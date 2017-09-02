#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;

/*****************************************
    Classe A                            */

class A{
protected:
    int x;

public:
    A(int _x) : x(_x) {}
    virtual const int f() = 0;
    virtual ostream &put(ostream&);
};

/****************************************
    Overloading dell'operatore << di A */

ostream &operator<<(ostream &stream, A &obj){
    return obj.put(stream);
}

/****************************************
    Metodi della classe A              */

ostream& A::put(ostream &os){
    return os << "x=" << x;
}

/*****************************************
    Classe B                            */

class B : public A{
private:
    char b;

public:
    B(int _x, char _b) : A(_x), b(_b) {}
    const int f();
    ostream &put(ostream&);
    B operator++(int);
};

/******************************************
    Metodi della classe B                */

B B::operator++(int){
    B aux = *this;
    x++;
    return aux;
}

const int B::f(){
    if(x % 2 == 0)
        return b;
    return b * 2;
}

ostream& B::put(ostream& os){
    return A::put(os) << ", b=" << b << ", f()=" << f();
}

/*******************************************
    Classe C                              */

template<class T>
class C: public A{
private:
    T c;

public:
    C(int _x, T _c) : A(_x), c(_c) {}
    const int f(){
        return x + int(20 * c);
    }
    const T f(double eps){
        if(typeid(T) == typeid(char))
            return c + 1;
        return T(f() + eps);
    }
    ostream &put(ostream& os){
        return A::put(os) << ", c=" << c << ", f()=" << f() << ", f(0.03)=" << f(0.03);
    }
};

/**********************************************
    MAIN                                     */

int main(){
    const int DIM = 50;
    A* vett[DIM];
    srand(328832748);
    for(int i = 0; i < DIM; i++){
        int x = 1 + rand()%100;
        int c = 'a' + rand()%26;
        switch(rand()%3){
        case 0:
            vett[i] = new B(x, c);
            break;
        case 1:
            vett[i] = new C<double>(x, rand()/(double)RAND_MAX);
            break;
        case 2:
            vett[i] = new C<char>(x, c+1);
        }
    }

    int temp = 0;
    string s;

    for(int i = 0; i < DIM; i++){
        if(temp < vett[i]->f())
            temp = vett[i]->f();


        cout << i << ")\t";
        if(typeid(*vett[i]) == typeid(B))
            cout << "class B:\t";
        else if(typeid(*vett[i]) == typeid(C<double>))
            cout << "class C<double>: ";
        else{
            s += ((C<char>*)vett[i])->f(0.03);
            cout << "class C<char>: ";
        }
        cout << *vett[i] << endl;
    }

    cout << "\nIncremento la x usando l'operatore overloaded ++:" << endl;
    for(int i = 0; i < DIM; i++){
        (*((B*)vett[i]))++;
        cout << *vett[i] << endl;
    }

    cout << "\nPunto 1: max= " << temp << endl;
    cout << "Punto 2: conc= \"" << s << "\"" << endl;


    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}
