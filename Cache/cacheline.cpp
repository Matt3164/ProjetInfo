#include"CacheLine.h"
#include <iostream>
#include<math.h>
#define w 4


CacheLine::CacheLine()
{
	int taille =(int) pow(2.0,w);
	tabligne = new double[taille];

}


void CacheLine::load(double * p)
{
	double taille=pow(2.0,4);

	for(int i=0; i< taille;i++)
	{
		tabligne[i]=*(p+i);
	}
    
    xtag = (intptr_t) p;
    
    valid = true;
}


int CacheLine::tag(double* p){

	return (((intptr_t )p >> 9)<< 9);
}

int CacheLine::itag(int p){
    
	return (( p >> 9)<<9);
}

int CacheLine::decalage(double* p){

	int a = ((intptr_t) p - xtag);
    return a / 8.;
}