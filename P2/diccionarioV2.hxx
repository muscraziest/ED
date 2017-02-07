/* 
 * diccionario.h
 *
 * Copyright  (C) Juan F. Huete, María del Mar García Cabello, Laura Tirado Lopez.
 *
 * diccionario:: diccionario, end, find, operator[], size, max_element
 * tipos diccionario::entrada, diccionario::size_type
 *
 *
*/

//! Clase diccionario (Version V2)
 /*! diccionario:: diccionario, find, operator[], size,insert,operator= ,operator <<,buscar_rep,cheq_rep,empty

 * Tipos diccionario::entrada, diccionario::size_type

 * Descripción

* Nuestro diccionario es un vector de pares. El primer campo de la entrada, first, es un meteorito, y el segundo, second, es la deficnicion de un meteorito (class defM).

*La diferencia de las dos versiones es que la primera (diccionarioV1.hxx) no tiene el vector de meteoritos ordenado. Esta version (diccionarioV2.hxx) tiene el vector de elementos ordenados.
*Tenemos dos funciones que se encargan de chequear que los meteoritos del diccionario tengan unos ciertos criterios: el primero de ellos es que todos tengan nombre y el segundo es que no haya meteoritos repetidos, para ello usamos la funcion cheq_rep, la cual usa la funcion buscar_rep para facilitar la lectura del codigo.

* El número de elementos en el diccionario puede variar dinámicamente; la gestión de la memoria es automática.
*/

#include <cstdlib>
#include <assert.h>

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

pair <diccionario::entrada,bool> diccionario::find(const nombreM & s) const{ 

	pair <entrada,bool> encontrado;

	bool found = false;
	int i=0;
	int tope = dic.size()-1;
	int centro;

   	while((!found) && (i <= tope)){

   		centro = (tope+i)/2;

     	if(dic[centro].first.compare(s) == 0){

     		encontrado.first = dic[centro];
     		found = true;
     	}

      	else{ 

      		if(dic[centro].first.compare(s) < 0){

	 			i = centro + 1;
	 		}	 		

	 		else {

       			tope = centro - 1;
       		}
       	}	

   	}

	if(!found){

		defM def_vacia;
		encontrado.first.second = def_vacia;
		encontrado.second = false;
	}

	else{

		encontrado.second = true;
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
		int tope = dic.size()-1;
		int centro;
		bool found = (dic.at(i).first == s);

   		while(!found && (i <= tope)){

   			centro = (tope+i)/2;

     		if(dic[centro].first.compare(s) == 0){

     			found = true;
     		}

      		else{ 

      			if(dic[centro].first.compare(s) < 0){

	 				i = centro + 1;
	 			}

	 			else {

       				tope = centro - 1;
       			}
       		}	

   		}

		return dic[i].second;
	}

}
	
/*****************************************************************/

const defM & diccionario::operator[](const nombreM & s) const{

	bool found = false;
	int i=0;
	int tope = dic.size()-1;
	int centro;

   	while((!found) && (i <= tope)){

   		centro = (tope+i)/2;

     	if(dic[centro].first.compare(s) == 0){

     		found = true;
     	}

      	else{ 

      		if(dic[centro].first.compare(s) < 0){

	 			i = centro + 1;
	 		}	 		

	 		else {

       			tope = centro - 1;
       		}
       	}	

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

	bool correcto;

	if(dic.size() == 0){

		dic.push_back(e);

		correcto = true;
	}

	else{

		bool found = false;
		int i=0;
		int tope = dic.size()-1;
		int centro;

   		while((!found) && (i <= tope)){

   			centro = (tope+i)/2;

     		if(dic[centro].first.compare(e.first) == 0){

     			found = true;
     		}

      		else{ 

      			if(dic[centro].first.compare(e.first) < 0){

	 				i = centro + 1;
	 			}	 		

	 			else {

       				tope = centro - 1;
       			}
       		}	

   		}

		if(!found && (e.first != "")){

			dic.insert(dic.begin()+i, e);

			correcto = true;

		}

		else{

			correcto = false;
		}
	}

	return correcto;

}

/*****************************************************************/

diccionario & diccionario::operator= (const diccionario & org){ 

	if(this != &org){

		dic = org.dic;
	}

	return *this;

}

/*****************************************************************/

typename diccionario::size_type diccionario::size() const {

	return dic.size();

}

/*****************************************************************/

bool diccionario<T,D>::empty() const{

	return dic.empty();
}
  
/*****************************************************************/

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

bool diccionario<T,D>::buscar_rep(const nombreM & s) const{

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

ostream &  operator << (ostream & sal, const diccionario<T,D> & Di){

	for(int i=0; i < Di.size(); i++){

		sal << Di.dic[i] << endl;
	}

	return sal;
  
}

/*****************************************************************/