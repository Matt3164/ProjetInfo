#ifdef MEMORY_EXPORTS
#define ExportedBy __declspec(dllexport)
#else
#define ExportedBy __declspec(dllimport)
#endif

#ifndef DOUBLEREF_H
#define DOUBLEREF_H

#include"DoublePtr.h"

class ExportedBy DoubleRef {
	public:
	DoubleRef(Double & other);
	DoubleRef operator=(const Double & other);
    operator Double() const;
	
	private:
	DoublePtr R;
};

#endif



