#ifdef MATRICES_EXPORTS
#define ExportedBy __declspec(dllexport)
#else
#define ExportedBy __declspec(dllimport)
#endif

#ifndef _MATRIX_H
#define _MATRIX_H
#include"MatrixImpl.h"
#include "Double.h"
#include "DoubleRef.h"

class ExportedBy Matrix{
	ExportedBy friend Matrix operator*(const Matrix & A, const Matrix & B); // Operateur * externe pour la classe Matrix

	public:
	Matrix(); // Constructeur sans argument
	~Matrix(); // Destructeur 
	Matrix(const Matrix & other);//Constructeur de copie
	DoubleRef operator() (unsigned int i,unsigned int j);
	Double  operator() (unsigned int i,unsigned int j) const;

	private:
	MatrixImpl M; // Objet de type MatrixImpl en donnée membre
	Matrix(MatrixImpl * N);// Constructeur prenant en argument un pointeur sur un objet MatrixImpl
};
#endif
