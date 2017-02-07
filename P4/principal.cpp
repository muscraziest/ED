#include "diccionario.h"
#include "meteorito.h"
#include <list>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

void load(diccionario<nombreM,defM> & d, const string & s){

    string cadena;
    string nombre;
    string code;
    string num;
    string f;
    double mas;
    bool fall;
    string year;
    double lat;
    double lon;
    ifstream fi;
    std:: size_t aux;

    fi.open(s.c_str());

    //Leemos la primera linea de name, reclass...
    getline(fi, cadena);

    while(!fi.eof()){

        diccionario<nombreM, defM>::entrada e;

        int pos_inicio = 0;
        int pos_final;

        getline(fi, cadena); //Vamos leyendo el fichero s.

        //Buscamos el nombre
        pos_final = cadena.find_first_of(";",pos_inicio);

        //nombre.assign(cadena, pos_inicio, (pos_final-pos_inicio-1));
        nombre = cadena.substr(pos_inicio, pos_final-pos_inicio);

        e.first = nombre;

        pos_inicio = pos_final+1;

        //Buscamos los códicos
        pos_final = cadena.find_first_of(";", pos_inicio);

        code = cadena.substr(pos_inicio, pos_final-pos_inicio);

        string aux;
        string copia = code;

        //Mientras haya más de un código
        while(copia.find(',') != string::npos){

            int pi = 0;
            int p;

            p = copia.find_first_of(",",pi);

            aux = copia.substr(pi, p);

            copia.erase(pi,p+1);

            e.second.setCode(aux);

        }

        aux = copia.substr(0);

        e.second.setCode(aux);

        pos_inicio = pos_final+1;

        //Buscamos la masa
        pos_final = cadena.find_first_of(";",pos_inicio);

        num = cadena.substr(pos_inicio, pos_final-pos_inicio);

        //Si hay una coma en el string num, la cambiamos por un punto
        if(num.find(',') != num.size()-1){

        	num[num.find(',')] = '.';
        }

        mas = atof(num.c_str());    //Convertimos la cadena a doble

        e.second.setMas(mas);

        pos_inicio = pos_final+1;


        //Buscamos si ha sido encontrado
        pos_final = cadena.find_first_of(";",pos_inicio);

        f = cadena.substr(pos_inicio, pos_final-pos_inicio);

        if(f == "Found"){

            e.second.setFall(true);
        }

        else{

            e.second.setFall(false);
        }

        pos_inicio = pos_final+1;

        //Buscamos el año
        pos_final = cadena.find_first_of(";",pos_inicio);

        year = cadena.substr(pos_inicio, pos_final-pos_inicio);

        e.second.setYear(year);

        pos_inicio = pos_final+1;

        //Buscamos la latitud
        pos_final = cadena.find_first_of(";",pos_inicio);

        num = cadena.substr(pos_inicio, pos_final-pos_inicio);

        //Si hay una coma en el string num, la cambiamos por un punto
        if(num.find(',') != num.size()-1){

        	num[num.find(',')] = '.';
        }

        lat = atof(num.c_str());    //Convertimos la cadena a doble

        e.second.setLat(lat);

        pos_inicio = pos_final+1;

        //Buscamos la longitud
        num = cadena.substr(pos_inicio);

        //Si hay una coma en el string num, la cambiamos por un punto
        if(num.find(',') != num.size()-1){

        	num[num.find(',')] = '.';
        }

        lon = atof(num.c_str());    //Convertimos la cadena a doble

        e.second.setLong(lon);

        //Insertamos la entrada en el diccionario
        d.insert(e);

    }

    fi.close();

}

/** @brief organiza el conjunto de meteoritos por tipologia
@param[in] nombre_fichero que contiene el conjunto de meteoritos
@param[out] tipos un diccionario donde para cada tipo de meteorito se almacena la lista de todos los nombres de meteoritos que pertenecen al mismo.
Recordemos que el diccionario tiene clave unica, por tanto no puede haber elementos con clave repetida.
Por este motivo, y dado que la tipologia del meteorito se repite por las distintas entradas del fichero,
se tendrá para cada una de las mismas una lista con los nombres de meteoritos.
*/
void listaTipos(const string & nombre_fichero, diccionario<string,list<nombreM> > & tipos){

    string cadena;
    nombreM nombre;
    string code;
    ifstream fi;
    std:: size_t aux;

    fi.open(nombre_fichero.c_str());

    //Leemos la primera linea de name, reclass...
    getline(fi, cadena);

    while(!fi.eof()){

        diccionario<string,list<nombreM> >::entrada e;

        int pos_inicio = 0;
        int pos_final;

        getline(fi, cadena); //Vamos leyendo el fichero s.

        //Buscamos el nombre
        pos_final = cadena.find_first_of(";",pos_inicio);

        //nombre.assign(cadena, pos_inicio, (pos_final-pos_inicio-1));
        nombre = cadena.substr(pos_inicio, pos_final-pos_inicio);

        pos_inicio = pos_final+1;

        //Buscamos los códicos
        pos_final = cadena.find_first_of(";", pos_inicio);

        code = cadena.substr(pos_inicio, pos_final-pos_inicio);

        string aux;
        string copia = code;

        //Mientras haya más de un código
        while(copia.find(',') != string::npos){

            int pi = 0;
            int p;

            p = copia.find_first_of(",",pi);

            aux = copia.substr(pi, p);

            copia.erase(pi,p+1);

            //Guardamos el código
            e.first = aux;

            //Insertamos el código en el diccionario
            tipos.insert(e);

            //Añadimos el nombre al código
            tipos[aux].push_back(nombre);

        }

        aux = copia.substr(0);

        e.first = aux;

        //Insertamos el código en el diccionario
        tipos.insert(e);

        tipos[aux].push_back(nombre);
    }

    fi.close();

}


/** @brief Obtiene el diccionario teniendo en cuenta el año de caida del meteorito
@param[in] nombre_fichero que contiene el conjunto de meteoritos
@param[out] met_anio número de meteoritos clasificados por año de caida.
@return el año con más caidas.
*/
string caidos_por_anio(const string & nombre_fichero, diccionario<string,int> & met_anio){

    string cadena;
    string code;
    string anioM;
    fstream fi;
    string anio;
    int mayor = 0;

    fi.open(nombre_fichero.c_str());

    getline(fi,cadena);//Quitamos la fila que tiene el formato del fichero: name;recclass;mass;fall;year;reclat;reclong

    while (!fi.eof())
    {

        diccionario<string,int>::entrada e;

        int pos_inicio = 0;
        int pos_final;

        getline(fi, cadena); //Vamos leyendo el fichero.

        //Buscamos el nombre
        pos_final = cadena.find_first_of(";",pos_inicio);
        pos_inicio=pos_final+1;

        //Buscamos los códicos
        pos_final = cadena.find_first_of(";", pos_inicio);
        pos_inicio=pos_final+1;

         //Buscamos la masa
        pos_final = cadena.find_first_of(";",pos_inicio);
        pos_inicio=pos_final+1;

         //Buscamos si ha caido
        pos_final = cadena.find_first_of(";",pos_inicio);
        pos_inicio=pos_final+1;

         //Buscamos el año
        pos_final = cadena.find_first_of(";",pos_inicio);
        anioM = cadena.substr(pos_inicio, pos_final-pos_inicio);

        //Si no está el año se inserta y pone el valor de caidas a 1
        //Si está, incrementa el valor de caídas
        met_anio[anioM]++;

        if(met_anio[anioM] > mayor){

            mayor = met_anio[anioM];
            anio = anioM;
        }

    }

    fi.close();

    return anio;

}



int main(){


    diccionario <nombreM,defM> Meteoritos;
    list<nombreM> l;
    list<nombreM> :: iterator it;
    load(Meteoritos, "meteorites_all.csv");

    diccionario <string,list<nombreM> > tipos;
    listaTipos("meteorites_all.csv", tipos);

    l = tipos["EH4"];

    for(it = l.begin(); it != l.end(); it++){

        cout << *it << ", ";
    }

    cout << endl;

    diccionario <string, int> anios;
    cout << "Anio max caidos: " << caidos_por_anio("meteorites_all.csv", anios) << endl;


   return 0;
}
