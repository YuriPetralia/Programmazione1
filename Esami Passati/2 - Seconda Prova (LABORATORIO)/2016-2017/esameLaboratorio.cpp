#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <string>
#define DIM 50

using namespace std;

class A {
	protected:
		short x;
	public:
		A(short _x) {
			x = _x;
		}
		virtual int const f()=0;
		virtual ostream &put(ostream &os){
			return os << "x=" << x << " ";
		}	
};

ostream & operator << (ostream & left, A & obj) {
        return obj.put(left);
}

class B:public A {
	
	char b;
	
	public:
		B(int _x, char _b) :A(x) {
			b = _b;
		}
		int const f() {
			if(x<50) {
				return b;
			} else {
				return b+4;
			}
		}
		ostream &put(ostream &os){
			return A::put(os) << "b='" << b << "'";
		}
	
};

template<class T>
class C : public A {
	
	private:
		T c;
	public:
		C(int _x, T _c) : A(_x) { 
			c = _c; 
		}
		
		int const f() { 
			return (int)x + (100 * (c)); 
		}
		
		const T f(double eps) {
			if (typeid(T) == typeid(char))
				return (char)((int)(c)-1);
			return (f() + eps);
		}
		ostream &put(ostream &os){
			return A::put(os) << "c=" << c;
		}

};

int main() {
	srand(1365582748);

	A *vett[DIM];

	for (int i = 0; i < DIM; i++)
	{
		short x = 1 + rand() % 100;
		int c = 'a' + rand() % 26;
		switch ( rand() % 3) {
			case 0: vett[i] = new B(x,c); break;
			case 1: vett[i] = new C<double>(x, rand()/(double)RAND_MAX); 
					break;
			case 2: vett[i] = new C<char>(x, c);
		}
	}
	
	int maxValore = 0;
	string concatenata = "";
	for (int i = 0; i < DIM; i++) {	
	cout << *vett[i] << endl;
		if(typeid(*vett[i]) == typeid(C<char>))
			concatenata += ((C<char>*)vett[i])->f(0.03);

		
		if(maxValore < (*vett[i]).f())
			maxValore = (*vett[i]).f();
	}
	/*PUNTO 1*/
	cout << endl;
	cout << "max: " << maxValore << endl;
	cout << "concatenata = \"" << concatenata << "\"" << endl;

	
	
}
