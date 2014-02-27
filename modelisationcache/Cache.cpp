#include"Cache.h"
#include "CacheLine.h"
#include <iostream>



Cache::Cache(){

	hit = 0;
    miss = 0;
    
    cache = new CacheLine[5];

}

double Cache::get(double * p){
    
    if (lineIndex(p)) {
        return *p;
    }else{
        int i = 0;
        while (cache[i].valid) {
            i++;
        }
        cache[i].load(p);
    }
	
	return *p;
}

void Cache::set(double * p, double value){

    if (lineIndex(p) < 99) {
        *p = value;
    }else{
        int i = 0;
        while (cache[i].valid) {
            i++;
        }
        cache[i].load(p);
        *p = value;
    }
}


int Cache::lineIndex(double * p){

	int index = 0;
	bool update = false;

	for(int i = 0; i < 5; i++){
		if( (cache[i].tag(p) == cache[i].itag(cache[i].xtag)) & cache[i].valid){
			index = i;
		update = true;
		hit++;
		}
	}

	if(!update){
		std::cout << "Il n'est pas dans le cache " << std::endl;
		miss++;
        index = 100;
	}
	
	return index;
}

double Cache::hitratio(){

	if(hit+miss != 0 ){
		return (double) hit / (double) (hit + miss);
	}else{return 0.;}

}