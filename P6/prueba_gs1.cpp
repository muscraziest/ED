#include <iostream>
#include <set>
#include <unordered_set>
#include <iostream>
#include "gs1Set.h"
#include "gs1Set.cpp"
#include <fstream>
#include <time.h>

/** @brief Carga el fichero en memoria
 * @param contenedor contenedor de salida
 * @param s nombre del fichero 
 * @pre T debe tener el método insert(const string &)
 */

using namespace std;

template <typename T>
void load(T  &  contenedor, const string & s) {
 ifstream fe;
 string cadena;
 //cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail()){
   cerr << "Error al abrir el fichero " << s << endl;
 } 
 else {
    while ( !fe.eof() ){ 
		
		  getline(fe,cadena,'\n');
      if (!fe.eof()) {
	   	 //cout << "leo:: "<< cadena << endl;

	     contenedor.insert(cadena);
      }
     }
    } // else
  fe.close();
}
 
 
 int main(int argc, char *argv[]){
  
   if (argc !=2) {
     cout << "formato: nombre_ejecutable datos.txt" << endl;
     exit(1);
   }
   
   string nfichero = string(argv[1]);
   set<string> s,s_copia;
   unordered_set<string> us_codigo,us_copia;
   gs1Set gs1,gs1_copia;
   ifstream fe;
   clock_t start, end;
   double dif_set, dif_un, dif_gs1;
   string cadena;
   /* Insercion de elementos en los tres ficheros*/
   /*
  gs1.print();
  cout << "Tiempo en el insert: " << endl;
   for(int i=1; i <= 10; i++){
    start = clock();
    for(int j=0; j < i; j++){ 
      load(us_codigo,nfichero);
      us_codigo.clear();
    }

    end = clock();
    dif_un = end-start;
    cout << i*100000 << " " << dif_un/CLOCKS_PER_SEC << endl;


    start = clock();
    for(int j=0; j < i; j++){ 
      load(s,nfichero);
      s.clear();
    }
    end = clock();
    dif_set = end-start;
    cout << i*100000 << " " << dif_set/CLOCKS_PER_SEC << endl;
   
    start = clock();
    for(int j=0; j < i; j++){ 
      load(gs1,nfichero);
      gs1.clear();
    }
    end = clock();
    dif_gs1 = end-start;
    cout << i*100000 << " " << dif_gs1/CLOCKS_PER_SEC << endl;
 }
*/
  load(us_codigo,nfichero);
  load(s,nfichero);
  load(gs1,nfichero);
/*
  cout << "Tiempo en el find: " << endl;

  for(int i=1; i <= 10; i++){

    fe.open(nfichero.c_str(), ifstream::in);
    start = clock();
    for(int j=0; j < 1000*i; j++){
        getline(fe,cadena,'\n');
        cadena += 'h';
        us_codigo.find(cadena);
        cadena = "";
    }
    end = clock();
    dif_un = end-start;
    fe.close();

    cout << i*1000 << " " << dif_un/CLOCKS_PER_SEC << endl;
  
    fe.open(nfichero.c_str(), ifstream::in);
    start = clock();
    for(int j=0; j < 1000*i; j++){
        getline(fe,cadena,'\n');
        cadena += 'h';
        s.find(cadena);
        cadena = "";
    }
    end = clock();
    dif_set = end-start;
    fe.close();

    cout << i*1000 << " " << dif_set/CLOCKS_PER_SEC << endl;

    fe.open(nfichero.c_str(), ifstream::in);
    start = clock();
    for(int j=0; j < 1000*i; j++){
        getline(fe,cadena,'\n');
        cadena += 'h';
        gs1.find(cadena);
        cadena = "";
    }
    end = clock();
    dif_gs1 = end-start;
    fe.close();

    cout << i*1000 << " " << dif_gs1/CLOCKS_PER_SEC << endl;
 
*/
    cout << "Tiempo erase: " << endl;
    for(int i=1; i <= 20; i++){

    fe.open(nfichero.c_str(), ifstream::in);
    start = clock();
    us_copia = us_codigo;
    for(int j=0; j < 10000*i; j++){
        getline(fe,cadena,'\n');
        us_copia.erase(cadena);
        cadena = "";
    }
    end = clock();
    dif_un = end-start;
    fe.close();

    //cout << i*10000 << " " << dif_un/CLOCKS_PER_SEC << endl;
  
    fe.open(nfichero.c_str(), ifstream::in);
    start = clock();
    s_copia = s;
    for(int j=0; j < 10000*i; j++){
        getline(fe,cadena,'\n');
        s_copia.erase(cadena);
        cadena = "";
    }
    end = clock();
    dif_set = end-start;
    fe.close();

    //cout << i*10000 << " " << dif_set/CLOCKS_PER_SEC << endl;

    fe.open(nfichero.c_str(), ifstream::in);
    start = clock();
    gs1_copia = gs1;
    for(int j=0; j < 10000*i; j++){
        getline(fe,cadena,'\n');
        gs1_copia.erase(cadena);
        cadena = "";
    }
    end = clock();
    dif_gs1 = end-start;
    fe.close();

    cout << i*10000 << " " << dif_gs1/CLOCKS_PER_SEC << endl;
 }
}