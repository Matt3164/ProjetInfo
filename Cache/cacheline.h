

#ifndef CACHELINE_H
#define CACHELINE_H

class CacheLine {

public:

    CacheLine();
	int tag(double* p);
    int itag(int p);
	int decalage(double* p);
	void load(double * p);

//private:
	bool valid;
    int xtag;
	double* tabligne;
};
#endif
