#include<iostream>
#include<typeinfo>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#define DIM 50
using namespace std;
const int N=5;

class A{
	private:
		float* x;
	public:
		A(float _a){cout<<"A";
			x[0]=_a;
			for( int i=0; i<N; i++){ x[i]=((float)sin(100*x[i-1]));};
		};
		virtual float f()=0;
		float* getX(){return x;};
		virtual ostream& put(ostream& out){
			stringstream s;
			for(int i=0;i<N;i++){
				s<<x[i]<<" ";
			}
			return out<<s.str();
		};
};

ostream& operator << (ostream& out, A& obj){
	return obj.put(out);
};

class C:public A{
	public:
	C(float _a):A(_a){cout<<"C";};
		float f(){
			float avg=0;
			for(int i=0;i<N;i++){
				avg+=getX()[i];
			};
			return avg/N;
		};
		int gte(float _thr){
			int cont=0;
			for(int i=0;i<N;i++){
				if(getX()[i]>_thr) cont++;
			};
			return cont;
		};
		
		ostream& put(ostream& out){
			return A::put(out);
		};
};

class B:public A{
	public:
		B(float _a):A(_a){ cout<<"B"; };
		float f(){
			float max=0;
			for(int i=0;i<N;i++){
				if(getX()[i]>max) max=getX()[i];
			};
			return max;
			};
			
ostream& put(ostream& out){
			return A::put(out);
		};
};


class D{
	private:
		A* a;
		B* b;
		C* c;
	public:
		D(float seed){ cout<<"D";
		if(seed>0.5) a= new B(seed);
				else a= new C(seed);
		c= new C(seed/3);	
		b= new B(seed/2);
		};
		
 		float m(){
 			float max=0;
 			float somma=0;
 			for(int i=0;i<N;i++){
 				max=0;
 				if(max<a->getX()[i])max=a->getX()[i];
 				if(max<b->getX()[i])max=b->getX()[i];
 				if(max<c->getX()[i])max=c->getX()[i];
 				somma+=max;
 			};
 			return somma;
 		};
 		
 		float h(float thr){
 			float rap=b->f()/c->f();
 			if(typeid(*a)==typeid(C)) rap= rap*((C*)a)->gte(thr);
 			return rap;
 		};
 		
 		ostream& put(ostream& out){
 			return out<<a->put(out)<<endl<<b->put(out)<<endl<<c->put(out)<<endl;
 			};

};

ostream& operator <<(ostream& out, D& obj){
	return obj.put(out);
};


int main(){
	D* vett[N]; float avg=0;
	srand(111222333);
	for(int i=0;i<DIM;i++){
		vett[i]= new D(rand()/RAND_MAX);
		avg=vett[i]->h(0.7);
		cout<<"class "<<typeid(*vett[i]).name()<<"  "<<vett[i]<<endl;
	};
	cout<<"punto 1) media ="<<avg<<endl;;
	cout<<"punto 2) somma ="<<(vett[4]->m()+vett[5]->m());
}
