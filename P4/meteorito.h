/* 
 * meteorito.h
 * 
 * Copyright  (C) María del Mar García Cabello Laura Tirado López
*/
#ifndef __METEORITO_H
#define __METEORITO_H

#include <string>
#include <iostream> 
using namespace std;

//! Clase defM, asociada a la definición de un meteorito 
/*! defM::defM, setCode, setMas, setFall, setYear, setLat, setLong,
    getCodes, getMas, getFall, getYear, getLat, getLong

    * Un meteorito es un tipo de dato formado por un par de elementos. El primero es el nombre y el segundo las características de dicho meteorito definidas en la clase defM.

    * La clase defM contiene los campos que definen las características de un meteorito: sus códigos específicos, su masa, si se conoce el lugar donde cayó o se sabe que ha caído, el año en que cayó y sus coordenadas de latitud y longitud. Ásí pues los métodos de la clase defM son modificadores (set) y consultores (get) de los valores de dichos atributos.
 

*/


class defM {

public:
  
   /** @brief Constructor primitivo 
   @post define un constructor primitivo que inicializa los datos a valores nulos 
   */
  /*!Correción:

	*El vector de códigos lo inicializamos a uno vacío.
	*Incializamos la masa a 0.0 en vez de a 0
	
   */
   defM();

   /** @brief Constructor de copia 
    @param[in] x definición a copiar
    */
    defM(const defM & x);

    /** @brief Inserta el código del meteorito
    @param[in] s código del meteorito
    @return true si el código era válido y se ha podido guardar, false en caso contrario
    */
   /*! Corrección:
	
	*Consideramos que un código es válido si no era vacío. Añadimos también que no esté repetido.
    */
    bool setCode(const string & s);

    /** @brief Inserta el valor de la masa del meteorito en gramos
    @param[in] m masa del meteorito
    */
    void setMas(const double &  m);

    /** @brief Inserta el valor de cuando cayó 
    @param[in] f valor de si ha caído el meteorito o no
    */
    void setFall(bool f);

    /** @brief Inserta el año en el que cayó el meteorito
    @param[in] y año 
    */
    void setYear(const string & y);

    /** @brief Inserta la latitud (coordenada) en la que cayó (coordenada)
    @param[in] l latitud
    */
    void setLat(double & l);

    /** @param Inserta la longitud (coordenada) en la que cayó (coordenada)
    @param[in] l longitud
    */
    void setLong(double & l);

    /** @brief Consulta el codigo del meteorito 
    @return codigo del meteorito
    */
    vector<string> getCodes();

    /** @brief Consulta el valor de la masa del meteorito 
    @return masa del meteorito
    */
    double getMas();

    /** @brief Consulta si el meteorito ha caído  
    @return true si el meteorito ha caido (se conoce su posicion), false en caso contrario
    */
    bool getFall();

    /** @brief Consulta el año en que cayó el meteorito 
    @return año en que cayó
    */
    string getYear();

    /** @brief Consulta la latitud (coordenada) del meteorito 
    @return latitud (coordenada) del meteorito
    */
    double getLat();

    /** @brief Consulta la longitud (coordenada) del meteorito 
    @return longitud (coordenada) del meteorito
    */
    double getLong();

private:

    friend  ostream& operator<< (ostream& , const defM &);

    vector<string> code;
    double mas;
    bool fall;
    string year;
    double lat;
    double lon;
  
};


typedef string nombreM;

typedef pair<nombreM,defM> meteorito;

ostream & operator<<(ostream&, const meteorito &);

#include "meteorito.hxx"  
#endif
