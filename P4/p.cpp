#include "diccionario.h"
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;


int main(){


    diccionario<string,int> notas;
    diccionario<string,int>::entrada e1;
    diccionario<string,int>::entrada e2;
    diccionario<string,int>::entrada e3;
    diccionario<string,int>::iterator it(notas.begin());
	

    
    e1.first = "hola";
    e1.second = 1;
    e2.first = "adios";
    e2.second = 2;
    e3.first = "teodio";
    e3.second = 3;


    

    if (notas.find("a") == notas.end()){

        cout << "Si" << endl;
    }

    else{

        cout << "NO " << endl;
    }

    notas.insert(e1);
    notas.insert(e2);
    notas.insert(e3);


    //cout << notas << endl;

    cout << endl;



   return 0;
}
