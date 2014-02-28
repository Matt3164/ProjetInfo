
#include"Cache.h"
#include"CacheLine.h"
#include <iostream>
#include<iomanip>
#include <stdio.h>
#include<math.h>
#include <cstdint>

using namespace std;

int main() {
    
    Cache Cac;
    double * test = new double[100];
    
    cout << "Adresse : " << (intptr_t) test << endl;
    intptr_t tag = (((intptr_t) test >> 4) << 4);
    cout << "Tag : " << tag << endl;
    cout << "Tag calculé : " << Cac.cache[0].tag(test) << endl;
    intptr_t dec = (intptr_t) test - tag;
    cout << "Decalage : " << dec << endl;
    cout << "Decalage calculé : " << Cac.cache[0].decalage(test) << endl;
    
    intptr_t tag2 = (((intptr_t) test >> 9) << 9);
    intptr_t li = (tag - tag2) >> 4;
    
    cout << "Line index : " << li << endl;
    cout << "Line index : " << Cac.lineIndex(test) << endl;
    
    cout << "test de get" << endl;
    test[0] = 2.;
    cout << "Premier test : " << Cac.get(test) << endl;
    cout << "Deuxième test : " << Cac.get(test) << endl;
    test++;
    cout << "test de set" << endl;
    Cac.set(test, 3);
    cout << "Premier test de set : " << Cac.get(test) << endl;
    test++;
    Cac.set(test, 7);
    cout << "Premier test de set : " << Cac.get(test) << endl;
    
    cout << "Hit Ratio : " << Cac.hitratio() << endl;
    
    
    
    
    
	return 0;
}
