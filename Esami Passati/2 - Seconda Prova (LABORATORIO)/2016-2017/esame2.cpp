#include <iostream>
#include <math.h>
#include <typeinfo>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>
#define DEF 10
#define NUM 50
using namespace std;

class A{

	private:
		float * x;

	public:
		A(float _x){
			x = new float[DEF];
			x[0] = _x;
			for(int i=1;i<DEF;i++)
				x[i] = sin(100*x[i-1]);
		}
		virtual float f() = 0;
		float * getX(){ return x; }
		/*
		string toString(){
			string str;
			stringstream tmp;
			for(int i=0;i<DEF;i++)
				tmp << setprecision(2) << getX()[i] << " ";
			str = tmp.str();	
			return str;
		}*/
		virtual ostream &put(ostream &os){
			string str;
			stringstream tmp;
			for(int i=0;i<DEF;i++)
				tmp << setprecision(2) << getX()[i] << " ";
			str = tmp.str();	
			return os << "class " << typeid(*this).name()[1] << " [" << str << "]";
		}
};

ostream &operator <<(ostream &left,A &obj){
	return obj.put(left);
}

class B : public A{

	public:
		B(float _x) : A(_x){}
		float f(){
			float max = 0;
			for(int i=0;i<DEF;i++)
				if(max<getX()[i])
					max = getX()[i];
			return max;
		}
		/*
		string toString(){
			stringstream tmp;
			tmp << " f() = " << setprecision(2) << f();
			return "Class B [ " + A::toString() + "]" + tmp.str();
		}*/
		ostream &put(ostream &os){
			return A::put(os) << " f() = " << setprecision(2) << f();
		}
		
};

class C : public A{

	public:
		C(float _x) : A(_x){}
		float f(){
			float m = 0;
			for(int i=0;i<DEF;i++)
				m += getX()[i];
			return m/DEF;
		}
		int gte(float thr){
			int n = 0;
			for(int i=0;i<DEF;i++)
				if(thr<getX()[i]) n++;
			return n;
		}
		/*
		string toString(){
			stringstream tmp;
			tmp << " f() = " << f() << " gte(.7) = " << gte(.7);
			return "Class C [ " + A::toString() + "]" + tmp.str();
		}*/
		ostream &put(ostream &os){
			return A::put(os) << "]" << " f() = " << f() << " gte(.7) = " << gte(.7);
		}
};

class D{
 
	private:
		A * a;
		B * b;
		C * c;

	public:
		D(float seed){
			if(seed > 0.5)
				a = new B(seed);
			else
				a = new C(seed);	
			b = new B(seed/2);
			c = new C(seed/3);
		}
		float m(){
			float m = 0;
			for(int i=0;i<DEF;i+=2){
				if(typeid(* a) == typeid(B))
					m += max(((A *)a)->getX()[i],((A *)b)->getX()[i]);
				if(typeid(* a) == typeid(C))
					m += max(((A *)a)->getX()[i],((A *)c)->getX()[i]);
			}
			return m;
		}
		float h(float thr){
			float v = c->f()/b->f();
			if(typeid(* a) == typeid(C))
				v *= ((C *)a)->gte(thr);
			return v;
		}
		/*
		string toString(){
			stringstream tmp;
			tmp << "h(.7) = " << h(.7) << " m() = " << m() << endl << endl;
			return ((typeid(* a) == typeid(B)) ? ((B *)a)->toString() : ((C *)a)->toString()) + "\n" + b->toString() + "\n" + c->toString() + "\n" + tmp.str();
		}
		*/
		virtual ostream &put(ostream &os){
			return os << *a << endl << *b << endl << *c << endl << "h(.7) = " << h(.7) << " m() = " << m() << endl << endl;
		}
};

ostream &operator <<(ostream &left,D &obj){
	return obj.put(left);
}

int main(){

	srand(347537586);
	D * vett[50];
	float media = 0;
	for(int i=0;i<26;i++){
		vett[i] = new D(rand()/(float)RAND_MAX);
		cout << i << ")" << endl << *vett[i];
		media += vett[i]->h(0.7);
	}

	cout << "\nMedia: " << media/NUM << " vett[4]->m()+vett[5]->m() = " << vett[4]->m()+vett[5]->m();

    system ("PAUSE") ;
	return 0;
}
