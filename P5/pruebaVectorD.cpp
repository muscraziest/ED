#include <iostream>
#include "vectorDlistas.h"
using namespace std;

int main(){

	vectorD<int> v1(5, 0);
	vectorD<int> v2(v1);
	vectorD<int> v3 (10, 3);
	vectorD<int>::iterator it_n;
	vectorD<int>::stored_iterator it_s;

	cout << "Size V3: " << v3.size() << endl;
	cout << "Default value V3: " << v3.default_value() << endl;
	cout << "Default value V1: " << v1.default_value() << endl;

	v3.assign(2,3);
	v3.assign(1,5);
	v3.assign(4,6);
	v3.assign(1,3);

	cout << "V3 despues de assign(): " << endl;
	cout << "V3 (vector completo): "<< endl;
	for(it_n = v3.begin(); it_n != v3.end(); ++it_n){

		cout << (*it_n) << " ";
	}
	cout << endl;
	cout << "V3 (elementos no nulos): "<< endl;
	for(it_s = v3.sbegin(); it_s != v3.send(); ++it_s){

		cout << "(" << (*it_s).first << " ," << (*it_s).second << ") ";
	}
	cout << endl;

	v2.push_back(0);
	v2.push_back(5);
	v2.push_back(3);

	cout << "V2 despues de push_back(): " << endl;
	cout << "V2 (vector completo): "<< endl;
	for(it_n = v2.begin(); it_n != v2.end(); ++it_n){

		cout << (*it_n) << " ";
	}
	cout << endl;
	cout << "V2 (elementos no nulos): "<< endl;
	for(it_s = v2.sbegin(); it_s != v2.send(); ++it_s){

		cout << "(" << (*it_s).first << " ," << (*it_s).second << ") ";
	}
	cout << endl;

	v2.pop_back();
	cout << "V2 despues de pop_back(): " << endl;
	cout << "V2 (vector completo): "<< endl;
	for(it_n = v2.begin(); it_n != v2.end(); ++it_n){

		cout << (*it_n) << " ";
	}
	cout << endl;
	cout << "V2 (elementos no nulos): "<< endl;
	for(it_s = v2.sbegin(); it_s != v2.send(); ++it_s){

		cout << "(" << (*it_s).first << " ," << (*it_s).second << ") ";
	}
	cout << endl;

	v3.clear();
	cout << "V3 despues de clear(): " << endl;
	cout << "V3 (vector completo): "<< endl;
	for(it_n = v3.begin(); it_n != v3.end(); ++it_n){

		cout << (*it_n) << " ";
	}
	cout << endl;

	v1.resize(6);

	cout << "V1 despues de resize(6): " << endl;
	cout << "V1 (vector completo): "<< endl;
	for(it_n = v1.begin(); it_n != v1.end(); ++it_n){
		
		cout << *it_n << " ";
	}
	cout << endl;
	cout << "V1 (elementos no nulos): "<< endl;
	for(it_s = v1.sbegin(); it_s != v1.send(); ++it_s){

		cout << "(" << (*it_s).first << " ," << (*it_s).second << ") ";
	}
	cout << endl;

	v1.resize(2);

	cout << "V1 despues de resize(2): " << endl;
	cout << "V1 (vector completo): "<< endl;
	for(it_n = v1.begin(); it_n != v1.end(); ++it_n){

		cout << (*it_n) << " ";
	}
	cout << endl;
	cout << "V1 (elementos no nulos): "<< endl;
	for(it_s = v1.sbegin(); it_s != v1.send(); ++it_s){

		cout << "(" << (*it_s).first << " ," << (*it_s).second << ") ";
	}
	cout << endl;

	cout << "v2[0] = " << v2[0] << endl;
	cout << "v2[4] = " << v2[4] << endl;

	cout << "v2.at(0) = " << v2.at(0) << endl;
	cout << "v2.at(4) = " << v2.at(4) << endl;

	v1 = v3;

	cout << "V1 = V3: " << endl;
	cout << "V1 (vector completo): "<< endl;
	for(it_n = v1.begin(); it_n != v1.end(); ++it_n){

		cout << (*it_n) << " ";
	}
	cout << endl;
	cout << "V1 (elementos no nulos): "<< endl;
	for(it_s = v1.sbegin(); it_s != v1.send(); ++it_s){

		cout << "(" << (*it_s).first << " ," << (*it_s).second << ") ";
	}
	cout << endl;

	cout << "V3 (vector completo): "<< endl;
	for(it_n = v3.begin(); it_n != v3.end(); ++it_n){

		cout << (*it_n) << " ";
	}
	cout << endl;
	cout << "V3 (elementos no nulos): "<< endl;
	for(it_s = v3.sbegin(); it_s != v3.send(); ++it_s){

		cout << "(" << (*it_s).first << " ," << (*it_s).second << ") ";
	}
	cout << endl;

	if(v1 == v3)
		cout << "V1 y V3 son iguales" << endl;
	else
		cout << "V1 y V3 no son iguales" << endl;

	if(v1 != v2)
		cout << "V1 y V2 no son iguales" << endl;
	else
		cout << "V1 y V2 son iguales" << endl;
		
}	