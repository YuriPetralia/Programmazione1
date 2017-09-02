#include <iostream>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <cmath>
using namespace std;

class C{
private:
    float x;

public:
    C(float _x) : x(_x) {}
    virtual double f() = 0;
    float getX() { return x; }
    virtual ostream &put(ostream &os){
        return os << "[" << x;
    }
};

ostream &operator<<(ostream &stream, C &obj){
    return obj.put(stream);
}

class D: public C{
private:
    char c;

public:
    D(float _x) : C(_x) {
        c = (char)('a' + (int)(_x*1000000000) % 20);
    }

    double f(){ return sin(getX()) * sin(getX()); }
    char getC() { return c; }
    ostream &put(ostream &os){
        return C::put(os) << " c='" << c << "'], \t";
    }
};

class E: public C{
private:
    int n;

public:
    E(float _x): C(_x) {
        n = (int)(_x*1000000000)%10;
    }

    double f() { return cos(getX()) * cos(getX()); }
    int getN(){ return n; }
    ostream &put(ostream &os){
        return C::put(os) << " n=" << n << "]\t";
    }
};

class A{
protected:
    C* obj1;
    C* obj2;

public:
    A(float _x){
        obj1 = new D(_x);
        obj2 = new E(_x);
    }

    double g(){
        return obj1->f() + obj2->f();
    }

    virtual ostream &put(ostream &os){
        return os << *obj1 << *obj2 << "g()= " << g() << "\t";
    }
};

ostream &operator<<(ostream &stream, A &obj){
    return obj.put(stream);
}

class B: public A{
public:
    B(float _x) : A(_x) {}

    string st(){
        string s;
        for(int i = 0; i < ((E*)obj2)->getN(); i++){
            s += ((D*)obj1)->getC();
        }
        stringstream stream;
        stream << g() << s;
        return stream.str();
    }

    ostream &put(ostream &os){
        return A::put(os) << "st()= " << st();
    }
};

int main(){
    srand(328832748);
    const int DIM = 50;
    A* vett[DIM];

    for(int i = 0; i < DIM; i++){
        if(rand()%2 == 1)
            vett[i] = new A((float)rand()/INT_MAX);
        else
            vett[i] = new B((float)rand()/INT_MAX);
    }

    double sum1 = 0;
    int sum2 = 0;
    string s;

    for(int i = 0; i < DIM; i++){
        sum1 += vett[i]->g();
        cout << i << ")\t";
        if(typeid(*vett[i]) == typeid(A))
            cout << "class A: ";
        else{
            cout << "class B: ";
            s = ((B*)vett[i])->st();
            int k = s.length();
            for(int i = 0; i < k; i++)
                sum2 += s[i];

        }
        cout << *vett[i] << endl;
    }

    cout << "\nPunto 1: sum1=" << sum1 << "\nPunto 2: sum2=" << sum2 << endl;

    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}
