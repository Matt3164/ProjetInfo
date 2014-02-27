#include "DoubleRef.h"
#include "DoublePtr.h"
using namespace std;

DoubleRef ::DoubleRef (Double & other)
: R(&other)
{
}

DoubleRef DoubleRef::operator=(const Double & other)
{
	cout << "Appel de = DoubleRef" <<endl;
	return *(Double *) R=other.d;
}

DoubleRef:: operator Double() const
{
	cout << "Appel de operateur cast DoubleRef" <<endl;
	return *R;
}








