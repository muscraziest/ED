#include <iostream>
#include <list>
#include "polinomio.h"
using namespace std;

int main(){

	Polinomio<int> p1(5,0);
	Polinomio<int> p2(3,0);
	Polinomio<int> p3(3,0);
	Polinomio<int> p4;
	Polinomio<int>::iterator it;
	int i;

	p1.assign(0,1);
	p1.assign(3,4);
	p1.assign(4,1);

	p2.assign(0,3);
	p2.assign(2,1);

	p3.assign(0,1);
	p3.assign(1,4);
	p3.assign(2,-3);

	cout << "P1: " << endl;

	for(it = p1.begin(),i=0; it != p1.end(); it++,i++)
		cout << *it << "x^" << i << " + ";
	cout << endl;

	cout << "P2: " << endl;

	for(it = p2.begin(),i=0; it != p2.end(); it++,i++)
		cout << *it << "x^" << i << " + ";
	cout << endl;	

	cout << "P3: " << endl;

	for(it = p3.begin(), i=0; it != p3.end(); it++,i++)
		cout << *it << "x^" << i << " + ";
	cout << endl;

	cout << "P1 + P2: " << endl;
	p4 = p1+p2;

	for(it = p4.begin(), i=0; it != p4.end(); it++,i++)
		cout << *it << "x^" << i << " + ";
	cout << endl;

	cout << "P3 - P2: " << endl;
	p4 = p3-p2;

	for(it = p4.begin(), i=0; it != p4.end(); it++,i++)
		cout << *it << "x^" << i << " + ";
	cout << endl;
	
}	