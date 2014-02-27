#ifdef MEMORY_EXPORTS
#define ExportedBy __declspec(dllexport)
#else
#define ExportedBy __declspec(dllimport)
#endif

#ifndef DOUBLE_H
#define DOUBLE_H

#include<iostream>

using namespace std;

class Double {

	friend class DoubleRef;
    friend ostream& operator<<(ostream& flux, const Double & other);// Opérateur externe permettant d'afficher le Double sur un flux ostream
    friend Double operator*( const Double & a, const Double & b);

	public:
	Double();//Constructeur sans argument
	Double(double other); //Constructeur prenant un double en argument
	Double( Double const & other);// Constructeur de copie
	Double & operator=(const Double & other); // Opérateur d'affectation
	Double & operator+=( Double const & other); // Opérateur d'affectation additionneur
	Double operator*=(const Double & other);// Opérateur de multiplication
	bool operator==(const Double & other); // Opérateur de comparaison


	private:
	double d;
};
#endif
