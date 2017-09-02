#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <typeinfo>
#define DEF 60
using namespace std;

class A{
	
	private:
		bool a;
		bool b;
		bool c;
	
	public:
		A(int *_x){
			a = ((_x[0])%2 == 0) ? true : false;
			b = ((_x[1])%2 == 0) ? true : false;
			c = ((_x[2])%2 == 0) ? true : false;
		}
		bool getA(){ return a; }
		bool getB(){ return b; }
		bool getC(){ return c; }
		bool andF(){ return (a && b && c); }
		/*
		string toString(){
			stringstream s;
			s << a<< " " << b << " " << " " << c;
			return s.str();
		}*/
		virtual ostream &put(ostream &os){
			return os << a<< " " << b << " " << " " << c;
		}
		virtual bool calcola() = 0;
};

ostream &operator << (ostream &left, A &obj){
	return obj.put(left);
}

class B : public A{
	
	public:
		B(int *_x) : A(_x){}
		int valenza(){
			int v = 0;
			if(getA()) v++;
			if(getB()) v++;
			if(getC()) v++;
			return v;
		}
		bool calcola(){	return (getA()&&getB()); }
};

class C : public A{
	
	private:
		bool d;
	
	public:
		C(int *_x) : A(_x){ d = (((_x[3]%2) == 0) ? true : false); }
		bool andF(){ return (andF()&&d); }
		bool calcola(){	return (getC()||d); }
		/*
		string toString(){
			stringstream s;
			s << A::toString() << " " << d;
			return s.str();
		}
		*/
		ostream &put(ostream &os){
			return A::put(os) << " " << d;
		}
};

int main(){
	
	srand(1777555444);
	A * vett[DEF];
	int p[4];
	int sommaV = 0;
	int sommaT = 0;	
	for(int i=0;i<DEF;i++){
		for(int j=0;j<4;j++)
			p[j] = (int)(rand()%100+1);
		
		if(rand()%2 == 1) vett[i] = new B(p);
		else vett[i] = new C(p);
		
		if(typeid(*vett[i]) == typeid(B))
			sommaV += ((B *)vett[i])->valenza();
			
		if(vett[i]->calcola())
			sommaT++;
		
		cout << *vett[i] << endl;
	}
	
	for(int i=0;i<DEF;i++)
		if(typeid(*vett[i]) == typeid(C) && vett[i]->andF() == true)
			cout << i << ",";
	
	cout << endl << "SommaV: " << sommaV << " SommaT: " << sommaT;
	system("PAUSE");
	return 0;
}
