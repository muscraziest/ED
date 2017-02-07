/* 
 * diccionario.h
 * 
 * Copyright  (C) Juan F. Huete
 * 
 * diccionario:: diccionario, end, find, operator[], size, max_element
 * tipos diccionario::entrada, diccionario::size_type
 * 
 *
===================================================================================
Funcion de Abstraccion:
  @todo incluir funcion de abstracción 
=====================================================================================
Invariante de la Representación:

  @todo incluir invariante dela representación 
=====================================================================================
*/
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

pair<diccionario::entrada,bool> & diccionario::find( const defM & s) const{


}

/*****************************************************************/

defM & diccionario::operator[](const nombreM & s) {

}
	
/*****************************************************************/

const defM & diccionario::operator[](const nombreM & s) const{

}

/*****************************************************************/

bool diccionario::insert(const diccionario::entrada & e) const{

}

/*****************************************************************/

diccionario & diccionario::operator=( const diccionario & org){

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

bool diccionario::cheq_rep( ) const {

}
  
/*****************************************************************/

ostream &  operator << ( ostream & sal, const diccionario & D){
  
}

/*****************************************************************/