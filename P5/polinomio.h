/* 
 * Polinomio.h
 * 
 * Copyright  (C) María del Mar García Cabello, Laura Tirado Lopez.
*/


#ifndef __POLINOMIO_H
#define __POLINOMIO_H

#include "vectorDlistas.h"

using namespace std;

//! Clase Polinomio
 /*! Polinomio:: Polinomio, grado, coeficiente, assing, operator=, 
     operator+, operator-  
 * Descripción

* Un polinomio es una expresión algebraica que constituye la suma o resta ordenadas de un número finito de monomios, que representamos a través de un vector disperso.

* El comportamiento es crear un polinomio, asignarle un coeficiente a un monomio, sumar, restar e igualar polinomios.
 
 */

template <typename  T>
class Polinomio
{
public:
  class iterator;
  class const_iterator;

//////////// constructores //////////////
  		
/** @brief constructor primitivo. 
	@post define un constructor primitivo inicializando todos los elementos a un valor. Si no se proporciona ningún valor se inicializan al valor por defecto.
	@param t valor para los elementos. 
	*/
Polinomio(const T & t= T());


/** @brief constructor de copia. 
	@param[in] b polinomio a copiar
	*/   	
Polinomio(const Polinomio< T > & b);    	


/** @brief constructor
	@post constructor primitivo que crea un Polinomio con numcomp componentes, todas ellas iguales a t. numcomp deve ser mayor que cero.
	@param[in] numcomp número de componentes del vector
	@param[in] t valor por defecto 
	*/
Polinomio( int grado, const  T  & t);


////////////// destructor ////////////

/** @brief destructor. 
	*/    	
~Polinomio();


/////////// Consultores ////////////

/** @brief consulta el grado del polinomio
*/
int gradoPolinomio() const;

/** @brief consulta coeficiente del monomio de grado p
@return el valor del coeficiente
*/
T  coeficiente(int p) const;

////////  MODIFICADORES //////////////////////

/** @brief
  Cambia al valor t el coeficiente de grado p del polinomio.
  @param[in] p grado del monomio a modificar, t valor nuevo.
  @post no modifica el grado del polinomio.
*/
void assign(int p, const  T  & t);

/////////////// operadores ///////////////////

/** @brief operador de asignación
Crea un polinomio duplicado exacto de x.
@param[in] x polinomio  a copiar.
*/
Polinomio & operator= (const Polinomio & x);

/** @brief operador suma
    Suma dos polinomios
@param[in] x polinomio a sumar
*/
Polinomio & operator+ (const Polinomio & x);

/** @brief operador resta
    Resta dos polinomios
@param[in] x polinomio a restar
*/
Polinomio & operator- (const Polinomio & x);

////////////////////////////////////////


/** @brief  
    @return Devuelve el iterador a la primera posición del polinomio.
	@post no modifica el polinomio
*/
iterator begin();

/** @brief  
    @return Devuelve el iterador a la posición final (siguiente al útlimo) del polinomio.
	@post no modifica el polinomio
*/
iterator end();

/** @brief  
    @return Devuelve un iterador constante a la primera posición del polinomio.
	@post no modifica el polinomio
*/
const_iterator cbegin() const;

/** @brief  
    @return Devuelve un iterador constante a la posición final (siguiente al útlimo) del polinomio.
	@post no modifica el polinomio
*/
const_iterator cend() const;

private: // parte  privada

    vectorD<T> monomios;
    int grado;
 
    /* FA e IR*/
    /* FA(rep): rep -- > polinomio
      (monomios,grado):
         monomios=[ (a,v1), (b,v2), ..., (n,vn) ]
         grado = M
      --------->
      pos: 0 1 2 ... a-1 a ... x .... b....  ... n-1 n  n+1 ..... M-1
      val: t t t ....t  v1 ... t .... v2 ..  ... t   vn  t  ...... t
      */
public:

  class iterator{
  public:
    friend class Polinomio;
    
    iterator();
    iterator(const iterator & d);
    const  T  & operator *(  ) ;
    iterator & operator++( );
    iterator operator++(int ) ; 
    bool operator == (const iterator & d) ;
    bool operator != (const iterator & d);
    iterator & operator=(const iterator & d);

  private:
   typename vectorD<T>::iterator it;
};
    
  class const_iterator{
  public:
    friend class Polinomio;
    
    const_iterator() ;
    const_iterator(const const_iterator & d);
    const_iterator(const iterator & d);
    const  T  &  operator *(  ) ;
    const_iterator & operator++( ) ;
    const_iterator operator++(int ) ;
    bool operator == (const const_iterator & d) ;
    bool operator != (const const_iterator & d) ;
    
  private:
    typename vectorD<T>::const_iterator it;
};

};

#include "polinomio.cpp"

#endif
 
