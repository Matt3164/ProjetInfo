#include"Double.h"
#include "DoublePtr.h"



Double::Double(){
}

Double::Double(double other)
: d(other)
{}

Double::Double( const Double & other)
{
	d=other.d;
}

Double & Double::operator=(const Double & other){
	cout<< "utilisation = Double" <<endl;
	if (this!=&other) {
		d=other.d;
	return *this;
	}
}

Double & Double::operator+=( const Double  & other)
{
	d+=other.d;
	return *this;
}

Double Double::operator*=(const Double & other){
	d*=other.d;
	return *this;
}

bool Double:: operator==(const Double & other){
	return d==other.d;
}

ostream& operator<<(ostream& flux, const Double& other){
	flux<< other.d;
	return(flux);
}

Double operator*( const Double & a, const Double & b){

	Double resultat=a;
	return resultat*=b;
}


