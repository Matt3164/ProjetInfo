
#include"Cache.h"
#include"CacheLine.h"
#include <iostream>
#include<iomanip>
#include <stdio.h>
#include<math.h>
#include <cstdint>

using namespace std;

int main() {

	// Test de la fonction tag
	CacheLine CL;
    int taille = pow(2.0, 4);
    double* b =  new double [taille];
    
    CL.load(b);
    
    cout << "L'adresse de b est : " << b << endl;
    cout << "L'adresse de b est : " << &(b[0]) << endl;
    cout << "L'adresse de b est : " << &(b[1]) << endl;
    
    cout << "Test sur le tag" << endl;
    /*for (int i = 0; i < taille; i++) {
        cout << "Le tag de b[" << i  << "] est : " << CL.tag(&(b[i])) << endl;
        cout << "Le decalage de b[" << i  << "] est : " << CL.decalage(&(b[i])) << endl;
        
    }*/
    
    
    Cache caca;
    for (int i = 0 ; i < 5; i++) {
        cout << "Le booleen de la ligne[" << i << "] est " << caca.cache[i].valid << endl;
    }
    
    caca.cache[3].load(b);
    
    for (int i = 0 ; i < 5; i++) {
        cout << "Le booleen de la ligne[" << i << "] est " << caca.cache[i].valid << endl;
    }
    
    
    for (int i = 0; i < taille; i++) {
        cout << "L'index de b[" << i << "] est : " << caca.lineIndex(&b[i]) << endl;

    }
    
    cout << "On récupère le terme b : " << caca.get(&b[1]) << endl;
    caca.set(&b[1], 2.);
    cout << "On récupère le terme b : " << caca.get(&b[1]) << endl;
    
    double* c = new double[15];
    caca.set(&c[1], 2.);
    cout << "On récupère le terme b : " << caca.get(&c[1]) << endl;
    
    cout << "Le hit ratio est : " << caca.hitratio() << endl;
    
    
    

	return 0;
}
