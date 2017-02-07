/*********************************************************/ 
template <typename T>
Polinomio<T>::Polinomio(const T & t){
  vectorD<T> aux(t);
  monomios = aux;
  grado = 0;
}

/*********************************************************/ 
template <typename T>
Polinomio<T>::Polinomio(const Polinomio<T> & b){

  monomios = b.monomios;
  grado = b.grado;

}    	
/*********************************************************/ 
template <typename T>
Polinomio<T>::Polinomio(int g, const  T  & t){

  grado = g;

  vectorD<T> aux(g+1,t);
  monomios = aux;
}
/*********************************************************/ 
template <typename T>
Polinomio<T>::~Polinomio(){}
/*********************************************************/
template <typename T> 
int Polinomio<T>::gradoPolinomio() const{

  return monomios.size();
}
/*********************************************************/ 
template <typename T>
T  Polinomio<T>::coeficiente(int p) const{

  return monomios.at(p);
}
/*********************************************************/ 
template <typename T>
void Polinomio<T>::assign(int p, const  T  & t){

  monomios.assign(p,t);

}
/*********************************************************/ 
template <typename T>
Polinomio<T> & Polinomio<T>::operator= (const Polinomio<T> & x){

  if(this != &x){
    monomios = x.monomios;
    grado = x.grado;
  }

  return *this;
}

/*********************************************************/ 
template <typename T>
Polinomio<T> & Polinomio<T>::operator+ (const Polinomio<T> & x){

  Polinomio<T> aux(x);
  Polinomio<T>::iterator it1, it2;
  vectorD<T> resultado(grado+1, monomios.default_value());
  it1 = begin();
  it2 = aux.begin();
  int i = 0;

  if(x.grado == grado){

    while(it1 != end()){;
      resultado.assign(i, (*it1 + *it2));
      ++it1;
      ++it2;
      ++i;
    }

  }

  else if(x.grado < grado){

    while(it2 != aux.end()){
      resultado.assign(i, (*it1 + *it2));
      ++it1;
      ++it2;
      ++i;
    }

    while(it1 != end()){
      resultado.assign(i, *it1);
      ++it1;
      ++i;
    }
  }

  else if(x.grado > grado){

    vectorD<T> resultado(x.grado, x.monomios.default_value());

    while(it1 != end()){
      aux.monomios.assign(i, (*it1 + *it2));
      ++it1;
      ++it2;
      ++i;
    }
    resultado = aux.monomios;
  }

  monomios = resultado;

  return *this;

}
/*********************************************************/ 
template <typename T>
Polinomio<T> & Polinomio<T>::operator- (const Polinomio<T> & x){

  Polinomio<T> aux(x);
  Polinomio<T>::iterator it;
  int i=0;
  it = aux.begin();
  
  // Sumamos el opuesto
  for(it, i; i <= aux.grado; ++it, ++i){
    aux.monomios.assign(i, (-1)*(*it));
  }
  
  
  return (*this+aux);
}

/*********************************************************/ 
template <typename T>
typename Polinomio<T>::iterator Polinomio<T>::begin(){

  Polinomio<T>::iterator ite;

  ite.it = monomios.begin();

  return ite;
}
/*********************************************************/ 
template <typename T>
typename Polinomio<T>::iterator Polinomio<T>::end(){

  Polinomio<T>::iterator ite;

  ite.it = monomios.end();

  return ite;
}
/*********************************************************/ 
template <typename T>
typename Polinomio<T>::const_iterator Polinomio<T>::cbegin() const{

  Polinomio<T>::const_iterator ite;

  ite.it = monomios.cbegin();

  return ite;
}
/*********************************************************/ 
template <typename T>
typename Polinomio<T>::const_iterator Polinomio<T>::cend() const{

  Polinomio<T>::const_iterator ite;

  ite.it = monomios.cend();

  return ite;
}
/*********************************************************/ 
template <typename T>
Polinomio<T>::iterator::iterator() {}
/*********************************************************/
template <typename T>
Polinomio<T>::iterator::iterator(const iterator & d){

  it = d.it;
}
/*********************************************************/
template <typename T>
const  T  & Polinomio<T>::iterator::operator *( ) {

  return *it;
}
/*********************************************************/
template <typename T>
typename Polinomio<T>::iterator & Polinomio<T>::iterator::operator++( ){

  ++it;
  return (*this);
}
/*********************************************************/
template <typename T>
typename Polinomio<T>::iterator Polinomio<T>::iterator::operator++(int ) {

  iterator tmp(*this);
  it++;
  return tmp;
} 
/*********************************************************/
template <typename T>
bool Polinomio<T>::iterator::operator == (const iterator & d) {

  return (it == d.it);
}
/*********************************************************/
template <typename T>
bool Polinomio<T>::iterator::operator != (const iterator & d){

  return (it != d.it);
}
/*********************************************************/
template <typename T>
typename Polinomio<T>::iterator & Polinomio<T>::iterator::operator=(const iterator & d){

  it = d.it;
  return *this;
}
/*********************************************************/
template <typename T>
Polinomio<T>::const_iterator::const_iterator() {}
/*********************************************************/
template <typename T>
Polinomio<T>::const_iterator::const_iterator(const const_iterator & d) {

  it = d.it;
}
/*********************************************************/
template <typename T>
Polinomio<T>::const_iterator::const_iterator(const iterator & d) {

  it(d.it);
}
/*********************************************************/
template <typename T>
const  T  &  Polinomio<T>::const_iterator::operator *(  ) {

  return *it;
}
/*********************************************************/
template <typename T>
typename Polinomio<T>::const_iterator & Polinomio<T>::const_iterator::operator++( ) {

  ++it;
  return *this;
}
/*********************************************************/
template <typename T>
typename Polinomio<T>::const_iterator Polinomio<T>::const_iterator::operator++(int ) {

  const_iterator tmp(*this);
  ++it;
  return tmp;
}
/*********************************************************/
template <typename T>
bool Polinomio<T>::const_iterator::operator == (const const_iterator & d) {

  return (it == d.it);
}
/*********************************************************/
template <typename T>
bool Polinomio<T>::const_iterator::operator != (const const_iterator & d) {

  return (it != d.it);
}   