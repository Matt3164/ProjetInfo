#ifdef MEMORY_EXPORTS
#define ExportedBy __declspec(dllexport)
#else
#define ExportedBy __declspec(dllimport)
#endif

#ifndef DOUBLEPTR_H
#define DOUBLEPTR_H

#include"Double.h"
#include "Cache.h"

class DoublePtr {

	friend class DoubleRef;

	public:
	DoublePtr();
	DoublePtr(Double * other); // Constructeur prenant un pointeur sur Double en argument
	Double& operator*(void) const; // Surcharge op�rateur affectation sur Pointeur
	Double const & operator[](int i) const ; // Surcharge op�rateur d'acc�s 
	operator Double*(void) const;
	DoublePtr& operator++(); // Surcharge op�rateur d'incr�mentation sur pointeur - post
	DoublePtr operator++(int); // Surcharge op�rateur d'incr�mentation sur pointeur - pre

	private:
	Double* P;

};
#endif


	//~DoublePtr(); // Destructeur 
	//DoublePtr(const DoublePtr & other);
	//DoublePtr & operator=(const DoublePtr & other);
	/*unsigned int size;
	static Cache * cac;*/
	//static void setcache(Cache * C);
	//DoubleRef operator*(void); // Retourne une r�f�rence
	//DoubleRef operator[](int i); // Surcharge op�rateur d'acc�s 