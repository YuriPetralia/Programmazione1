#include<iostream>
#include<cmath>
#include<typeinfo>
#include<ctime>
#include<cstdlib>

using namespace std;

class MyDouble {
	private:
		double x;
	public:
		MyDouble(float _x) {
			x=_x;
		}
		int getTrunc() {
			x+=0.5;
			return (int)x;
		}
		
		MyDouble& exp(MyDouble& op, double y, float _x){
        	x = pow(_x, y);
        	return x;
    	}
		
		bool operator>(MyDouble &op){
        	if (this->x > op.x) return true;
        	else return false;
    	}
		
};

MyDouble& operator^ (MyDouble& op,MyDouble& y) {
	return y.exp(op);
}

class A {
	private:
		float w;
	protected:
		const int dim = 4;
		MyDouble* mat[][4];
	public:
		A(double _w) {
			
			for(int i=0;i<dim;i++) {
				for(int j=0;j<dim;j++) {
					mat[i][j]=MyDouble((w*10)+i+j);
				}
			}
			return mat;

		}
		virtual double f()=0;
		
		ostream& output(ostream& out){
        cout << A ;
        return out;
    }
		
};

class B:public A {
	public:
		B(double _w) : A(_w) {
		}
		double f(){
			double somma=0;
			for(int i=0;i<dim;i++){
				somma+=_w[i];
			}
			return somma;
		}
};


class C:public A {
	private:
		T c;
	public:
		C(double _w, T _c) {
		}
		double f(double mat[dim][dim],const int dim) {
			double max=0;
			for(int i=0;i<dim;i++){
				for(int j=0;i<dim;j++) {
					max=mat[i][j];
					if(max>mat[i+1][j+1]) return max;
					else max=mat[i+1][j+1];
				}
			}
		}
		MyDouble f(T p) {
			
			if(typeid(T) == typeid(double)) return MyDouble(p);
			else return mat[0][0]=pow(mat[0][0],mat[dim-1][dim-1]);
		}
		
};

const int DIM=30;

int main() {
	
	srand(328832748);
	for(int i=0;i<DIM;i++) {
		double x= rand()/(double) RAND_MAX;
		rand();
		switch (rand()%3) {
			case 0: vett[i]=new B(x);
					break;
			case 1: vett[i]= new C <double> (x, rand()/(double)RAND_MAX);
					break;
			case 2: vett[i]=new C<int> (x,(int)(x*10));
					break;
		}
	}
	
	return 0;
	
}

