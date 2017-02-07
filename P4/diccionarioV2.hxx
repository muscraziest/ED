/* 
 * diccionario.h
 *
 * Copyright  (C) Juan F. Huete, María del Mar García Cabello, Laura Tirado Lopez.
 *
 * diccionario<T,D>:: diccionario, end, find, operator[], size, max_element
 * tipos diccionario<T,D>::entrada, diccionario<T,D>::size_type
 *
 *
*/

//! Clase diccionario (Version V2)
 /*! diccionario<T,D>:: diccionario, find, operator[], size,insert,operator= ,operator <<,buscar_rep,cheq_rep,empty

 * Tipos diccionario<T,D>::entrada, diccionario<T,D>::size_type

 * Descripción

* Nuestro diccionario es un vector de pares. El primer campo de la entrada, first, es un meteorito, y el segundo, second, es la deficnicion de un meteorito (class D).

*La diferencia de las dos versiones es que la primera (diccionarioV1.hxx) no tiene el vector de meteoritos ordenado. Esta version (diccionarioV2.hxx) tiene el vector de elementos ordenados.
*Tenemos dos funciones que se encargan de chequear que los meteoritos del diccionario tengan unos ciertos criterios: el primero de ellos es que todos tengan nombre y el segundo es que no haya meteoritos repetidos, para ello usamos la funcion cheq_rep, la cual usa la funcion buscar_rep para facilitar la lectura del codigo.

* El número de elementos en el diccionario puede variar dinámicamente; la gestión de la memoria es automática.
*/

#include <cstdlib>
#include <assert.h>

/**
 Como usa un contenedor de la STL, se llama por defecto al constructor de la clase vector
*/
template <typename T, typename D>
diccionario<T,D>::diccionario(){ 

}

/*****************************************************************/

template <typename T, typename D>
diccionario<T,D>::diccionario (const diccionario<T,D> & d){

	dic = d.dic;

}

/*****************************************************************/
template <typename T, typename D>
typename diccionario<T,D>::iterator diccionario<T,D>::begin(){

	diccionario<T,D>::iterator it_d(dic.begin());  //Estamos usando el begin del iterador del vector
	
	return it_d;
} 

/*****************************************************************/
template <typename T, typename D>
typename diccionario<T,D>::iterator diccionario<T,D>::end(){

	diccionario<T,D>::iterator it_d(dic.end());  //Estamos usando el end del iterador del vector

	return it_d;
}
	
/*****************************************************************/
template <typename T, typename D>
typename diccionario<T,D>::const_iterator diccionario<T,D>::cbegin() const{

	diccionario<T,D>::iterator it_d(dic.cbegin());  //Estamos usando el cbegin del iterador del vector
	
	return it_d;
}

/*****************************************************************/
template <typename T, typename D>
typename diccionario<T,D>::const_iterator diccionario<T,D>::cend() const{

	diccionario<T,D>::iterator it_d(dic.cend()); //Estamos usando el cend del iterador del vector
	
	return it_d;
}

/*****************************************************************/
template <typename T, typename D>
diccionario<T,D>::iterator::iterator(){

	it_v = NULL;	

} 

/*****************************************************************/
template <typename T, typename D>
diccionario<T,D>::iterator::iterator(const diccionario<T,D>::iterator & it){
	
	it_v = it.it_v; 
	
} 

/*****************************************************************/
template <typename T, typename D>
typename diccionario<T,D>::value_type & diccionario<T,D>::iterator::operator* () const{

	return *it_v;
	
} 

/*****************************************************************/
template <typename T, typename D>
typename diccionario<T,D>::iterator diccionario<T,D>::iterator::operator++ (int n){

	diccionario<T,D>::iterator sal(*this);

	++(*this);

	return sal;
	
} 

/*****************************************************************/
template <typename T, typename D>
typename diccionario<T,D>::iterator & diccionario<T,D>::iterator::operator++(){
	
	this.it_v++;

	return (*this);
	
} 

/*****************************************************************/
template <typename T, typename D>
bool diccionario<T,D>::iterator::operator==(const diccionario<T,D>::iterator & it) const{
	
	return (it_v == it.it_v);
	
} 

/*****************************************************************/
template <typename T, typename D>
bool diccionario<T,D>::iterator::operator !=(const diccionario<T,D>::iterator & it) const{

	return !(this == it);
	
} 

/*****************************************************************/
template <typename T, typename D>
diccionario<T,D>::iterator::iterator(typename diccionario<T,D>::entrada *p){

	this.it_v = (pair<const T,D> *) p;
}

/*****************************************************************/
template <typename T, typename D>
diccionario<T,D>::iterator::iterator(typename vector<diccionario<T,D>::entrada>::iterator it){

	it_v=(pair<const T,D> *)&(*(it));
	
}

/*****************************************************************/
template <typename T, typename D>
diccionario<T,D>::const_iterator::const_iterator(){
	
	this.it_v = NULL;
} 

/*******************************************************************/

template <typename T, typename D>
diccionario<T,D>::const_iterator::const_iterator(const typename diccionario<T,D>::const_iterator & it){

	this.it_v = it.it_v;

}

/*****************************************************************/
template <typename T, typename D>
diccionario<T,D>::const_iterator::const_iterator (typename diccionario<T,D>::entrada * p){

	this.it_v = (pair<const T,D> *)p;
}

/*****************************************************************/
template <typename T, typename D>
diccionario<T,D>::const_iterator::const_iterator (typename vector<diccionario<T,D>::entrada>::const_iterator it){

	this.it_v=(pair<const T,D> *)&(*(it));
}

/*****************************************************************/
template <typename T, typename D>
const typename diccionario<T,D>::value_type & diccionario<T,D>::const_iterator::operator* () const{

	return *it_v;
	
} 

/*****************************************************************/
template <typename T, typename D>
typename diccionario<T,D>::const_iterator diccionario<T,D>::const_iterator::operator++ (int n){

	diccionario<T,D>::const_iterator sal(*this);

	++(*this);

	return sal;
	
} 

/*****************************************************************/
template <typename T, typename D>
typename diccionario<T,D>::const_iterator & diccionario<T,D>::const_iterator::operator++(){
	
	it_v++;

	return (*this);
	
} 

/*****************************************************************/
template <typename T, typename D>
bool diccionario<T,D>::const_iterator::operator==(const diccionario<T,D>::const_iterator & it)const{
	
	return (this.it_v == it.it_v);
	
} 

/*****************************************************************/
template <typename T, typename D>
bool diccionario<T,D>::const_iterator::operator !=(const diccionario<T,D>::const_iterator & it)const{
	
	return !(this == it);
	
} 


/*****************************************************************/

template <typename T, typename D>
typename diccionario<T,D>::iterator diccionario<T,D>::find(const T & s) const{ 
	
	bool found = false;
	int i=0;
	int tope = dic.size()-1;
	int centro;

   	while((!found) && (i <= tope)){

   		centro = (tope+i)/2;
     	if(dic[centro].first == s){

     		i=centro;
     		found = true;
     	}

      	else{ 

      		if(dic[centro].first < s){
	 			i = centro + 1;
	 		}	 		

	 		else {
       			tope = centro - 1;
       		}
       	}	

   	}

   	if(!found){

   			diccionario<T,D>::iterator sal;
   			sal.it_v= (pair<const T,D> *) (&dic[0]+dic.size());
   			return sal;
   	}

   	else{

   			diccionario<T,D>::iterator sal;
   			sal.it_v=(pair<const T,D> *) (&dic[0]+i);
   			return sal;
   	}

}

/*****************************************************************/

template <typename T, typename D>
D & diccionario<T,D>::operator[](const T & s) {

	diccionario<T,D>::iterator it;

	it = find(s);	

	// Si no esta en el diccionario lo añadimos
	if(it == end()){

		diccionario<T,D>::entrada e;
		D def;

		e.first = s;
		e.second = def;
		insert(e);
		
		it = find(e.first);
   		
	}

	return (*it).second;


}
	
/*****************************************************************/

template <typename T, typename D>
const D & diccionario<T,D>::operator[](const T & s) const{

	diccionario<T,D>::const_iterator it;

	it = find(s);	

	// Si no esta en el diccionario lo añadimos
	if(it == end()){

		cerr << "Error: const D & diccionario<T,D>::operator[](const T & s) const; \n ====> " << s << " no se encuentra en el diccionario\n";
		exit(1);		
	}

	return (*it).second;
}

/*****************************************************************/

template <typename T, typename D>
bool diccionario<T,D>::insert(const diccionario<T,D>::entrada & e) {

	bool correcto;

	if(dic.size() == 0){

		dic.push_back(e);

		correcto = true;
	}

	else{
		
		if(find(e.first) == end()){

			bool found = false;
			int i=0;
			int tope = dic.size()-1;
			int centro;

   			while((!found) && (i <= tope)){

   				centro = (tope+i)/2;

     				if(dic[centro].first == e.first){

     					i=centro;
     					found = true;
     				}

      				else{ 

      					if(dic[centro].first < e.first){

	 					i = centro + 1;
	 				}	 		

	 				else {

       						tope = centro - 1;
       					}
       				}	

   			}//WHILE

			dic.insert(dic.begin()+i,e);  //llamamos al insert del vector, no del diccionario
			correcto = true;
		}//IF

		else
			correcto = false;
	}//ELSE

	return correcto;
}

/*****************************************************************/

template <typename T, typename D>
diccionario<T,D> & diccionario<T,D>::operator= (const diccionario<T,D> & org){ 

	if(this != &org){

		dic = org.dic;
	}

	return *this;

}

/*****************************************************************/

template <typename T, typename D>
typename diccionario<T,D>::size_type diccionario<T,D>::size() const {

	return dic.size();

}

/*****************************************************************/

template <typename T, typename D>
bool diccionario<T,D>::empty() const{

	return dic.empty();
}
  
/*****************************************************************/

template <typename T, typename D>
bool diccionario<T,D>::cheq_rep() const {

	bool correcto = true;
	int i=0;

	while((i < size()) && correcto){

		if((dic[i].first == "") || (buscar_rep(dic[i].first))){

			correcto = false;
		}

		i++;
	}

	return correcto;

}
  
/*****************************************************************/

template <typename T, typename D>
bool diccionario<T,D>::buscar_rep(const T & s) const{

	bool repetido = false;
	int i = 0;
	int j = i+1;


	while((i < size()) && !repetido){

		if(dic[i].first == dic[j].first){

			repetido = true;
		}

		//Como estan ordenados, si pasa a ser mayor que el siguiente se sale del bucle
		else if(dic[i].first > dic[j].first){

			i = size()-1;
		}

		i++;
	}

	return repetido;
}

/*****************************************************************/

template <typename T, typename D>
ostream &  operator << (ostream & sal, const diccionario<T,D> & Di){

	typename diccionario<T,D>::const_iterator it;

	for(it = Di.cbegin(); it != Di.cend(); ++it){

		sal << (*it).first << (*it).second << endl;
	}

	return sal;
  
}

/*****************************************************************/
