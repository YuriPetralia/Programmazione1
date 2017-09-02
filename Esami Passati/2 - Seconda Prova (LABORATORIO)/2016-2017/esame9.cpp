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
		virtual int * f() = 0;
		
};

class E{
	
	private:
		float coeff;
	
	public:
		E(double _c){ coeff = _c; }
		double getCoeff(){ return coeff; }
	
};

class B : public A{
	
	private:
		int w;
		E * e;
	
	public:
		B(int _x,int _w,double _d) : A(_x){ e = new E(_d); w = _w; }
		float alfa(){ return w+e->getCoeff(); }
		
};

class C : public A{
	
	private:
		int z;
		
	public:
		C(int _x,int _z) : A(_x){ z = _z; }
		int * f(){
			int * arr = new int[100];
			srand(22446688);
			for(int i=0;i<100;i++)
				arr[i] = z+rand()%1000;
			return arr;
		}
	
};

class D : public B{
	
	public:
		D(int _x,int _w,double _d) : B(_x,_w,_d){}
		int * f(){
			int * arr = new int[100];
			srand(22446688);
			for(int i=0;i<100;i++)
				arr[i] = rand()%400;
				
			for(int i=0;i<100;i++){
				for(int j=0;j<100;j++){
					if(arr[i]<arr[j]){
						int t = arr[j];
						arr[j] = arr[i];
						arr[i] = t;
					}
				}
			}

			return arr;
		}
		
};


int main(){
	
	srand(2245544);
	A * vett[DEF];
	double max = 0;
	int somma = 0;
	for(int i=0;i<DEF;i++){
		int x = rand()%10;
		int y = rand()%100;
		double d = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/40));
		if(rand()%2 == 1) vett[i] = new C(x,y);
		else vett[i] = new D(x,y,d);
		
		if(typeid(* vett[i]) == typeid(D) && max<((B *)vett[i])->alfa())
			max = ((B *)vett[i])->alfa();
	}
	
	for(int i=0;i<DEF;i++)
		somma += vett[i]->f()[25];
	
	cout << "Somma: " << somma << " Max: " << max;
	system("PAUSE");
	return 0;
}
