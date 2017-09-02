#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <sstream>
#define DEF 30
using namespace std;

class A{
	
	private:
		string s;
		
	public:
		A(string _s){ s = _s; }
		string getS(){ return s; }
		bool lunga(){ return ((s.length()>3) ? true : false); }
		//string toString(){ return "s = " + s; }
		virtual string estrai() = 0;
		virtual ostream &put(ostream &os){
			return os << "s = " << s;
		}
};

ostream &operator << (ostream &left, A &obj){
	return obj.put(left);
}

class B : public A{
	
	private:
		int y;
		
	public:
		B(string _s,int _y) : A(_s){ y = _y; }
		bool lunga(){ return ((getS().length()>y) ? true : false); }
		string estrai(){
			stringstream s;
			for(int i=0;i<(y-5);i++) s << '*';
			return s.str();
		}
		/*
		string toString(){
			stringstream s;
			s << A::toString() << " | y = " << y;
			return s.str();
		}
		*/
		ostream &put(ostream &os){
			return A::put(os) << " | y = " << y;
		}
};

class C : public A{
	
	private:
		char c;
		
	public:
		C(string _s,char _c) : A(_s){ c = _c; }
		string estrai(int _x){
			stringstream s;
			if(_x<getS().length()-1) s << getS()[_x];
			else s << getS().substr(getS().length()-2,3);
			return s.str();
		}
		/*
		string toString(){
			return A::toString() + " | c = " + c;
		}*/
		ostream &put(ostream &os){
			return A::put(os) << " | c = " << c;
		}
};

class D : public C{
	
	private:
		int z;
		
	public:
		D(string _s,char _c,int _z) : C(_s,_c){ z = _z; }
		string estrai(){
			stringstream s;
			if(z<getS().length()-1) s << getS()[z];
			else s << getS().substr(0,2);
			return s.str();
		}
		/*
		string toString(){
			stringstream s;
			s << C::toString() << " | z = " << z;
			return s.str();
		}*/
		ostream &put(ostream &os){
			return C::put(os) << " | z = " << z;
		}
};


int main(){
	
	srand(1567234333);
	A * vett[DEF];
	int len = 0;
	stringstream s;
	stringstream s4;
	for(int i=0;i<DEF;i++){
		int p = rand()%10+3;
		string str = "";
		for(int j=0;j<p;j++) str += (char)('a' + rand()%26);
		int a = rand()%15;
		if(rand()%2 == 1) vett[i] = new D(str, (char)('a'+rand()%26), a);
		else vett[i] = new B(str, a);
		
		s << vett[i]->estrai();
		if(typeid(* vett[i]) == typeid(D))
		s4 << ((C *)vett[i])->estrai(4);
		
		if(vett[i]->lunga())
			len++;
			
		//if(typeid(* vett[i]) == typeid(B) && ((B *)vett[i])->lunga())
			//len++;
		/*
		if(typeid(* vett[i]) == typeid(B)) cout << ((B *)vett[i])->toString() << endl;
		else cout << ((D *)vett[i])->toString() << endl;*/
		cout << *vett[i] << endl;
	}
	
	cout << endl << "Len: " << len << endl << "Estrai() = { " << s.str() << " }" << endl << "Estrai(4) = { " << s4.str() << " }";
  system("PAUSE");
	return 0;
}
