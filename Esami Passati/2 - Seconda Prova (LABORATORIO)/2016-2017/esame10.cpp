#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <cmath>
#include <sstream>
#define DEF 100
using namespace std;

class A{
	
	private:
		double x;
	
	public:
		A(double _x){ x = _x; }
		double getX(){ return x; }
		bool grande(){ return ((x>0.5) ? true : false);	}
		/*
		string toString(){
			stringstream s;
			s << x;
			return "x = "+s.str();
		}
		*/
		virtual double calcola() = 0;
		virtual ostream &put(ostream &os){
			return os << "x = " << x;
		}
};

ostream &operator <<(ostream &left,A &obj){
	return obj.put(left);
}

class B : public A{
	
	private:
		double y;
	
	public:
		B(double _x,double _y) : A(_x){ y = _y; }
		double calcola(double m){ return pow((getX()+m),y); }
		/*
		string toString(){
			stringstream s;
			s << y;
			return A::toString()+" y = "+s.str();
		}
		*/
		ostream &put(ostream &os){
			return A::put(os) << " y = " << y;
		}
};

class C : public B{
	
	private:
		double z;
	
	public:
		C(double _x,double _y,double _z) : B(_x,_y){ z = _z; }
		double calcola(){ return pow(getX(),z); }
		/*
		string toString(){
			stringstream s;
			s << z;
			return  B::toString()+" z = "+s.str();
		}
		*/
		ostream &put(ostream &os){
			return B::put(os) << " z = " << z;
		}
};

class D : public A{
	
	private:
		double w;
	
	public:
		D(double _x,double _w) : A(_x){ w = _w; }
		bool grande(){ return ((getX()>(0.5-w)) ? true : false); }
		double calcola(){ return getX()*w; }
		/*
		string toString(){
			stringstream s;
			s << w;
			return  A::toString()+" w = "+s.str();
		}
		*/
		ostream &put(ostream &os){
			return A::put(os) << " w = " << w;
		}
};

int main(){
	
	srand(1987234111);
	A * vett[DEF];
	double max = 0;
	int big = 0;
	double somma = 0;
	for(int i=0;i<DEF;i++){
		double a = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX));
		double b = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX));
		if(rand()%2 == 1){
			double c = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX));
			vett[i] = new C(a, b, c);
		}else vett[i] = new D(a, b);
		
		if(max<vett[i]->calcola())
			max = vett[i]->calcola();
			
		if(typeid(* vett[i]) == typeid(C) && ((B *)vett[i])->grande())
			big++;
		if(typeid(* vett[i]) == typeid(D) && ((D *)vett[i])->grande())
			big++;
			
		if(typeid(* vett[i]) == typeid(C))
			somma += ((B *)vett[i])->calcola(vett[i]->calcola());
		
		/*
		if(typeid(* vett[i]) == typeid(C))
			cout << ((C *)vett[i])->toString() << endl;
		if(typeid(* vett[i]) == typeid(D))
			cout << ((D *)vett[i])->toString() << endl;
		*/
		cout << *vett[i] << endl;
	}
	
	cout << "Big: " << big << " Max: " << max << " Somma: " << somma;
	 system("PAUSE");
	return 0;
}
