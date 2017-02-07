#include <iostream>
#include <set>
#include <unordered_set>
#include <iostream>
#include "gs1Set.h"
#include "gs1Set.cpp"
#include <fstream>

/** @brief Carga el fichero en memoria
 * @param contenedor contenedor de salida
 * @param s nombre del fichero 
 * @pre T debe tener el método insert(const string &)
 */

using namespace std;

int main(int argc, char *argv[]){
  
   gs1Set gs1,gs2;
   list<string> codigos;

   gs1.insert("(03)12(02)456");
   gs1.insert("(02)23(02)3");
   gs1.insert("(04)2");
   gs1.insert("(03)13");
   gs1.insert("(00)245(01)");

   //gs1.print();

  gs1Set::const_iterator it;

   it = gs1.find("(03)12(02)456");

   cout << "Buscamos el código (03)12(02)456: " << *it << endl;

   codigos = gs1.codesWithPrefix("(03)");

   cout << "Códigos con prefijo (03): " << endl;

   while(!codigos.empty()){
      cout << codigos.front() << endl;
      codigos.pop_front();
   }

   gs1.erase("(03)13");

   gs1.print(); 
}
   