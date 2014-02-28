#include "DoublePtr.h"
#include "Double.h"
#include "../modelisationcache/Cache.h"
extern Cache moncache;

DoublePtr::DoublePtr ()
{	
}

DoublePtr::DoublePtr (Double * other)
{	
	P=other;
}


Double& DoublePtr::operator*(void) const
{
	cout << "Appel de * DoublePtr" <<endl;
    moncache.get(&((*P).d));
    return *P ;
}

//DoubleRef DoublePtr::operator*(void)
//{
//	return DoubleRef(P[0]);
//}

DoublePtr& DoublePtr::operator++(){
	P=(P+1);
	return *this;
}

DoublePtr DoublePtr::operator++(int){
	DoublePtr tmp(*this);
	++(*this);
	return tmp;
}
	
//Double DoublePtr::operator[](int i) const{
//	return Double(*(P + i));
//}

Double const & DoublePtr::operator[](int i) const{
	cout << "Appel de [] DoublePtr" <<endl;
	DoublePtr Ptr(P + i);
	return *Ptr;
}

DoublePtr::operator Double*(void) const
{return P;}


// void DoublePtr::setcache(Cache * C)
//{
//	Cache* cac=C;
//	return;
//}









