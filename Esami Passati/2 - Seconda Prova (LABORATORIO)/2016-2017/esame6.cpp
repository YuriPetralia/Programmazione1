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
		virtual int f(int _x) = 0;
		int getX(){ return x; }
};

class E{
	
	private:
		float coeff;
		
	public:
		E(double _c){ coeff = _c; }
		double getCoeff(){ return coeff; }
		int somma(int * v, int len){
			int s = 0;
			for(int i=0;i<len;i++)
				s += v[i];
			return s;
		}
};

class B : public A{
	
	private:
		E * e;
		
	public:
		B(int _x, double _d) : A(_x){ e = new E(_d); }
		float getCoeff(){ return e->getCoeff(); }
		E * getE(){ return e; }
};

class C : public B{

	private:
		int * z;

	public:
		C(int _x,double _d,int _z) : B(_x,_d){
			z = new int[_x];
			for(int i=0;i<_x;i++)
				z[i] = 2*_z+i+1;
		}
		int f(int _x){ return getE()->somma(z,getX()); }
		int ultimo(){ return z[getX()-1]; }
};

class D : public B{

	public:
		D(int _x,double _d) : B(_x,_d){}
		int f(int _x){ return _x+getCoeff()+100; }
};

int main(){
	
	srand(7645544);
	A[] vett = new A[100];
fo(int i=0; i<vett.length; i++;1
int x : r.nextlnt(10)+ 1;
doubled : r.nextDoubleQ* 40;
int z: r.nextlnt(30);
if (r.nextlnt(2)==1) vett[i] : ner^Cr (x,d,z);
else vett[i] : rrew D(x,d);
It
