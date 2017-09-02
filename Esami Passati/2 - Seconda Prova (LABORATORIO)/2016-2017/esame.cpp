#include<iostream>
#include<string>
#include <cstdlib>
#define DIM 50

using namespace std;


class A {
	
	string x;
	public:
		A(string _x) {
			x=_x;
		}
		
		string getX() {
			return x;
		}
		
		virtual string select()=0;
		
		bool moreThan3() {
			string str=x;
			int cont=0;
			for(int i=0;i<str.length()-1;i++) {
				cont=0;
				for(int j=1;str.length();j++) {
					if(x.at(i)==x.at(j)) {
						cont++;
						if(cont>=3) {
						
						return true;
							
						}
					}
				}
				
			}
			return false;
		}
		virtual ostream& output(ostream& out) = 0;
};

class B:public A {
	string y;
	float f;
	
	public: 
	
		B(string s, float _f): A(s.substr(0,9)) {
			for(int k=10;k<s.length();k++) { y=s.at(k); }
			f = _f;
		}
		char extract(){
        	int indice = (int)(f*10.0)%10;
        	return y.at(indice);
    	}
    
    	string select() {
    		string strVocali="";
    		
    		for(int i=0,j=0;i<getX().length(),j<y.length();i++,j++) {
    			if(getX()[i]==('a'||'e'||'i'||'o'||'u') && y[j]==('a'||'e'||'i'||'o'||'u')) {
    				strVocali+=getX()[i] + y[j];
				}
			}
    /*		for(int i=0;i<getX().length();i++) {
    			if(getX()[i]==('a'||'e'||'i'||'o'||'u')) {
    				strVocali+=getX()[i];
				}
			}
			for(int j=0;j<y.length();j++) {
				if(y.at(j)==('a'||'e'||'i'||'o'||'u')) {
					strVocali+=y.at(j);
				}
			}*/
			return strVocali;
		}
		ostream& output(ostream& out){        
        	out << getX() << endl;
        	return out;
    	}
};

class C:public A {
	short * b;
	short n;
	public:
		C(string s) : A(s) {
			getX()=s.substr(0,9);
			n=s.length();
			b=new short[n];
			for(int i=0;i<n;i++) {
				b[i]=s.at(i)%5;
			}
		}
		
		~C() {delete[] b;}
		
		string select() {
			string stringa="";
			for (int i=0;i<getX().length();i++) {
				stringa+=getX()[b[i]];
				cout<<getX()[b[i]];
			}
			return stringa;
		}
		ostream& output(ostream& out){        
    		out << getX() << endl; 
    		for(int i = 0; i < n; i++) {
       			out << b[i] << " "; 
        	}
    		cout << endl;
    		return out;
    	} 
	
};

ostream& operator<<(ostream& stream, A* a) {
    
    return a->output(stream);
    
}

int main() {
	
	srand(111222333);
	A* vett[DIM];
	string select = "";
    string extract = "";
    int indice = 0;
    

    
	for(int i=0;i<DIM;i++) {
		string str="";
		for(int j=0;j<20;j++) {
			str+=(char)('a'+rand()%12);
		}
		if(rand()%2==1) {
			vett[i]=new B(str,(float)rand()/RAND_MAX);
		} else {
			vett[i]=new C(str);
		}
		cout<<vett[i];
	}
	
/*	for(int i=0;i<DIM;i++) {
		if(vett[i]->moreThan3()) cout<<"indice: "<<i<<endl;
	}*/
	
	
	select=vett[13]->select()+vett[48]->select();
	cout<<select;
	
	
	return 0;
}
