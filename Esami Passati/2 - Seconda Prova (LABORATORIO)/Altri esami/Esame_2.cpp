#include <iostream>
#include <cmath>
#include <cstdlib>
#include <typeinfo>
using namespace std;

/*****************************************************
   Classe MyArray */

class MyArray{
private:
    int dim;
    short* data;

public:
    MyArray(int);
    float avg();
    int greater(int);
    ostream &put(ostream&);
};

/******************************************************
   Overloading dell'operatore << di MyArray */

ostream &operator<<(ostream &stream, MyArray &obj){
    return obj.put(stream);
}

/******************************************************
   Metodi della classe MyArray */

MyArray::MyArray(int _x): dim(_x) {
    data = new short[dim];
    for(int i = 0; i < dim; i++){
        data[i] = short(dim * sin(dim + i));
    }
}

float MyArray::avg(){
    float temp = 0;
    for(int i = 0; i < dim; i++){
        temp += data[i];
    }
    return temp/dim;
}

int MyArray::greater(int _x){
    int temp = 0;
    for(int i = 0; i < dim; i++){
        if(data[i] > _x) temp++;
    }
    return temp;
}

ostream& MyArray::put(ostream &os){
    os << "[";
    for(int i = 0; i < dim-1; i++){
        os << data[i] << ", ";
    }
    os << data[dim-1] << "]";
    return os;
}

/********************************************************
   Classe A */

class A{
private:
    int dim;

protected:
    MyArray* x;

public:
    A(int);
    virtual float f() = 0;
    virtual ostream &put(ostream&);
};

/********************************************************
   Overloading dell'operatore << di A */

ostream &operator<<(ostream &stream, A &obj){
    return obj.put(stream);
}

/********************************************************
   Metodi della classe A */

A::A(int _x): dim(_x){
    x = new MyArray(dim);
}

ostream& A::put(ostream &os){
    return os << ", dim=" << dim << ", " << *x;
}

/********************************************************
   Classe B */

class B: public A{
public:
    B(int);
    float f();
    ostream &put(ostream&);
};

/********************************************************
   Metodi della classe B */

B::B(int _x): A(_x) {}

float B::f(){
    return x->avg();
}

ostream& B::put(ostream &os){
    return A::put(os) << ", f()=" << f();
}

/*********************************************************
   Classe C */

class C: public A{
private:
    double w;

public:
    C(int, double);
    float f();
    float f(int) const;
    ostream &put(ostream&);
};

/*********************************************************
   Metodi della classe C */

C::C(int _x, double _w) : A(_x), w(_w) {}

float C::f(){
    return x->greater(int(w));
}

float C::f(int _x) const{
    return w * _x;
}

ostream& C::put(ostream &os){
    return A::put(os) << ", w=" << w << ", f()=" << f()
                      << ", f(4)=" << f(4);
}

/*********************************************************
   MAIN */

int main(){
    const int DIM = 30;
    A* vett[DIM];

    srand(833274768);
    for(int i = 0; i < DIM; i++){
        int x = 1 + rand() % 5;
        switch(x % 2){
        case 0:
            vett[i] = new B(x);
            break;
        case 1:
            vett[i] = new C(x, x/(double)RAND_MAX*10000);
        }
    }

    float temp = 0, valoreF4 = 0;
    int index = 0, cont = 0;

    for(int i = 0; i < DIM; i++){
        temp += vett[i]->f();

        cout
         i << ")\t";
        if(typeid(*vett[i]) == typeid(B)){
            cout << "class B";
        }else{
            cont++;
            if(cont == 5){
                index = i;
                valoreF4 = ((C*)vett[i])->f(4);
            }
            cout << "class C";
        }
        cout << *vett[i] << endl;
    }

    cout << "\nPunto 1: sum = " << temp << endl;
    cout << "Punto 2: f(4) = " << valoreF4 << " di indice " << index << endl;

    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}
