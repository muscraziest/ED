#include <assert.h>
#include <map>

/*********************************************************/
template <typename T>
vectorD<T>::vectorD(const T & t){

  n_ele = 0;
  v_nulo = t;
}


/*********************************************************/  	
template <typename T>
vectorD<T>::vectorD (const vectorD<T> & b){

  vd = b.vd;
  n_ele = b.n_ele;
  v_nulo = b.v_nulo;
}    	


/*********************************************************/
template <typename T>
vectorD<T>::vectorD(int numcomp, const T & t){

  n_ele = numcomp;
  v_nulo = t;
}


/*********************************************************/
template <typename T>     	
vectorD<T>::~vectorD(){}


/*********************************************************/
template <typename T>
typename vectorD<T>::size_type vectorD<T>::size() const{

  return n_ele;
}

/*********************************************************/
template <typename T>
T  vectorD<T>::default_value( ) const{

  return v_nulo;
}

/*********************************************************/
template <typename T>
bool vectorD<T>::empty() const{

  return (n_ele == 0);
}

/*********************************************************/
template <typename T>
void vectorD<T>::assign(int p, const  T  & t){

  //Buscamos el elemento en la lista
  typename map<int,T>::iterator it;
  it = vd.find(t);
  bool found = (vd.find(t) != vd.end());

  //Si el valor nuevo es el valor nulo y está en la lista lo borramos
  if((t == v_nulo) && (found)){

      vd.erase(it);
  }

  //Si está en la lista pero el valor es distinto al valor nulo, lo cambiamos
  else if ((t != v_nulo) && (found)){

    (*it).second = t;
  }

  //Si el valor es distinto del valor nulo y no está en la lista, lo insertamos
  else if ((t != v_nulo) && (!found)){

    vd.insert(pair<int,T>(p,t));
  }

}

/********************************************************/
template <typename T>
void vectorD<T>::push_back(const  T  & t){

  //Si el valor no es nulo, lo añadimos a la lista
  if(t != v_nulo){

    pair <int,T> elemento;
    elemento.first = n_ele;
    elemento.second = t;

    vd.insert(elemento);
  }

  ++n_ele;
}

/*********************************************************/
template <typename T>
void vectorD<T>::pop_back(){

  //Comprobamos si el último elemento está en la lista
  typename vectorD<T>::stored_iterator it;
  it.ite = --vd.end();

  if((*it).first == n_ele-1)
    vd.erase(n_ele-1);

  --n_ele;
}

/*********************************************************/
template <typename T>
void vectorD<T>::clear(){

  vd.clear();
  n_ele = 0;
} 

/*********************************************************/
template <typename T>
void vectorD<T>::resize(int s){
 
  if((n_ele > s) && !(vd.empty())){

    typename map<int,T>::reverse_iterator it,aux;
    it = vd.rbegin();

    while((it!=vd.rend()) && (*it).first >= s){
      aux = it;
      ++it;
      vd.erase((*aux).first);
      
    }
  }
  n_ele = s;

} 

/*********************************************************/
template <typename T>
vectorD<T> & vectorD<T>::operator= (const vectorD<T> & x){

	if(this != &x){

		n_ele = x.n_ele;
		v_nulo = x.v_nulo;
		vd = x.vd;
	}

	return *this;
}

/*********************************************************/
template <typename T>
const  T  & vectorD<T>::operator[](int c) const  {

	typename vectorD<T>::const_stored_iterator it;
	it = csbegin();
	bool found = ((*it).first == c);

	//Buscamos si está en la lista
	while(!found && (it != csend()))
		++it;

	//Si está devolvemos su valor
	if(found)
		return (*it).second;

	//En caso contrario devolvemos el valor nulo
	else
		return v_nulo;

}

/*********************************************************/
template <typename T>
const  T  & vectorD<T>::at(int c) const  {

  assert((c <= n_ele) && (c >= 0));

  return (*this)[c];

}

/*********************************************************/
template <typename T>
bool vectorD<T>::operator==(const vectorD<T> & x){

  bool iguales;
  

  if((n_ele != x.n_ele) || (v_nulo != x.v_nulo))
    iguales = false;
  
  else{

    map<int,T> aux = x.vd;

    if(vd.size() != aux.size()){
      iguales = false;
    }

    else{
      typename vectorD<T>::stored_iterator it_1;
      typename map<int,T>::iterator it_2;
      it_1 = sbegin();
      it_2 = aux.begin();
      iguales = true;

      while(iguales && (it_1 != send()) && (it_2 != aux.end())){
        
        if(((*it_1).first != (*it_2).first) || ((*it_1).second != (*it_2).second))
          iguales = false;

        ++it_1;
        ++it_2;
      }
    }
  }

  return iguales;
}

/*********************************************************/
template <typename T>
bool vectorD<T>::operator!=( const vectorD & x){

  return !(*this == x);
}

/*********************************************************/
template <typename T>
typename vectorD<T>::iterator vectorD<T>::begin(){

  vectorD<T>::iterator it;

  it.i_vect = 0;
  it.ite_rep = vd.begin();
  it.el_vect = this;

  return it;
}

/*********************************************************/
template <typename T>
typename vectorD<T>::iterator vectorD<T>::end(){

  vectorD<T>::iterator it;

  it.i_vect = n_ele;
  it.ite_rep = vd.end();
  it.el_vect = this;

  return it;
}

/*********************************************************/
template <typename T>
typename vectorD<T>::const_iterator vectorD<T>::cbegin() const{

  vectorD<T>::iterator it;

  it.i_vect = 0;
  it.ite_rep = vd.cbegin();
  it.el_vect = this;

  return it;
}

/*********************************************************/
template <typename T>
typename vectorD<T>::const_iterator vectorD<T>::cend() const{

  vectorD<T>::iterator it;

  it.i_vect = n_ele;
  it.ite_rep = vd.cend();
  it.el_vect = this;

  return it;
}

/*********************************************************/
template <typename T>
typename vectorD<T>::stored_iterator vectorD<T>::sbegin(){

  vectorD<T>::stored_iterator it;

  it.ite = vd.begin();

  return it;
} 

/*********************************************************/
template <typename T>
typename vectorD<T>::stored_iterator vectorD<T>::send(){

  vectorD<T>::stored_iterator it;

  it.ite = vd.end();

  return it;
}

/*********************************************************/
template <typename T>
typename vectorD<T>::const_stored_iterator vectorD<T>::csbegin() const{

  vectorD<T>::const_stored_iterator it;

  it.ite = vd.begin();

  return it;
} 

/*********************************************************/
template <typename T>
typename vectorD<T>::const_stored_iterator vectorD<T>::csend() const{

  vectorD<T>::const_stored_iterator it;

  it.ite = vd.end();

  return it;
}

/*********************************************************/
template <typename T>
int vectorD<T>::checkRep(){

  if(vd.size() > n_ele)
    return 1;

  stored_iterator it;
  it = sbegin();
  bool encontrado = ((*it).second == v_nulo);

  while(it != send() && !encontrado)
    ++it;

  if(encontrado)
    return 2;

  bool correcto = ((*it).first >= 0);

  while(it != send() && correcto)
    ++it;

  if(!correcto)
    return 3;

  stored_iterator it1, it2;
  it1 = sbegin();
  it2 = it1++;
  correcto = ((*it1).first < (*it2).first);

  while(it2 != send() && correcto){
    ++it1;
    ++it2;
  }

  if(!correcto)
    return 4;

  return 0;

}

/*********************************************************/ 
template <typename T>
vectorD<T>::stored_iterator::stored_iterator() {} 

/*********************************************************/ 
template <typename T>
vectorD<T>::stored_iterator::stored_iterator(const vectorD<T>::stored_iterator & d) : ite(d.ite) {}

/*********************************************************/ 
template <typename T>
 pair<const int, const T > & vectorD<T>::stored_iterator::operator *() { 

  return (pair<const int, const T > &) *ite;
}

/*********************************************************/ 
template <typename T>
typename vectorD<T>::stored_iterator & vectorD<T>::stored_iterator::operator++( ) {
  ++ite; 
  return *this;
}  

/*********************************************************/ 
template <typename T>
typename vectorD<T>::stored_iterator vectorD<T>::stored_iterator::operator++(int) {
  stored_iterator tmp(*this);
  ++ite;
  return tmp;
}  

/*********************************************************/ 
template <typename T>
bool vectorD<T>::stored_iterator::operator == (const vectorD<T>::stored_iterator & d) {
  return ite == d.ite;
}

/*********************************************************/ 
template <typename T>
bool vectorD<T>::stored_iterator::operator != (const vectorD<T>::stored_iterator & d) {
  return ite != d.ite;
}
    
/*********************************************************/
template <typename T>
vectorD<T>::iterator::iterator() {

  i_vect = -1;
  el_vect = NULL;
}

/*********************************************************/
template <typename T>
vectorD<T>::iterator::iterator(const vectorD<T>::iterator & d){

  i_vect = d.i_vect;
  ite_rep = d.ite_rep;
  el_vect = d.el_vect;
}

/*********************************************************/
template <typename T>
const  T  & vectorD<T>::iterator::operator *() {

 
  if((*el_vect).vd.empty()){
    return (*el_vect).v_nulo;
  }
  else{
    if(i_vect == (*ite_rep).first)
      return (*ite_rep).second;
    else
      return (*el_vect).v_nulo;
  }
    
}

/*********************************************************/
template <typename T>
typename vectorD<T>::iterator & vectorD<T>::iterator::operator++(){

  if((!(*el_vect).vd.empty()) && (i_vect == (*ite_rep).first))
    ++ite_rep;

  ++i_vect;

  return *this;
}

/*********************************************************/
template <typename T>
typename vectorD<T>::iterator vectorD<T>::iterator::operator++(int) {

  vectorD<T>::iterator tmp(*this);
  
  if((!(*el_vect).vd.empty()) && (i_vect == (*ite_rep).first))
    ++ite_rep;

  ++i_vect;

  return tmp;
} 

/*********************************************************/
template <typename T>
bool vectorD<T>::iterator::operator == (const vectorD<T>::iterator & d) {

  return ((i_vect == d.i_vect) && (el_vect == d.el_vect));
}
/*********************************************************/
template <typename T>
bool vectorD<T>::iterator::operator != (const vectorD<T>::iterator & d){

  return !(*this == d);
}

/*********************************************************/
template <typename T>
typename vectorD<T>::iterator & vectorD<T>::iterator::operator=(const vectorD<T>::iterator & d){

  i_vect = d.i_vect;
  ite_rep = d.ite_rep;
  el_vect = d.el_vect;

  return *this;
}

/*********************************************************/
template <typename T> 
vectorD<T>::const_stored_iterator::const_stored_iterator(){}

/*********************************************************/
template <typename T> 
vectorD<T>::const_stored_iterator::const_stored_iterator(const vectorD<T>::const_stored_iterator & d) :ite(d.ite) {}

/*********************************************************/
template <typename T> 
vectorD<T>::const_stored_iterator::const_stored_iterator(const vectorD<T>::stored_iterator & d) {

  ite = d.ite;
}
/********************************************************/
template <typename T>
 pair<const int, const T> & vectorD<T>::const_stored_iterator::operator *( ) {

  return ( pair<const int, const T> &)(*ite);
}

/********************************************************/
template <typename T>
typename vectorD<T>::const_stored_iterator & vectorD<T>::const_stored_iterator::operator++( ) {

  ++ite;
  return *this;
} 

/********************************************************/
template <typename T>
typename vectorD<T>::const_stored_iterator vectorD<T>::const_stored_iterator::operator++(int ) {

  const_stored_iterator tmp(*this);
  ++ite;
  return tmp;
}

/********************************************************/
template <typename T>
bool vectorD<T>::const_stored_iterator::operator == (const vectorD<T>::const_stored_iterator & d) {

  return (ite == d.ite);
}

/********************************************************/
template <typename T>
bool vectorD<T>::const_stored_iterator::operator != (const vectorD<T>::const_stored_iterator & d) {

  return (ite != d.ite);
}
/********************************************************/
template <typename T>
typename vectorD<T>::const_stored_iterator & vectorD<T>::const_stored_iterator::operator= (const vectorD<T>::const_stored_iterator & d) {

  ite = d.ite;
  return *this;
}

/*********************************************************/
template <typename T>
vectorD<T>::const_iterator::const_iterator() {

  i_vect = -1;
  el_vect = NULL;
}

/*********************************************************/
template <typename T>
vectorD<T>::const_iterator::const_iterator(const vectorD<T>::const_iterator & d) {

  i_vect = d.i_vect;
  ite_rep = d.ite_rep;
  el_vect = d.el_vect;
}

/*********************************************************/
template <typename T>
vectorD<T>::const_iterator::const_iterator(const vectorD<T>::iterator & d) {

  i_vect = d.i_vect;
  ite_rep = d.ite_rep;
  el_vect = d.el_vect;
}

/*********************************************************/
template <typename T>
const  T  &  vectorD<T>::const_iterator::operator *() {

  if((*el_vect).vd.empty()){
    return (*el_vect).v_nulo;
  }
  else{
    if(i_vect == (*ite_rep).first)
      return (*ite_rep).second;
    else
      return (*el_vect).v_nulo;
  }
}

/*********************************************************/
template <typename T>
typename vectorD<T>::const_iterator & vectorD<T>::const_iterator::operator++() {

  if((!(*el_vect).vd.empty()) && (i_vect == (*ite_rep).first))
    ++ite_rep;

  ++i_vect;

  return *this;
}

/*********************************************************/
template <typename T>
typename vectorD<T>::const_iterator vectorD<T>::const_iterator::operator++(int) {

  vectorD<T>::const_iterator tmp(*this);
  
  if((!(*el_vect).vd.empty()) && (i_vect == (*ite_rep).first))
    ++ite_rep;

  ++i_vect;

  return tmp;
}

/*********************************************************/
template <typename T>
bool vectorD<T>::const_iterator::operator == (const vectorD<T>::const_iterator & d) {

  return((i_vect == d.i_vect) && (el_vect == d.el_vect));
}

/*********************************************************/
template <typename T>
bool vectorD<T>::const_iterator::operator != (const vectorD<T>::const_iterator & d) {

  return !(*this == d);
}