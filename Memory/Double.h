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
    friend ostream& operator<<(ostream& flux, const Double & other);// Op�rateur externe permettant d'afficher le Double sur un flux ostream
    friend Double operator*( const Double & a, const Double & b);

	public:
	Double();//Constructeur sans argument
	Double(double other); //Constructeur prenant un double en argument
	Double( Double const & other);// Constructeur de copie
	Double & operator=(const Double & other); // Op�rateur d'affectation
	Double & operator+=( Double const & other); // Op�rateur d'affectation additionneur
	Double operator*=(const Double & other);// Op�rateur de multiplication
	bool operator==(const Double & other); // Op�rateur de comparaison


	private:
	double d;
};
#endif
