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
diccionario::diccionario(){ 

}

/*****************************************************************/

diccionario::diccionario (const diccionario & d){

	dic = d.dic;

}

/*****************************************************************/

pair<diccionario::entrada,bool> diccionario::find(const nombreM & s) const{ 

	pair <diccionario::entrada,bool> encontrado;

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

defM & diccionario::operator[](const nombreM & s) {

	
	pair <entrada,bool> encontrada = find(s);
	

	// Si no esta en el diccionario lo añadimos
	if(!(encontrada.second)){

		defM d;

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

const defM & diccionario::operator[](const nombreM & s) const{

	int i=0;
	bool found = false;

	while((i < size()) && !found){

		if(dic[i].first == s){

			found = true;
		}

		i++;
	}

	if(!found){

		cerr << "Error: const defM & diccionario::operator[](const nombreM & s) const; \n ====> " << s << " no se encuentra en el diccionario\n";
		exit(1);
	}

	else{

		return dic.at(i).second;
	}
}

/*****************************************************************/

bool diccionario::insert(const diccionario::entrada & e) {

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

diccionario & diccionario::operator= (const diccionario & org){ 

	if(this != &org){

		dic = org.dic;
	}

	return *this;

}

/*****************************************************************/

diccionario::size_type diccionario::size() const {

	return dic.size();

}

/*****************************************************************/

bool diccionario::empty() const{

	return dic.empty();
}
  
/*****************************************************************/

bool diccionario::cheq_rep() const {

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

bool diccionario::buscar_rep(const nombreM & s) const{

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

ostream &  operator << (ostream & sal, const diccionario & D){


	for(int i=0; i < D.size(); i++){

		sal << D.dic[i] << endl;
	}

	return sal;
  
}

/*****************************************************************/