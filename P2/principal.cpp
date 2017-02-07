#include "diccionario.h"
#include "meteorito.h"
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

        entrada e;

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

int main()
{
    diccionario D<nombreM,defM>;
    meteorito m;
    defM x;
    
    cout << m << endl;

    D.insert(m);
    pair<diccionario::entrada,bool> p;
    p = D.find("aaaa");
    if (p.second==true) cout << p.first << endl;
    else cout << "No existe aaaa" << endl;


    cout << D["Barcelona"] << endl;

    D["Valencia"] = x;
    cout<< D["Valencia"] << endl;


    diccionario Meteoritos<nombreM,defM>;
    load(Meteoritos, "meteorites_all.csv");

    cout << "Diccionario: " << endl;

    cout << Meteoritos << endl;
 
    cout << endl;

    cout << Meteoritos["Bustee"] << endl;

   return 0;
}