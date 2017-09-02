#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#define DEF 100

using namespace std;

class A{
	
	protected:
		int x;
	
	public:
		A(int _x){ x = _x; }
		virtual int f() = 0;
		
};

class D{
	
	private:
		double z;
		
	public:
		D(double _z){ z = _z; }
		double getZ(){ return z; }
};

class B : public A, public D{
	
	protected:
		int y = 0;
		
	private:
		D * d;
		
	public:
		B(int _x,int _y,double _z) : A(_x), D(_z){ d = new D(_z); y = _y; }
		int f(){ return x*x; }
		int f(D * p){ return p->getZ()+d->getZ(); }
};

class C : public B{
	
	public:
	C(int _x,int _y,double _z) : B(_x,_y,_z){}
	int f(){ return 7*y; }
	
};

int main(){
	
	srand(6353433);
	A * vett[DEF];
	
	int somma = 0;
	int somma2 = 0;
	int istant = 0;
	for(int i=0;i<DEF;i++){
		int x = rand()%10;
		int y = rand()%100;
		int z = rand()%30;		
		if(rand()%2 == 1) vett[i] = new B(x,y,z);
		else vett[i] = new C(x,y,z);
		
		D * obj = new D(rand()%47);
		somma2 += ((B *)vett[i])->f(obj);
		delete obj;
		
		if(typeid(* vett[i]) == typeid(B))
			istant++;
		
		somma += vett[i]->f();
	} 
	
	cout << "Somma: " << somma << " Somma2: " << somma2 << " Istant: " << istant;
	system("PAUSE");
	return 0;
}
