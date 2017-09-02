#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <typeinfo>
#define DIM 30
// By Danilo Tascone, controllare errori.
using namespace std;

class MyArray {
      
      private: 
               int dim;
               short *data;
      public:
             MyArray(int dim) {
                 this->dim = dim; 
                 data = new short[this->dim];
                 
                 for(int i = 0; i < this->dim;i++){
                         data[i] = static_cast<short>((this->dim)*sin(this->dim + i));
                        // cout << "[ "<<data[i] << "]";
                 }
               //  cout << endl;
             }
             
             float avg() {
                  float average = 0.0;
                  for(int i = 0; i < this->dim;i++){
                          average += data[i];
                  }
                  
                  return average/this->dim;
             }
             
             int greater(int q) {
                 int counter = 0;
                 for(int i = 0; i < (this->dim);i++){
                         if(data[i] > q){
                            counter++;
                         }
                 }
                 return counter;
             }
             
             virtual ostream &put(ostream &os){
                    stringstream temp;
                    for(int i = 0; i < this->dim ; i++){
                             temp << data[i] << " ";
                    }  
                     string str = temp.str();
                     return os << str;
             }
};

ostream & operator << (ostream & left, MyArray & obj)
{
        return obj.put(left);
}

class A {
      
      private: int dim;
              
      protected: MyArray *x;
      
      public:
             A(int dim ) {
                   this->dim = dim;
                   x = new MyArray(dim);
             }
             virtual float f() const = 0;
             
             virtual ostream &put(ostream &os){
                     
                     return os  << "dim = " << dim << " " << "arr: " << "["<< *x<<"]";
             }
};

ostream &operator<< (ostream &left, A &obj){
        return obj.put(left);
}
class B: public A {
      
      public:
             B(int dim) : A(dim) {}
             
             float f() const { return x->avg();} // nel caso non dovesse funzionare riguardare avg();
             
             ostream &put(ostream &os) {
                     return A::put(os) << " Class B  " << "f() = " << f() << " ";
             }
};

class C : public A {
      
      private: double w;
      
      public:
             C(int dim, double w) : A(dim) { this->w = w;}
             
             float f() const {
               int intera = (int)this->w;
              return  x->greater(intera);
               
             }
             
             float f(int p) const {return (this->w)*p;}
             
             ostream &put(ostream &os) {
                     return A::put(os) << " Class C  "<< "f() = " << f() << " " << "w = "<< w << "  " << "f(4) = " << f(4);
             }
};
int main()
{   
    A* vett[DIM];
    srand(833274768);
    
    float sommaF = 0.0;
    float sommaF4 = 0.0;
    int counter = 0;
    int iC = 0;
    
    for(int i = 0; i < DIM; i++){
            int x = 1 + rand()%5;
            
            switch(x%2) {
               
               case 0 : vett[i] = new B(x);
               break;
               case 1 : vett[i] = new C(x,x/(double)RAND_MAX*10000);
            }
    }
     
     for(int i = 0; i < DIM; i++){
             cout << i << ")"<< *vett[i] << endl << endl;
     }
     
    for(int i = 0; i < DIM; i++){
             sommaF += vett[i]->f();
             
         if(typeid(*vett[i]) == typeid(C)){
                  counter++;
                  if(counter == 5){
                     iC = i;
                     sommaF4 = ((C*)vett[i])->f(4);
                  }                                                        
             }
     }
     
 	 cout << "sommaF = " << sommaF << "  " << "SommaF(4) = " << sommaF4 << " di indice " << iC << endl << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
