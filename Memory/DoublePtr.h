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
	Double& operator*(void) const; // Surcharge opérateur affectation sur Pointeur
	Double const & operator[](int i) const ; // Surcharge opérateur d'accès 
	operator Double*(void) const;
	DoublePtr& operator++(); // Surcharge opérateur d'incrémentation sur pointeur - post
	DoublePtr operator++(int); // Surcharge opérateur d'incrémentation sur pointeur - pre

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
	//DoubleRef operator*(void); // Retourne une référence
	//DoubleRef operator[](int i); // Surcharge opérateur d'accès 