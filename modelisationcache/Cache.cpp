#include"Cache.h"
#include "CacheLine.h"
#include <iostream>
#include <cmath>
#define n 5



Cache::Cache(){

	hit = 0;
    miss = 0;
    
    cache = new CacheLine[(int) pow(2,n)];

}

double Cache::get(double * p){

    if (cache[lineIndex(p)].valid && cache[lineIndex(p)].tag(p) == cache[lineIndex(p)].itag(cache[lineIndex(p)].xtag)) {
        std::cout << "Get : Il est dans le cache" << std::endl;
        hit++;
        return cache[lineIndex(p)].getLine(p);
    }else{
        cache[lineIndex(p)].load(p);
        std::cout << "Get : Il n'est pas dans le cache" << std::endl;
        miss++;
        return cache[lineIndex(p)].getLine(p);
    }
}

void Cache::set(double * p, double value){

    if (cache[lineIndex(p)].valid && cache[lineIndex(p)].tag(p) == cache[lineIndex(p)].itag(cache[lineIndex(p)].xtag)) {
        std::cout << "Set : Il est dans le cache" << std::endl;
        hit++;
        cache[lineIndex(p)].setLine(p, value);
        
    }else{
        std::cout << "Set : Il n'est pas dans le cache" << std::endl;
        miss++;
        cache[lineIndex(p)].load(p);
        cache[lineIndex(p)].setLine(p, value);
    }
    
}


int Cache::lineIndex(double * p){
    
    intptr_t verif = ((intptr_t) p >> 9) << 9;
    return ((intptr_t) p - verif) >> 4;
	
}

double Cache::hitratio(){

	if(hit+miss != 0 ){
		return (double) hit / (double) (hit + miss);
	}else{return 0.;}

}