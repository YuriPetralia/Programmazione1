#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <typeinfo>
#define DEF 30

using namespace std;

class A{
	
	private:
		int x;
		
	public:
		A(int _x){ 
			x = _x; 
		}
		int getX(){ 
			return x; 
		}
		//string toString(){ stringstream s; s << "x=" << x; return s.str(); }
		virtual float f(int _q) = 0;
		virtual ostream &put(ostream &os){
			return os << "x=" << x;
		}
};

ostream &operator <<(ostream &left,A &obj){
	return obj.put(left);
}

class D{
	
	private:
		char x;
	
	public:
		D(char _x){ 
			x = _x; 
		}
		char getX(){ 
			return x; 
		}
		//string toString(){ stringstream s; s << "x2=" << x; return s.str(); }
		virtual ostream &put(ostream &os){
			return os << "x2=" << x;
		}
};

class E : public D{
	
	private:
		char y;
		
	public:
		E(char _x,char _y) : D(_x){ 
			y = _y; 
		}
		string coppia(){ 
			stringstream s; 
			s << getX() << y; 
			return s.str(); 
		}
		//string toString(){ stringstream s; s << D::toString() << " y=" << y; return s.str(); }
		ostream &put(ostream &os){		
			return D::put(os) << " y=" << y;
		}
};

ostream &operator <<(ostream &left,D &obj){
	return obj.put(left);
}

class B : public A{
	
	private:
		D * obj;
		
	public:
		B(int _x, char _y, char _z) : A(_x){ 
			obj = new E(_y,_z);  
		}
		float f(int _q){ 
			return getX()+_q; 
		}
		string f(){ 
			stringstream s; 
			s << ((E *)obj)->coppia() << getX(); 
			return s.str(); 
		}
		//string toString(){ stringstream s; s << A::toString() << " " << ((E *)obj)->toString(); return s.str(); }
		ostream &put(ostream &os){
			return A::put(os) << " " << *(E *)obj;
		}
};

class C : public A{
	
	private:
		int * a;
		
	public:
		C(int _p) : A(_p){ 
			srand(_p); 
			a = new int[20]; 
			for(int i=0;i<20;i++) 
				a[i] = rand()%256; 
		}
		float f(int _q){
			float m = 0;
			float c = 0;
			for(int i=0;i<20;i++)
				if(a[i]<_q){
					c++;
					m += i;
				}
			return m/c;
		}
		float f(){ 
			return a[11]; 
		}
		//string toString(){ stringstream s; for(int i=0;i<20;i++) s << a[i] << " "; return A::toString()+" "+s.str(); }
		ostream &put(ostream &os){
			stringstream s; for(int i=0;i<20;i++) s << a[i] << " ";
			return A::put(os) << " " << s.str();
		}
};

int main(){
	
	srand(43253793);
	A * vett[DEF];
	float m = 0;
	float max = 0;
	stringstream s;
	for(int i=0;i<DEF;i++){
		int a = rand()%30;
		char c = (char)('a'+rand()%13);
		if(rand()%2 == 1) 
			vett[i] = new B(a,c,(char)(c+rand()%13));
		else vett[i] = new C(a);
		
		m += vett[i]->f(100);		
		if(typeid(* vett[i]) == typeid(B)) 
			s << ((B *)vett[i])->f();		
		if(typeid(* vett[i]) == typeid(C))
			if(max<((C *)vett[i])->f())
				max = ((C *)vett[i])->f();

		/*
		if(typeid(* vett[i]) == typeid(B)) 
			cout << ((B *)vett[i])->toString();
		else cout << ((C *)vett[i])->toString();
		*/
		cout << *vett[i] << endl;
	}
	
	cout << endl << "Media: " << m/DEF << " Max: " << max << " Str: " << s.str();
	system("PAUSE");
	return 0;
}
