#ifdef CACHE_EXPORTS
#define ExportedBy __declspec(dllexport)
#else
#define ExportedBy __declspec(dllimport)
#endif

#include"cacheline.h"
#ifndef CACHE_H
#define CACHE_H

class ExportedBy Cache {

public:
	Cache();
	double get(double * p);
	void set(double * p, double value);
	int lineIndex(double * p);
	double hitratio();

//private:

	int miss;
	int hit;
	int nombredelignes;
	CacheLine* cache;

};

#endif