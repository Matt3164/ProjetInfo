#include"Matrix.h"
#include "../Memory/Double.h"
#include "../Memory/DoubleRef.h"

Matrix::Matrix()
{ 
}

Matrix :: Matrix(MatrixImpl* N)
: M(*N)
{	
	delete N;
}

Matrix::Matrix(const Matrix & other)
{
	M=other.M;
}

Matrix  operator*(const Matrix & A, const Matrix & B){
	Matrix out;
	out.M=(A.M)*(B.M);
	return out;
}

DoubleRef  Matrix:: operator() (unsigned int i,unsigned int j){
	return M(i,j);
}

Double Matrix:: operator() (unsigned int i,unsigned int j) const{
	return M(i,j);
}

Matrix :: ~Matrix ()
{ 
}



