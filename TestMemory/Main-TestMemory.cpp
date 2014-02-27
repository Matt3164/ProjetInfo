#include "../Memory/Double.h"
#include "../Memory/DoublePtr.h"
#include "../Memory/DoubleRef.h"
#include "../modelisationcache/Cache.h"

static Cache moncache;
Double fonction(const DoublePtr p);
Double fonction2(DoublePtr p);


int main ()

{

	double double1=6.25;
	double double2=5.0;
	double double3=10.0;

	cout <<"Test de la classe Double"<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << "Test du constructeur sans argument, creation et affichage de l'objet cree \n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double Double1;
	cout << "Double1=" << Double1 <<"\n"<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";


	cout << "Test du constructeur prenant un double natif: " << double2 << " en argument \n"; 
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double Double2(double2);
	Double Double3(double3);
	cout << "Double2=" << Double2 <<"\n"<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";


	cout << "Test du constructeur de copie avec "<<Double2<<" en argument" << "\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double Double4(Double2);
	cout << "Double3=" << Double4<<"\n"<< "\n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << "Test de l'operateur d'affectation: Double2=" << Double2 << " prend la valeur de Double3=" << Double3<<"  \n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double2=Double3;
	cout << "Double2 vaut maintenant " << Double2<<" \n"<<" \n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << "Test de l'operateur d'affectation additionneur, ajout de Double2=" <<Double2<< " a Double3 ="<< Double3<< "\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double3+=Double2;
	cout << "Double3="<<Double3<<" \n";;
	cout <<" \n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << "Test de l'operateur d'affectation multiplicateur, multiplication de Double2=" <<Double2<< " par Double3="<< Double3<< "\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double2*=Double3;
	cout << "Double3="<<Double2<<" \n";;
	cout <<" \n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << "Test de l'operateur de multiplication \n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	cout << "(Double3=" << Double3 << ")*("<< "Double2=" <<Double2 << ")="<< Double3*Double2<<"\n"<<" \n";;
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << "Test de l'operateur de comparaison \n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	cout << Double3<< "=="<< Double2 << " ? ";
	cout << (Double3==Double2) << " \n"<<" \n";
	Double Double5(20);
	cout << Double3<< "=="<< Double5 << " ? ";
	cout << (Double3==Double5) << " \n"<<" \n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << "Test de l'operateur flux" << "\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	cout << Double3;
	cout <<" \n"<<" \n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	

	////////////Classe DoublePtr /////////////

	cout << "Test de la classe Pointeur"<<"\n"<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << "Test du constructeur prenant un pointeur sur Double en argument" << "\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double * x=new Double[100];
	x[0]=5;
	x[1]=10;
	DoublePtr ptest1(x);
	cout << ptest1[0]<< "\n";
	cout << ptest1[1]<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	
	
	cout << "Test du constructeur de copie par defaut" <<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	cout << "DoublePtr ptest2(ptest1)" <<"\n";
	DoublePtr ptest2(ptest1);
	*ptest2;
	cout << ptest2[0]<< "\n";
	cout << ptest2[1]<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	cout << "Test de l'operateur d'affectation par defaut" <<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	DoublePtr ptest3=new Double[2];
	Double u1(1);
	Double u2(2);
	*ptest3=u1;
	*ptest3=u2;
	cout << "avant ptest3[0] : " << ptest3[0]<< "\n"<<endl;;
	cout << "avant ptest3[1]: " <<ptest3[1]<<"\n"<<endl;;
	cout << "ptest1[0]: " << ptest1[0]<< "\n";
	cout << "ptest1[1]: " <<ptest1[1]<<"\n";
	cout << "ptest3=ptest1" <<endl;
	ptest3=ptest1;
	cout << "apres ptest3[0]: "<<ptest3[0]<< "\n";
	cout << "apres ptest3[1]: "<<ptest3[1]<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";

	
	cout <<"Test de l'operateur []" <<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	 DoublePtr ptest=new Double[2];
	*ptest=Double1;
	*(ptest+1)=Double2;
	cout << ptest[0]<<"\n";
	cout << ptest[1]<<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";


	cout << "Test de l'operateur ++" <<"\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	cout << "avant : " << ptest1[0]<< "\n";
	++ptest1;
	cout << "apres : " << ptest1[0]<< "\n";

	cout << "avant : " << ptest3[0] << "\n";
	ptest3++;
	cout << "apres : " << ptest3[0] << "\n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	

	cout<<"Test de l'operateur de dereferencement \n";
	cout << "------------------------------------------------------------------------------------ \n \n";
	cout<< "ptest : " << *ptest << "\n";
	cout<< "ptest : " << *(++ptest) << "\n";
	cout<< "ptest : " << *(ptest) << "\n";
	

	cout << "Question 25" <<endl;
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double a(1);
	Double b(5);
	DoublePtr p1=  new  Double[100];
	*p1=7;
	*p1;
	cout << "valeur de *p1 : " << *p1 <<endl;
	delete [] p1;
	cout << "------------------------------------------------------------------------------------ \n \n";


	cout << "Question 26" <<endl;
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double d;
	DoublePtr p2=&d;
	p2++;
	cout << "------------------------------------------------------------------------------------ \n \n";


	cout << "Question 27" <<endl<<endl;
	cout << "------------------------------------------------------------------------------------ \n \n";
	DoublePtr p3 = new Double[2];
	Double sum;
	for(int i=0; i<100; i++)
		sum+=p3[i];
	delete[] p3;
	cout << "------------------------------------------------------------------------------------ \n \n";
	


	cout << "Question 28" << endl;
	cout << "------------------------------------------------------------------------------------ \n \n";
	Double d4;
	DoubleRef p4= d4;
	p4 = 5.4;
	//cout << p4 <<"\n";

	const DoublePtr p5 = new Double[5];

	fonction(p3);
	cout << "Test : " << endl;
	*p3 = 1;
	*(p3+1)=2.;
	*(p3+2)=3.;
	cout << "------------------------------------------------------------------------------------ \n \n";

	fonction2(p3);
	cout << "Test 1 : " << p3[0] << endl;
	cout << "Test 2 : " << p3[1] << endl;
	//cout << "Test 3 : " << p4[0] << endl;
	cout << "Test 4 : " << p5[1] << endl;
	

//	 Test Calcul Hit Ratio
//	Double ci=9;
//	Double & abc=ci;
//	DoubleRef xxx(ci);
//	cout << xxx;

	return 0;

}

Double fonction(const DoublePtr p){
*p;
return Double(2.);}

Double fonction2(DoublePtr p){
*p = 7.;
return Double(5);}