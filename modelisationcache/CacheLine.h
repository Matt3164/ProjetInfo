#include <cstdint>

#ifndef CACHELINE_H
#define CACHELINE_H

class CacheLine {

public:

    CacheLine();
	intptr_t tag(double* p);
    intptr_t itag(intptr_t p);
	int decalage(double* p);
	void load(double * p);
    double getLine(double * p);
    void setLine(double * p, double value);

//private:
	bool valid;
    intptr_t xtag;
	double* tabligne;
};
#endif
