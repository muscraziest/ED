/* 
 * vectorD.h
 * 
 * Copyright  (C) María del Mar García Cabello, Laura Tirado Lopez.
*/


#ifndef __VECTORDISPERSO_H
#define __VECTORDISPERSO_H

#include <map>
#include <utility> // clase pair


using namespace std;

//! Clase vectorD
 /*! vectorD:: vectorD, size, empty, assing, push_back, pop_back
 *   clear, resize, at, operator[], operator=, operator==, operator !=  
 * Tipos vectorD::T, vectorD::size_type
 * Descripción

* Un vector disperso es un vector en el que sólo se almacenan los elementos distintos de un valor nulo (valor por defecto).

* Asociado al vector disperso, tenemos el valor nulo o valor por defecto de los elementos, el tamaño y un map con los elementos no nulos, formados por pares (posición, valor).

* El comportamiento es crear un vector disperso, consultar su valor nulo, su tamaño, el valor de un elemento, asignar valores a los elementos, comparar vectores e iterar sobre sus elementos.
 
 */

template <typename  T >
class vectorD
{
public:
class stored_iterator; // iterador sobre elementos no nulos (sobre lista)
class iterator; // iterador sobre todos los elementos del vector
class const_stored_iterator; //const iterador sobre elementos no nulos (sobre lista)
class const_iterator; // const iterador sobre todos los elementos del vector
typedef unsigned int size_type;
//////////// constructores //////////////
  		
/** @brief constructor primitivo. 
	@post define un constructor primitivo inicializando todos los elementos a un valor. Si no se proporciona ningún valor se inicializan al valor por defecto.
	@param t valor para los elementos. 
	*/
vectorD(const T & t= T());


/** @brief constructor de copia. 
	@param[in] b vector disperso a copiar
	*/   	
vectorD(  const vectorD< T > & b);    	


/** @brief constructor
	@post constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp deve ser mayor que cero.
	@param[in] numcomp número de componentes del vector
	@param[in] t valor por defecto 
	*/
vectorD(int numcomp, const  T  & t);


////////////// destructor ////////////

/** @brief destructor. 
	*/    	
~vectorD();


/////////// Consultores ////////////

/** @brief tamaño del vector
@post  No de los elementos guardados
*/
size_type size() const;

/** @brief consulta el valor por defecto
@return valor por defecto
*/
T  default_value( ) const;

/** @brief 
   Chequea si el vector disperso esta vacio (size()==0)
*/
bool empty() const;

////////  MODIFICADORES //////////////////////

/** @brief
  Cambia a el valor t el valor de la posicion p-esima del vector.
  @param[in] p posicion del valor a modificar, t valor nuevo.
  @post no modifica el tamaño del vector.
*/
void assign(int p, const  T  & t);

/** @brief
  Inserta un elemento al final del vectorD. 
  @param[in] t nuevo elemento.
  @post Aumenta en 1 el tamanio.
*/
void push_back( const  T  & t);

/** @brief 
  Elimina un elemento del vectorD.
  @post Disminuye en 1 el tamanio
*/
void pop_back(  );

/** @brief 
  Elimina todos los elementos del vectorD.
  @post Deja el tamaño a 0.
*/
void clear(); 

/** @brief 
  Cambia el tama~no del vector a "s" elementos.
  Si s es menor que el tama~no actual, elimina los restantes. Si es mayor,
  amplia la capacidad del vector asignando a todos los nuevos elementos el valor nulo. 
  @param[in] s nuevo tamaño
*/
void resize(int s); 

/////////////// operadores ///////////////////

/** @brief operador de asignación
Crea un vector disperso duplicado exacto de x.
@param[in] x vector disperso  a copiar.
*/
vectorD & operator= (const vectorD & x);

/** @brief Consulta el valor de una posición del vector disperso.
    Devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes
@param[in] c posición
@return T & referencia constante al valor asociado a la posición c
*/
const  T  & operator[](int c) const  ;

/** @brief  
	Devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes
	@param[in] c posición
	@return T & referencia constante al valor asociado a la posición c
	@post Hace comprobacion de rango.
*/
const  T  & at(int c) const  ;

/** @brief operador de igualdad.
	@param[in] x vector disperso con el que se va a comparar
	@return true si son iguales, false en caso contrario.
	@post dos vectores dispersos son iguales si lo son elemento a elemento.
*/
bool operator==( const vectorD & x);

/** @brief operador de desigualdad.
	@param[in] x vector disperso con el que se va a comparar
	@return true si son distintos, false en caso contrario.
*/
bool operator!=( const vectorD & x);
/**  */
////////////////////////////////////////


/** @brief  
    @return Devuelve el iterador a la primera posición del vector disperso.
	@post no modifica el vector disperso
*/
iterator begin();

/** @brief  
    @return Devuelve el iterador a la posición final (siguiente al útlimo) del vector disperso.
	@post no modifica el vector disperso
*/
iterator end();

/** @brief  
    @return Devuelve un iterador constante a la primera posición del vector disperso.
	@post no modifica el vector disperso
*/
const_iterator cbegin() const;

/** @brief  
    @return Devuelve un iterador constante a la posición final (siguiente al útlimo) del vector disperso.
	@post no modifica el vector disperso
*/
const_iterator cend() const;

/** @brief  
    @return Devuelve un iterador a la primera posición de los elementos no nulos.
	@post no modifica el vector disperso
*/
stored_iterator sbegin(); 

/** @brief  
    @return Devuelve un iterador a la posición final (siguiente al último) de los elementos no nulos.
	@post no modifica el vector disperso
*/
stored_iterator send();

/** @brief  
    @return Devuelve un iterador constante a la primera posición de los elementos no nulos.
	@post no modifica el vector disperso
*/
const_stored_iterator csbegin() const; 

/** @brief  
    @return Devuelve un iterador constante a la posición final (siguiente al último) de los elementos no nulos.
	@post no modifica el vector disperso
*/
const_stored_iterator csend() const;

private: // parte  privada

    map<int, T> vd; // lista que aloja el vector disperso (solo los != valor nulo)
    int n_ele; // numero de elementos totals
    T   v_nulo; //valor nulo del vector
 
    /* FA e IR*/
    /* FA(rep): rep -- > vector
      (vd,n_ele,v_nulo):
         vd=[ (a,v1), (b,v2), ..., (n,vn) ]
         n_ele = M
         v_nulo = t
      --------->
      pos: 0 1 2 ... a-1 a ... x .... b....  ... n-1 n  n+1 ..... M-1
      val: t t t ....t  v1 ... t .... v2 ..  ... t   vn  t  ...... t
      */
     
    int checkRep();
    /* devuelve el tipo de fallo segun indica el IR */
	//0 si no hay fallo
    /* IR :
      IR(rep): rep ---> bool
     (vd,n_ele,v_nulo) :
      0 <= vd.size() < n_ele;  //Fallo tipo 1 
      vd[i].second != v_nulo, para todo i = 0, ..., vd.size()-1; // Fallo tipo 2 
      vd[i].first >=0, para todo i = 0, ..., vd.size()-1; // Fallo tipo 3
      vd[i].first < vd[j].first si i<j // Fallo tipo 4
     */
    
  /* ITERADORES SOBRE VECTOR DISPERSO */
public:
  
  /** @brief class stored_iterator
	 * forward iterador sobre los elementos no nulos del vector disperso, Lectura y Escritura
	 *  stored_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
* */
  public:
class stored_iterator{
  public:
    friend class vectorD;
    friend class vectorD< T >::const_stored_iterator;
    
    stored_iterator(); 
    stored_iterator(const stored_iterator & d);
    pair<const int, const T > & operator *(  );
    stored_iterator & operator++( ); 
    stored_iterator operator++(int );  
    bool operator == (const stored_iterator & d);
    bool operator != (const stored_iterator & d);
    
  private:
    
    typename map<int, T >::iterator ite;
};

/** @brief class iterator
	 * forward iterador sobre el vector disperso, Lectura y Escritura
	 *  iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
* */
class iterator{
  public:
    friend class vectorD;
    
    iterator() ;
    iterator(const iterator & d);
    const  T  & operator *(  ) ;
    iterator & operator++( );
    iterator operator++(int ) ; 
    bool operator == (const iterator & d) ;
    bool operator != (const iterator & d);
    iterator & operator=(const iterator & d);

  private: int i_vect; // indice sobre el vector abstracto
    typename map<int, T >::iterator ite_rep; //iterador a la representacion
    vectorD *el_vect; // ptro al vector para obtener el valor nulo del vector
    /* FA e IR*/
    /* FA(rep): rep -- > iterador sobre vector abstracto
      (i_vect, ite_rep, el_vec):
      i_vect = k    
      ite_rep = p   
      el_vect = v   
       --------->
      iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
       */
      /* IR :
       IR(rep): rep ---> bool
     (i_vect, ite_rep): 
       --------->
       0 <= i_vect <=n_ele
       i_vect <= (*ite_rep).first
       */
       
};

  /** @brief class const_iterator
	 * forward iterador sobre los elementos no nulos del vector disperso, Lectura
	 * const_stored_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
* */
class const_stored_iterator{
  public:
    friend class vectorD;
    
    const_stored_iterator();
    const_stored_iterator(const const_stored_iterator & d) ;
    const_stored_iterator(const stored_iterator & d) ; // Conversion de iterator a const_stored_iterator
    pair<const int, const T > & operator *(  ) ;
    const_stored_iterator & operator++( ) ; 
    const_stored_iterator operator++(int ) ;
    bool operator == (const const_stored_iterator & d) ;
    bool operator != (const const_stored_iterator & d) ;
    const_stored_iterator & operator= (const const_stored_iterator & d) ;
 
  private:
    typename map<int, T>::const_iterator ite;
};

  /** @brief class const_iterator
	 * forward iterador sobre el vector disperso, Lectura y Escritura
	 *  const_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
* */
class const_iterator{
  public:
    friend class vectorD;
    
    const_iterator() ;
    const_iterator(const const_iterator & d) ;
    const_iterator(const iterator & d) ;
    const  T  &  operator *(  ) ;
    const_iterator & operator++( ) ;
    const_iterator operator++(int ) ;
    bool operator == (const const_iterator & d) ;
    bool operator != (const const_iterator & d) ;
    
  private:
    int i_vect; // indice sobre el vector abstracto
    typename map<int, T>::const_iterator ite_rep; //iterador a la representacion
    const vectorD *el_vect; // ptro al vector para obtener el valor nulo del vector
    /* FA e IR*/
    /* FA(rep): rep -- > iterador sobre vector abstracto
      (i_vect, ite_rep, el_vec):
      i_vect = k
      ite_rep = p 
      el_vect = v
       --------->
      iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
       */
   
      /* IR :
       IR(rep): rep ---> bool
     (i_vect, ite_rep): 
       --------->
       0 <= i_vect <=n_ele
       i_vect <= (*ite_rep).first
       */
       
};



};

#include "vectorDmap.hxx"

#endif
 
