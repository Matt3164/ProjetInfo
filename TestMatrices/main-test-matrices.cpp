#include"Matrix.h"
#include<iostream>
using namespace std;
#include"DoublePtr.h"
#include"Double.h"
#define TAILLE 2

void affiche( Matrix const A) {
	for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
		cout << A(i,j) ;
		cout <<" / "<<endl;
							}
		cout << "\n";
		}
}

int main() {

	cout<< "Test du constructeur sans argument"<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << endl;
	cout<<"Test de la classe Matrix"<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	Matrix A;
	Matrix B;

	for (int j=0; j<TAILLE;j++){
		for (int i=0;i<TAILLE;i++){
			if(i==j){
				A(i,i)=2;
				B(i,i)=1;
				}
			if(i!=j){
				A(i,j)=1;
				B(i,j)=2;
				}
	}
	}
	
	cout << "On affiche la matrice 5*5 A" <<endl ;
	cout << "---------------------------------------------------------------- \n \n";
	affiche(A);
	cout <<endl <<endl <<endl;
	
	cout << "On affiche la matrice 5*5 B" <<endl ;
	cout << "---------------------------------------------------------------- \n \n";
	affiche(B);
	cout <<endl <<endl <<endl;

	cout << "On realise le produit A * B" <<endl ;
	cout << "----------------------------------------------------------------- \n \n";
	Matrix C=(A*B);
	affiche(C);
	cout <<endl <<endl <<endl;

	cout<< "Test du constructeur de copie"<<"\n";
	Matrix M1(A);
	Matrix M2(B);
	affiche(M1);
	cout<<"\n";
	affiche(M2);

	/*cout << " Test du produit de deux matrices Matrix ";
	Matrix A, B;
	Matrix C=A*B;
	affiche(C);*/

	return 0;
}