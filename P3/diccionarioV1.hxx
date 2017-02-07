/* 
 * diccionario.h
 * 
 * Copyright  (C) Juan F. Huete, Maria del Mar García Cabello, Laura Tirado Lopez.
 * 
 * diccionario:: diccionario, end, find, operator[], size, max_element
 * tipos diccionario::entrada, diccionario::size_type
 * 
 *
//! Clase diccionario (Version V1)
 /*! diccionario:: diccionario, find, operator[], size,insert,operator= ,operator <<,buscar_rep,cheq_rep,empty

 * Tipos diccionario::entrada, diccionario::size_type

 * Descripción:

* Nuestro diccionario es un vector de pares. El primer campo de la entrada, first, es un meteorito, y el segundo, second, es la deficnicion de un meteorito (class defM).

*La diferencia de las dos versiones es que la primera (diccionarioV1.hxx) no tiene el vector de meteoritos ordenado.

*Tenemos dos funciones que se encargan de chequear que los meteoritos del diccionario tengan unos ciertos criterios: el primero de ellos es que todos tengan nombre y el segundo es que no haya meteoritos repetidos, para ello usamos la funcion cheq_rep, la cual usa la funcion buscar_rep para facilitar la lectura del codigo.

* El número de elementos en el diccionario puede variar dinámicamente; la gestión de la memoria es automática.

*En esta primera version de diccionario.h no tenemos el vector de meteoritos ordenado.
*/
#include <assert.h>
#include <cstdlib>

/**
 Como usa un contenedor de la STL, se llama por defecto al constructor de la clase vector
*/
template <typename T, typename D> diccionario<T,D>::diccionario(){ 

}

/*****************************************************************/

template <typename T, typename D> 
diccionario<T,D>::diccionario (const diccionario <T,D> & d){

	dic = d.dic;

}

/*****************************************************************/

template <typename T, typename D> 
pair<typename diccionario <T,D>::entrada,bool> diccionario<T,D>::find(const T & s) const{ 

	pair<diccionario<T,D>::entrada,bool> encontrado;

	encontrado.second = false;
	int i=0;

	while((i < size()) && !(encontrado.second)){

		if(dic[i].first == s){

			encontrado.first = dic[i];
			encontrado.second = true;
		}

		i++;
	}

	return encontrado;

}

/*****************************************************************/

template <typename T, typename D> 
D & diccionario<T,D>::operator[](const T & s) {

	
	pair <diccionario<T,D>::entrada,bool> encontrada = find(s);
	

	// Si no esta en el diccionario lo añadimos
	if(!(encontrada.second)){

		D d;

		encontrada.first.first = s;
		encontrada.first.second = d;
		dic.push_back(encontrada.first);
		return dic.back().second;
   		
	}

	else{

		int i=0;

		while((i < size()) && (dic.at(i).first != s)){
			i++;
		}

		return dic[i].second;
	}
}
	
/*****************************************************************/

template <typename T, typename D> 
const D & diccionario<T,D>::operator[](const T & s) const{

	int i=0;
	bool found = false;

	while((i < size()) && !found){

		if(dic[i].first == s){

			found = true;
		}

		i++;
	}

	if(!found){

		cerr << "Error: const defM & diccionario<T,D>::operator[](const nombreM & s) const; \n ====> " << s << " no se encuentra en el diccionario\n";
		exit(1);
	}

	else{

		return dic.at(i).second;
	}
}

/*****************************************************************/

template <typename T, typename D> 
bool diccionario<T,D>::insert(const diccionario<T,D>::entrada & e) {

	if(dic.size() == 0){

		dic.push_back(e);
	}

	else{
		
		if(!(find(e.first).second) && (e.first != "")){

			dic.push_back(e);
		}

	}

	return !(find(e.first).second);

}

/*****************************************************************/

template <typename T, typename D> 
diccionario<T,D> & diccionario<T,D>::operator= (const diccionario <T,D> & org){ 

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
	int i = 0;

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

	int contador_rep = 0;
	bool repetido = (contador_rep > 1);
	int i = 0;


	while((i < size()) && !repetido){

		if(dic[i].first == s){

			contador_rep++;
		}

		i++;
	}

	return repetido;
}

/*****************************************************************/

template <typename T, typename D>
ostream &  operator << (ostream & sal, const diccionario <T,D> & Di){


	for(int i=0; i < Di.size(); i++){

		sal << Di.dic[i] << endl;
	}

	return sal;
  
}

/*****************************************************************/