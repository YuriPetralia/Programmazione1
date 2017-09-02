#include <iostream>
#include <stdlib.h>
#include <typeinfo.>
#include <sstream>
#define DEF 20
using namespace std;

class A{
	
	private:
		string x;
		
	public:
		A(string _x){ x = _x; }
		string getX(){ return x; }
		virtual string guess() = 0;
		bool doppia(){
			for(int i=0;i<x.length()-1;i++)
				for(int j=i+1;j<x.length();j++)
					if(x[i] == x[j])
						return true;
			return false;
		}
		//string toString(){ return "x = " + x; }
		virtual ostream &put(ostream &os){
			return os << "x = " + x;
		}
};

ostream &operator <<(ostream &left,A &obj){
	return obj.put(left);
}

class B : public A{
	
	private:
		string y;
		int pos;
		
	public:
		B(string _s,int _p) : A(_s.substr(0,10)){ y = _s.substr(10,10); pos = _p; }
		char estrai(){ return y[pos]; }
		string guess(){
			stringstream s;
			for(int i=0;i<getX().length();i++)
				s << getX()[i] << y[i];
		return s.str();
		}
		//string toString(){ stringstream s; s << pos; return A::toString()+" y = "+y+" pos: "+s.str(); }
		ostream &put(ostream &os){
			return A::put(os) << " y = " << y << " pos: " << pos;
		}
};

class C : public A{
	
	private:
		string z;
		
	public:
		C(string _s) : A(_s.substr(0,10)){ z = _s.substr(10,10); }
		string guess(){ return getX()+z; }
		//string toString(){ return A::toString()+" z = "+z; }
		ostream &put(ostream &os){
			return A::put(os) << " z = " << z;
		}
};

int main(){
	
	srand(333675333);
	A * vett[DEF];
	stringstream s;
	char c[20][20];	
	stringstream s2;
	for(int i=0;i<DEF;i++){
		string str = "";
		for(int j=0;j<20;j++) str += (char) ('a'+rand()%26);
		if(rand()%2 == 1) vett[i] = new B(str,rand()%10);
		else vett[i] = new C(str);
		
		if(!vett[i]->doppia()) cout << i << ") ";
		
		B *ptr = dynamic_cast <B*> (vett[i]);
		if(ptr){
			
			s << ptr->estrai();
			
		}
		
	//	if(typeid(* vett[i]) == typeid(B)) s << ((B *)vett[i])->estrai();
		
		/*
		if(typeid(* vett[i]) == typeid(B)) cout << ((B *)vett[i])->toString() << endl;
		else  cout << ((C *)vett[i])->toString() << endl;
		*/
		cout << *vett[i] << endl;
	}
	
	for(int i=0;i<DEF;i++){
		for(int j=0;j<DEF;j++){
			c[i][j] = vett[i]->guess()[j];
			if(i == j) s2 << c[i][j];
		}
	}

	cout << endl << "Estrai(): " << s.str() << " Diagonale: " << s2.str() << "\n\n";
	
	system("PAUSE");
  return EXIT_SUCCESS;
}
