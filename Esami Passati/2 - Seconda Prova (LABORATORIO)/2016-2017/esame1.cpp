#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>
#include <typeinfo>
#define DIM 50
using namespace std;

class C{
	
	private:
		float x;
		
	public:
		C(float _x){ x = _x; }
		virtual double f() = 0;
		float getX(){ return x; }
		virtual ostream &put(ostream & os) {
                x=3;
      		return os << " [" << x;
  		}
		
};//end Class C

ostream & operator << (ostream & left,  C & obj){
	return  obj.put(left); 
}  

class D : public C{
	
	private:
		char c;
		
	public:
		D(float _x) : C(_x){ c = (char)('a'+(int)(_x*1000000000) % 20);	}
		double f(){ return sin(getX())*sin(getX()); }
		char getC(){ return c; }
		ostream &put(ostream & os) {
      		return  C::put(os) << ", c = " << c << "]";
   		}
	
};//end Class D

class E : public C{
	
	private:
		int n;
	
	public:
		E(float _x) : C(_x){ n = (int)(_x*1000000000)%10; }
		double f(){	return cos(getX())*cos(getX()); }
		int getN(){	return n; }
		ostream &put(ostream & os) {
      		return  C::put(os) << ", n = " << n << "] ";
   		} 
		
};//end Class E


class A{
	
	protected:
		C * obj1, * obj2;
		
	public:
		A(float _x){
			obj1 = new D(_x);
			obj2 = new E(_x);
		}
		
		double g() const { return obj1->f() + obj2->f(); }
		virtual ostream &put(ostream & os) const{
      		return  os << typeid(*this).name() << *obj1 << ", " << *obj2 << " g()=" << g();
   		}
		
};//end Class A

ostream & operator << (ostream & left, A & obj){
	return obj.put(left); 
}  

class B : public A{
	
	public:
		B(float _x) : A(_x){}
		string st() const{
			string str = "";
			for(int j=0; j<((E*)obj2)->getN(); j++)
            	str += ((D*)obj1)->getC();
            	
		    ostringstream os;
		    os << g();
		    return  os.str() + str;
		}
		ostream &put(ostream & os) const{
      		return  A::put(os) << " st() = " << st();
   		}
		
};//end Class B

int main(){
	
	srand(832748);
	A * vett [DIM];
	for(int i=0; i<DIM; i++){
		if(rand()%2==1) vett[i] = new A((float)rand()/INT_MAX);
		else vett[i] = new B((float)rand()/INT_MAX);
		
		cout << i << " " << *(vett[i]) << endl;
	}
	
	double s = 0.0;
	int s2 = 0;
	for(int i=0;i<DIM;i++){
		
		s += vett[i]->g();
		if(typeid(* vett[i]) == typeid(B))
			for(int j=0;j<((B *)vett[i])->st().length();j++){
				s2 += ((B *)vett[i])->st()[j];
			}	
	}
	
	cout << endl << "s: " << s << " s2:" << s2;
	
	getchar();
	return 0;
}
