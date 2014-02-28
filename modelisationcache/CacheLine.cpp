#include"CacheLine.h"
#include <iostream>
#include<math.h>
#define w 4
#define n 5


CacheLine::CacheLine()
{
	int taille = pow(2., w) / 8.;
	tabligne = new double[taille];

}


void CacheLine::load(double * p)
{
	double taille= pow(2., w) / 8.;

	for(int i=0; i< taille;i++)
	{
		tabligne[i]=*(p+i);
	}
    
    xtag = (intptr_t) p;
    
    valid = true;
}


intptr_t CacheLine::tag(double* p){

	return (((intptr_t )p >> w)<< w);

}

intptr_t CacheLine::itag(intptr_t p){
    
	return (( p >> w)<< w);
    
}


int CacheLine::decalage(double* p){
    
	return ((intptr_t) p - tag(p)) / 8;
}

double CacheLine::getLine(double * p){
    
    return tabligne[decalage(p)];

}

void CacheLine::setLine(double * p, double value){
    
    tabligne[decalage(p)] = value;
    
}
