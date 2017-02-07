#include "gs1Set.h"
#include <string>

gs1Set::gs1Set (){
  pair<string,int> aux("gs1",0);
  arbol = tree<pair<string,int>>(aux);
  tama = 0;
}

gs1Set::gs1Set (const gs1Set  & x){
  arbol = x.arbol;
  tama = x.tama;
}


void gs1Set::reading_gs1Set () {

  tree<pair<string,int> >::node n, h;
  queue< tree<pair<string,int> >::node > Q;
  int contador;
   
  pair<string,int> aux;

  n = arbol.root();
  Q.push(n);
  while (!Q.empty()){
    n = Q.front(); //Pasa al siguiente nivel
    Q.pop();
    contador = 0;
    cout << "Hijo Izq de " << (*n).first << "/ si no tiene hijos "<< endl;
    cin >> aux.first;
    if (aux.first != "/") { 
      if(aux.first[0] == '(')
         aux.second = -1;
      else
        aux.second = 1;
      h= arbol.insert_left(n,aux);
      Q.push(h);
    }
    else
      contador++; //Incrementamos el contador si introduce '/'
    cout << "Hermano Dhc de " << (*h).first<< "/ si no tiene hermano"<< endl;
    cin >> aux.first;
    while (aux.first != "/"){
      contador = 0; //Ponemos el contador a 0, ya que no introdujo '/'
        if(aux.first[0] == '(')
          aux.second = -1;
        else
          aux.second = 1;
        h = arbol.insert_right_sibling(h,aux);
        Q.push(h);
        cout << "Hermano Dhc de " << (*h).first<< "/ si no tiene hermano"<< endl;
        cin >> aux.first;
    }
    contador++; //Incrementamos el contador si introduce '/'

    //Si se escriben dos seguidos '/' es que ni tiene hermanos ni tiene hijos
    if(contador == 2){
      while(!Q.empty())
        Q.pop();
    }
  }
}


gs1Set & gs1Set::operator = (const gs1Set & org){

  if(this != &org){
    arbol = org.arbol;
    tama = org.tama;
  }

  return *this;
}

string gs1Set::find_sub(string::const_iterator it) {

   string code;

   if(*it == '('){
      for(it; *it != ')'; it++){
         code.push_back(*it);
      }
      code.push_back(')');
   } 

   else
      code = "";

   return code;
}

pair<string, int> gs1Set::siguiente_dato(string::const_iterator & it) {

  pair<string, int> dato;

  if(*it == '(') {
    dato.first = find_sub(it);
    dato.second = -1;
    it += 4;
  }
  else {
    dato.first = *it;
    dato.second = 0;
    it++;
  }

  return dato;
}

void gs1Set ::incrementa_subcodigos(tree<pair<string,int>>::node n, int codigos) {
  tree<pair<string,int>>::node root;
  root = arbol.root();

  while(n != root) {
    if((*n).second >= 0) {
      //Si no es un IA, decremento
      (*n).second += codigos;
    }
    n = n.parent();
  }
}

bool gs1Set ::insert(const string& s){ 

   tree<pair<string,int> >::node n, aux, siguiente, root;
   string::const_iterator it(s.begin());
   bool enc, insertado;
   pair<string,int> dato;
   
   n = arbol.root();
   insertado = false;

    while(it != s.end()){

      aux = n.left(); // aux es el primer hijo del nodo raiz actual
      enc = false;
      dato = siguiente_dato(it); //guardamos los datos del siguiente nodo
 
      //Si el árbol está vacío o el nodo va antes que el actual
      if(aux.null() || (*aux).first > dato.first) {
        n = arbol.insert_left(n, dato);
        insertado = true;
      }
      //Si no está vacío
      else {
        while(!enc) {

          if(dato.first == (*aux).first) {
            //El nodo ya existe
            n = aux;
            enc = true;
          }
          else {
            siguiente = aux.next_sibling();
            if(siguiente.null() || dato.first < (*siguiente).first) {
              //Fin del árbol o el siguiente es mayor
              n = arbol.insert_right_sibling(aux, dato);
              insertado = true;
              enc = true;
            }
            else {
              //Continúo buscando
              aux = siguiente;
            }
          }//else
        }//while
      }//else
    }//while
      
  tama++;
  incrementa_subcodigos(n, 1);

  return insertado; //
}

int gs1Set::erase(const string & s){

   tree<pair<string,int> >::node n, aux, prec;
   tree<pair<string,int> > rama;
   gs1Set::const_iterator it = find(s);

   if(it != end()) {
      aux = it.act;
      if((*aux).second < 0) {
        // Se trata de un IA, busco el siguiente final del código
        while((*aux).second < 0 && !arbol.is_root(aux.parent())) {
          aux = aux.parent();
        }
      }

      int nCodigosBorrados = (*aux).second;
      
      //recorro el árbol hasta encontrar el último nodo donde haya una bifurcación
      while(!arbol.is_root(aux) ) {
        prec = aux.parent();
        if((*prec).second > nCodigosBorrados || arbol.is_root(prec))
          break;
        aux = prec;
      }

      n = aux.parent();

      //Podo el árbol
      if(n.left() == aux) {
        arbol.prune_left(n, rama); 
      }

      else{
        prec = n.left();
        while(prec.next_sibling() != aux){
          prec = prec.next_sibling();
        }
        prec.next_sibling();
        arbol.prune_right_sibling(prec, rama);
      }

      //Descuento los subcodigos
      incrementa_subcodigos(n, -nCodigosBorrados);
      return nCodigosBorrados;
   }
   return 0;
}

gs1Set::const_iterator gs1Set::find(const string & s){

  tree<pair<string,int> >::node n, aux, ant;
  string::const_iterator it_s(s.begin());
  gs1Set::const_iterator it;
  bool enc = true;
  bool coincide = false;
  pair<string,int> dato;

  n = arbol.root();
  aux = n.left(); // aux es el primer hijo
  ant = aux;
  
  while(it_s != s.end() && enc){

      dato = siguiente_dato(it_s);

      while(!aux.null() && !coincide){
         if(dato.first == (*aux).first){
            n = aux; //Pasamos al siguiente nivel
            coincide = true;
         }
         else{
            ant = aux;
            aux = aux.next_sibling();
            if(!aux.null()) 
               ant = aux;
         }
      }

      if (!coincide) 
         enc = false;
      else{
         ant = aux;
         aux = n.left();
         coincide = false;
      }
   }

   if(enc){
      it.act = ant;
      it.ptr = this;
   }
   else
      it = end();
   
  return it;
}

list<string> gs1Set::codesWithPrefix(const string & pr){

   list<string> salida;
   tree<pair<string,int> >::node n, aux, sig, raiz_codigo, sig_sub;
   string codigo, c_comun;
   
   bool enc = false;
   n = arbol.root();
   aux = n.left(); // aux es el primer hijo
  
  //Buscamos el subcódigo
  while(!aux.null() && !enc){
      if(pr==(*aux).first)
         enc = true;
      else
        aux = aux.next_sibling();
   } 

   //Si está, buscamos los códigos
   if(enc){
      sig = aux.next_sibling();
      raiz_codigo = aux;
      tree<pair<string,int> >::const_preorderiterator it(raiz_codigo);

      c_comun=pr;

      //Si aux no tiene hermanos, los códigos comparten ese dígito
      while(!aux.next_sibling().null()){
        aux = aux.left(); //bajamos un nivel
        c_comun+=(*aux).first;
      }

      sig_sub = aux.left();

      //Recorremos solo una rama, la que tiene como raíz el nodo del código
      while((*it) != (*sig_sub)){
         //aux pasa a ser el siguiente hermano del hijo del subárbol a recorrer mientras tenga hermanos
         if(!aux.next_sibling().null())
          aux = aux.next_sibling();
         if(!sig_sub.next_sibling().null())
          sig_sub = sig_sub.next_sibling();

         //Recorremos hasta el final de ese código
         for(it; (*it) != (*sig_sub); ++it){
            codigo+=(*it).first;
          }

         //Insertamos el código en la lista
         salida.push_back(codigo);

         //Nos aseguramos de que el "codigo común" permanece
         codigo=c_comun;
      }

      //Metemos el último código de la rama
      codigo = c_comun;

      for(it; (*it) != (*sig); ++it)
        codigo+=(*it).first;
      salida.push_back(codigo);
   }
 
   return salida;
}

gs1Set::size_type gs1Set::size() const{
  return tama;
}

bool gs1Set::empty() const{
  return arbol.empty();
}

void gs1Set::print() const {
  tree<pair<string,int> >::const_preorderiterator it;
  tree<pair<string,int> >::const_leveliterator itn;

  cout << "preorden " << endl; 
  for (it= arbol.beginPreorder(); it!= arbol.endPreorder();++it)
    cout << (*it).first << endl;

  cout << "Nivel " << endl;
  for (itn= arbol.beginlevel(); itn!= arbol.endlevel();++itn)
    cout << (*itn).first << endl;
  
}

void gs1Set::clear(){

  arbol.clear();
  tama = 0;

  pair<string,int> aux("gs1",0);
  arbol = tree<pair<string,int>>(aux);
}

gs1Set::const_iterator gs1Set::begin() const{

  gs1Set::const_iterator it;

  it.act = arbol.root();
  it.ptr = this;

  return it;
}
   

gs1Set::const_iterator gs1Set::end() const{

  gs1Set::const_iterator it;
  tree<pair<string,int> >::node n;
  
  it.act = arbol.root();
  it.ptr = this;

  return it;
}

gs1Set::const_iterator::const_iterator(){

  ptr = NULL;
}

gs1Set::const_iterator::const_iterator(const gs1Set::const_iterator & it){

  act = it.act;
  ptr = it.ptr;
}

string gs1Set::const_iterator::operator*(){

  //list<string> codes;
  string salida;
  tree<pair<string, int> >::node aux, n;
  
  n = (*ptr).arbol.root();
  if(act == n)
    return "";
  
  aux = act;

  while(aux != n){
    salida = (*aux).first + salida;
    aux = aux.parent();
  }
  return salida;
}

gs1Set::const_iterator & gs1Set::const_iterator::operator++(){

  while((*act).second < 0){

    act = act.left();
  }

  return *this;
}

gs1Set::const_iterator gs1Set::const_iterator::operator++(int){

  gs1Set::const_iterator aux(*this);

  while((*act).second < 0){

    act = act.left();
  }

  return aux;
}

gs1Set::const_iterator & gs1Set::const_iterator::upper_IA(){

  while((*act).second > 0){

    act = act.parent();
  }

  return *this;
}  

gs1Set::const_iterator & gs1Set::const_iterator::operator=(const const_iterator & it){

  if(this != &it){

    act = it.act;
    ptr = it.ptr;
  }

  return *this;
}

bool gs1Set::const_iterator::operator==(const const_iterator & it) const{

  return ((act == it.act) && (ptr == it.ptr));
}

bool gs1Set::const_iterator::operator!=(const const_iterator & it) const{

  return !(*this == it);
}

bool gs1Set::cheq_rep(){

  tree<pair<string,int> >::preorderiterator it(arbol.root());
  ++it;
  for(it; it!= arbol.endPreorder();++it){
      if((((*it).first.at(0) == '(') && ((*it).second > 0)) || (((*it).first.at(0) != '(') && ((*it).second) < 0))
         return false;
  }
  return true;
}