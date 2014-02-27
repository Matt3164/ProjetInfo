#ifndef MATRIXIMPL_H
#define MATRIXIMPL_H

#include "../Memory/Double.h"
#include "../Memory/DoublePtr.h"
#include "../Memory/DoubleRef.h"

class MatrixImpl {

	friend MatrixImpl operator*(const MatrixImpl & A, const MatrixImpl & B);// Opérateur externe de multiplication
	friend class Matrix;

	public:
	MatrixImpl(); // Constructeur sans argument
	 ~MatrixImpl(); // Destructeur qui appelle delete []
	MatrixImpl(const MatrixImpl & other); // Constructeur de copie
	MatrixImpl & operator=(const MatrixImpl & other); // Opérateur d'affectation
	Double const & operator() (unsigned int i, unsigned int j) const; // Opérateur d'accès en lecture seule aux données de la matrice
	DoubleRef operator() (unsigned int i, unsigned int j) ; // Opérateur d'accès pour modification
	
	private:
	unsigned int taille; // Taille de la matrice
	DoublePtr mat;
};


// Partie I - Question 3 
// Il est nécessaire de déclarer et d'implémenter les trois méthodes spéciales (destructeur, constructeur de copie, opérateur d'affectation) de MatrixImpl.
// En effet, dans la classe MatrixImpl, il y a un pointeur membre vers un bloc de mémoire situé dans le tas de taille variable
// et le cycle de vie de ce bloc est lié au cycle de vie de l'objet qui le pointe. 
// On doit construire un destructeur qui appelle delete [] car le constructeur a fait un new []. 
// On doit construire un constructeur de copie qui duplique la zone mémoire sous-jacente dans le Tas. 
// En effet, avec le constructeur de copie par défaut, la même zone-mémoire, pointé par deux objets, est désalloué deux fois.

#endif