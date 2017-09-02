#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#define DEF 100
using namespace std;

class A{
	
	private:
		int x;
		
	public:
		A(int _x){ x = _x; }  
		virtual int f() = 0;
		
};

class E{
	
	private:
		float coeff;
	
	public:
		E(double _c){ coeff = _c; }
		double getCoeff(){ return (double)coeff; }
		
};

class B : public A{
	
	private:
		int w;
		E * e;
		
	protected:
		static int totaleC;
	
	public:
		B(int _x,int _w,double _d) : A(_x){	e = new E(_d); w = _w; }
		int getW(){ return w; }
		float getCoeff(){ return (float)e->getCoeff(); }
		static int getTotaleC(){ return totaleC; }
	
};

int B::totaleC = 0;

class C : public B{
	
	private:
		int z;
	
	public:
		C(int _x,int _w,double _d, int _z) : B(_x,_w,_d){ z = _z; this->totaleC++;  }
		int f(){ return getW()+z; }
		
};

class D : public B{
	
	public:
		D(int _x,int _w,double _d) : B(_x,_w,_d){}
		int f(){ return getW()*getW(); }
		
};

int main(){
	
	srand(1772882);
	B * vett[DEF];
	int somma = 0;
	int istantD = 0;
	double max = 0;
	for(int i=0;i<DEF;i++){
		int x = rand()%10;
		int w = rand()%100;
		double d = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/40));
		int z = rand()%30;
		if(rand()%2 == 1) vett[i] = new C(x,w,d,z);
		else vett[i] = new D(x,w,d);

		somma += vett[i]->f();

		if(max<((B *)vett[i])->getCoeff())
			max = ((B *)vett[i])->getCoeff();
		
		if(typeid(* vett[i]) == typeid(D))
			istantD++;
	}
	
	cout << "Somma: " << somma << " Coeff: " << (double)max << " IstantC: " << B::getTotaleC() << " IstantD: " << istantD;
	system("PAUSE");
	return 0;
}
