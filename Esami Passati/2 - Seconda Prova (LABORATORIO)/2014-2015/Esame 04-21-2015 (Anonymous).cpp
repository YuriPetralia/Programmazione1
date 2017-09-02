#include <iostream>

using namespace std;


class A {
protected: 
    int x;
	
public: 
    A (int _x): x(_x) { }		

  	virtual int f() const = 0;
		
    virtual ostream &put(ostream & os) const {
       return  os << typeid(*this).name() << "\t   x=" << x;   
    }    
};


ostream & operator << (ostream & left, const A & obj)
   {
     return  obj.put(left); 
   }  



class B : public  A {
	
private: 
   char b;
	
public: 
   B (int _x, char _b): A(_x), b(_b) { }
	
   int  f () const
	  { 
		if (x%2 == 0) return b;
		         else return 2*b;
	  }

   B operator ++ (int) {
       B aux = *this;
       x++;
       return  aux;
    }

    virtual ostream &put(ostream & os) const {
       return  A::put(os) << "\t   b=" << b;   
      }
};




template <typename T>
class C: public A {
	
private:
   T c;
	
public:
   C (int _x, T _c): A(_x), c(_c) { }
		
   int  f () const
	  { 
        return x+(int)(c*20);
  	  }

   T  f (double epsilon) const
	  {  
        if (typeid(T) == typeid(char))   return c+1;
                                 else    return (T) (f()+epsilon);
  	  }
	    	  
   virtual ostream &put(ostream & os) const {
       return  A::put(os) << "\t   c=" << c << "\t f(0.03)=" << f(0.03);   
   } 
	    
};

 

int main()
{
   const int DIM = 50;
   srand(328832748);
   A * vett [DIM];
			
   for (int i=0; i<DIM; i++) {
	  int x=1+rand()%100;
	  int c='a'+rand()%26;
	  switch (rand()%3) {
         case 0 : vett[i] = new B(x,c); 
                  break;
         case 1 : vett[i] = new C<double>(x,rand()/(double)RAND_MAX);
                  break; 
         case 2 : vett[i] = new C<char>(x,c+1);
      }   
						
	  cout << i << " \t" << *vett[i] << " \t f()=\t" << vett[i]->f() << endl;
    }	

	string conc="";
	int max=0;
    for (int i=0; i<DIM; i++) {
	      if (max < vett[i]->f()) max=vett[i]->f();
	      if (typeid(*vett[i]) == typeid(C<char>))  
              conc += dynamic_cast<C<char>*>(vett[i])->f(0.03);	
	}			
	cout << "\nmax=" << max << "\nconc=" << conc << endl;
				
    cout << "******** operator++ ********\n";
    B obj = *((B*)vett[37]);
    cout << obj << endl;
    obj++;
    cout << obj << endl;

   system("PAUSE");    // ns. comodo!
   return EXIT_SUCCESS;
} // End main()
