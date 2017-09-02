#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <sstream>
#define DEF 60
using namespace std;

class A{
	
	private:
		int x;
		string s;
		
	protected:
		char * converti(){
			int len = s.length();			
			char * c = new char[len];
			for(int i=0;i<len;i++)
				c[i] = s[i];
			return c;
		}
		
	public:
		A(int _x,string _s){ x = _x; s = _s; }
		int getX(){ return x; }
		
		/*
		string toString(){
			stringstream t;
			t << x;
			return t.str()+", "+s;
		}
		*/
		virtual char carattere() = 0;
		
		ostream &put(ostream &os){
			return os << x << ", " << s;
		}
		
};

ostream &operator <<(ostream &left, A &obj){
	return obj.put(left);
}

class B : public A{
	
	public:
		B(int _x,string _s) : A(_x,_s){}
		bool primo(){
			int c = 0;
			for(int i=2;i<getX();i++){
				if(getX()%i == 0) c++;
				if(c > 0) return false;
			}
			return true;
		}
		char carattere(){
			return converti()[getX()%(sizeof(converti())/sizeof(*converti()))];
		}
	
};

class C : public A{
	
	public:
		C(int _x,string _s) : A(_x,_s){}
		char carattere(){
			return converti()[(sizeof(converti())/sizeof(*converti()))-1];
		}
};

int main(){
	
	srand(244556677);
	A * vett[DEF];
	string s = "";
	
	for(int i=0;i<DEF;i++){
		
		int p = rand()%10+3;
		string str = "";
		for(int j=0;j<p;j++)
			str += (char)('a'+rand()%26);
		if(rand()%2 == 1) vett[i] = new B(rand()%1000,str);
		else vett[i] = new C(rand()%10,str);
		
		s+= vett[i]->carattere();
		
		cout << "vett[" << i << "] = { " << *vett[i] << " }" << endl;
	}
	
	cout << endl << s << endl;
	for(int i=0;i<DEF;i++){
		if(typeid(* vett[i]) == typeid(B) && ((B *)vett[i])->primo())
			cout << i << ",";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}
