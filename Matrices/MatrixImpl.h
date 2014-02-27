#ifndef MATRIXIMPL_H
#define MATRIXIMPL_H

#include "../Memory/Double.h"
#include "../Memory/DoublePtr.h"
#include "../Memory/DoubleRef.h"

class MatrixImpl {

	friend MatrixImpl operator*(const MatrixImpl & A, const MatrixImpl & B);// Op�rateur externe de multiplication
	friend class Matrix;

	public:
	MatrixImpl(); // Constructeur sans argument
	 ~MatrixImpl(); // Destructeur qui appelle delete []
	MatrixImpl(const MatrixImpl & other); // Constructeur de copie
	MatrixImpl & operator=(const MatrixImpl & other); // Op�rateur d'affectation
	Double const & operator() (unsigned int i, unsigned int j) const; // Op�rateur d'acc�s en lecture seule aux donn�es de la matrice
	DoubleRef operator() (unsigned int i, unsigned int j) ; // Op�rateur d'acc�s pour modification
	
	private:
	unsigned int taille; // Taille de la matrice
	DoublePtr mat;
};


// Partie I - Question 3 
// Il est n�cessaire de d�clarer et d'impl�menter les trois m�thodes sp�ciales (destructeur, constructeur de copie, op�rateur d'affectation) de MatrixImpl.
// En effet, dans la classe MatrixImpl, il y a un pointeur membre vers un bloc de m�moire situ� dans le tas de taille variable
// et le cycle de vie de ce bloc est li� au cycle de vie de l'objet qui le pointe. 
// On doit construire un destructeur qui appelle delete [] car le constructeur a fait un new []. 
// On doit construire un constructeur de copie qui duplique la zone m�moire sous-jacente dans le Tas. 
// En effet, avec le constructeur de copie par d�faut, la m�me zone-m�moire, point� par deux objets, est d�sallou� deux fois.

#endif