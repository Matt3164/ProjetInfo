
#include"MatrixImpl.h"
#include "Double.h"
#include "DoublePtr.h"
#include "DoubleRef.h"
#include <iostream>
#define SIZE 2

MatrixImpl :: MatrixImpl ()
{
	taille =SIZE;
	mat = new Double[taille*taille];
};

MatrixImpl :: ~MatrixImpl ()
{ 
	delete [] mat;
}

MatrixImpl::MatrixImpl(const MatrixImpl & other)
:taille(other.taille)
{
	mat=new Double[taille*taille];
	for(int i=0; i<taille*taille;i++) 
		{	
				*(mat+i)=other.mat[i];
		}
}

MatrixImpl & MatrixImpl::operator=( const MatrixImpl & other)
{
	if (this!=&other) 
		{
		if(other.taille!=taille)
			{ 	
				std::cout << "les tailles des deux matrices ne sont pas compatibles \n";
			}

		for(int i=0; i<taille;i++) 
		{
			for (int j=0; j<taille;j++)
			{
				*(mat+i+taille*j)=other.mat[i+taille*j];
			}
		}

		}
	return *this;
}

Double const & MatrixImpl::operator() (unsigned int i, unsigned int j) const{
	//const DoublePtr * test=(*this).mat;
	return mat[i+j*taille];
}

DoubleRef MatrixImpl::operator() (unsigned int i, unsigned int j) {
	return *(mat+i+j*taille);
}

MatrixImpl operator*( const MatrixImpl & A,  const MatrixImpl & B)
{
	MatrixImpl out;
	if (A.taille==B.taille)
	{
	
	out.taille=A.taille;
	for (int i=0; i<A.taille;i++)
	{
		for(int j=0; j<A.taille; j++)
		{	
			//out(i,j)=0;
			Double sum=0;
			for(int k=0; k<A.taille; k++) 
			{ 
			sum+=A(i,k)*B(k,j);
			}
			cout <<"out"<<i<<j<<endl;
			out(i,j)=sum;
		}
	}
	}else{

		std::cout << "Il y a eu un problème \n";
		
		for(int j=0; j<A.taille; j++)
		{	
			for(int k=0; k<A.taille; k++) 
			{ 
				out(j,k)=0.;
			}
		}
	}

	return out;

}



// Modification du code de l operateur de multiplication 


/*for (k=0; k<n;k++)
{
	for(i=0; i<n;i++)
	{
		r=a[i][k];
		for(j=0; j<n; j++)
			{
				out[i][j]+=r*b[k][i]
			}
	}
}*/









