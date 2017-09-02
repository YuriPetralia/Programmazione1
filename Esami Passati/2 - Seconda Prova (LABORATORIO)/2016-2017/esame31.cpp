#include<iostream>
#include<cmath>
#include<typeinfo>
#include<cstdlib>

using namespace std;

const int N=5;
class A {
	
	float * x;
	
	public:
		A(float a) {
			float x[N];
			x[0]=a;
			for(int i=1;i<N ;i++) {
				x[i]=(float)sin(100*x[i-1]);
			}
		}
		virtual float f()=0;
		
		float* getX(){
			return x;
		}
		
		ostream& put(ostream& os) {
			return os<<"["<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<" "<<" "<<x[4]<<"]"<<endl;
		}
};

class B:public A {
	
	public:
		B(float x):A(x) {
		}
		float f() {
			float max=0;
			for(int i=0;i<N-1;i++) {
				max=getX()[i];
				if(max<getX()[i+1]) {
					max=getX()[i+1];
				}
			}
			return max;
		}
};

class C:public A {
	public:
		C(float x) :A(x){
		}
		float f() {
			float somma=0,media=0,lunghezza=N;
			for(int i=0;i<N;i++) {
				somma+=getX()[i];
			}
			media=somma/lunghezza;
			return media;
		}
		
		int gte(float thr) {
			int cont=0;
			for(int i=0;i<N;i++) {
				if(thr<getX()[i]) {
					cont++;
				}
			}
			return cont;
		}
};

class D {
	A* a;
	B* b;
	C c;
	public:
		D(float seed): c(C(seed/3)) {
			if (seed>0.5) {
				a= new B(seed);
			} else {
				a= new C(seed);
			}
			b= new B(seed/2);
		}
		
		float m() {
			float max1=0;
			float max2=0;
			float max3=0;
			
			for (int i =0;i<N;i++) {
				if( a->getX()[i] > max1) {
					max1=a -> getX()[i];
				}
				if( b->getX()[i] > max2) {
					max2=b -> getX()[i];
				}
				if( c.getX()[i] > max3) {
					max3=c.getX()[i];
				}
				
			}
			return max1+max2+max3;
			
		}
		float h(float thr) {
			if(typeid(*a)==typeid(C)){
				
				return (c.f()/b->f())*3;
				
			} else {
				
				return (c.f()/b->f());
				
			} 
		}
		
		friend 	ostream& operator<< (ostream& left, D& ogg);
		
};

ostream& operator<< (ostream& left, D& ogg) {
 			
	cout << "\n class C: ";
	cout << ogg.c.put(left);
			 
	cout << "\nclass B: ";
	return ogg.b->put(left);
			
}





const int DIM = 5;
int main() {
	D** vett= new D*[DIM];
	srand(111222333);
	float sommatoria = 0;
	for(int i=0; i < DIM; i++)
	{
		vett[i]= new D((float)rand()/RAND_MAX);
		cout << *(vett[i]);
		sommatoria += (*(vett[i])).h(0.7);
		
	}
//	cout <<endl<< "media h(0.7): "<< sommatoria / (float)DIM;
//	cout << "\nvett[4].m()+vett[5].m() = "<<vett[4]->m()+vett[5]->m();
	
	
	return 0;
}
