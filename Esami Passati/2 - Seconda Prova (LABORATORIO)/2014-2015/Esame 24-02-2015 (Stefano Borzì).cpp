#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <string>
#define DIM 50

/* Coded By Helias (Stefano Borzì) */
/*
	Le parti scritte in commento sono incomplete o sbagliate 
	(questo codice è stato valutato 2 punti all'esame di laboratorio di Cincotti)
*/

using namespace std;

class A {

	protected: int x;
	public:
		A(int _x) { x = _x; }
		virtual int f() const = 0;
		virtual ostream &put(ostream &os){
			return os << "x=" << x << " ";
		}
};

ostream & operator << (ostream & left, A & obj)
{
        return obj.put(left);
}

class B : public A {
	private:
		char b;
	public:
		B(int _x, char _b) : A(_x) { b = _b; }
		int f() const {
			if ( x % 2 == 0)
				return (int) b;
			return ((int) b) * 2;
		}
		ostream &put(ostream &os){
			return A::put(os) << "b='" << b << "'";
		}
/*		B operator ++( int)
		{
			x++;
			return *this;
		}
*/
};

template<class T>
class C : public A {
	
	private:
		T c;
	public:
		C(int _x, T _c) : A(_x) { c = _c; }
		int f() const { return x + (20 * (c)); }
//		int f() const { return x + (20 * ((int)c)); }
		T f(double eps) const {
			if (typeid(c) == typeid(char))
				return (char)((int)(c)+1);
			return (f() + eps);
		}
		ostream &put(ostream &os){
			return A::put(os) << "c=" << c;
		}

};

int main() {
	srand(328832748);

	A *vett[DIM];

	for (int i = 0; i < DIM; i++)
	{
		int x = 1 + rand() % 100;
		int c = 'a' + rand() % 26;
		switch ( rand() % 3) {
			case 0: vett[i] = new B(x,c); break;
			case 1: vett[i] = new C<double>(x, rand()/(double)RAND_MAX); break;
			case 2: vett[i] = new C<char>(x, c+1);
		}
	}

	int tmp = 0;
	string conc = "";
	for (int i = 0; i < DIM; i++)
	{	
		if(typeid(*vett[i]) == typeid(C<char>))
			conc += ((C<char>*)vett[i])->f(0.03);

		cout << *vett[i] << endl;
		if(tmp < (*vett[i]).f())
			tmp = (*vett[i]).f();
	}
	
	cout << endl;
	cout << "max: " << tmp << endl;
	cout << "conc = \"" << conc << "\"" << endl;
/*
	cout << endl << "## TEST ## operatore ++" << endl;
	cout << *vett[4] << endl;
	((B*)vett[4])++;
	cout << *vett[4] << endl;
*/
	return 0;
}