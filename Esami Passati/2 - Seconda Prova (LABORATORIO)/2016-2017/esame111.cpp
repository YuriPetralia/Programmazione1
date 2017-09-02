#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<typeinfo>

using namespace std;

class A {
	
	string s;
	public:
		A (string x) {
			s=x;
		}
		string getS() {
			return s;
		}
		bool doppia() {
			for(int i=0;i<s.length()-1;i++) {
				for(int j=i+1;s.length();j++) {
					if(s[i]==s[j]) return true;
				}
			}
			return false;
		}
		virtual string nuova()=0;
		
		ostream& put(ostream& os) {
			return os<<"A="<<getS();
		}
};

ostream& operator<< (ostream& os,A& stringa) {
	return stringa.put(os);
}

class C:public A {
	protected:
		char c;
	public:
		C(string z,char h): A(z){
		}
		string nuova() {
			string str = "";
			str +=getS()[0];
			for(int i=0;i<getS().length()-1;i++) {
				str += '*';
			}
			return str;
		}
		
};


class D:public C {
	public:
		D(string p, char k):C(p,k) {
		}
		string nuova(short x) {
			string l="";
			l+=c;
			for(int i=0;i<x;i++) {
				l+=getS()[i]+1;
			}
			return l;
		}
		
};

class B: public A {
	
	int y;
	public:
		B(string j,int w) :A(j){
		}
		bool doppia() {
			char k;
			for(int i=0;i<getS().length()-1;i++) {
				if(getS()[i]==('a' || 'e' || 'i' || 'o' || 'u')) {
					k=getS()[i];
					for(int q=i+1;q<getS().length();q++) {
						if (k==getS()[q]) return true;
					}
				}
			}
			return false;
		}
		string nuova() {
			if (y%3==0) {
				return getS().substr(getS().length()-3,getS().length());
			} else {
				return getS().substr(0,3);
			}
		}
};
const int DIM=30;
int main() {
	A* vett[DIM];
	srand(111222333);
	for(int i=0;i<DIM;i++) {
		int p=rand()%5+3;
		string str="";
		for(int j=0;j<p;j++) {
			str+=(char) ('a'+rand ()%26);
		}
		if (rand()%2==1) {
				vett[i]=new D(str,(char)('a'+rand ()%26));
		} else {
			vett[i]=new B(str, rand()%15);
		}
	}
	for(int i=0;i<DIM;i++) {
		cout<<*vett[i];
		cout<<endl;
	}
	string stringa = "";
	for(int i=0;i<DIM;i++) {
		for (int j=0; j < 2; j++){
			stringa+= vett[i]->nuova()[j];
		}
	}
	cout << "nuova()= " << stringa;
	cout<<endl;
	
	//esercizio1
	string stringa2="";
	for(int i=0;i<DIM;i++) {
		if(typeid(*vett[i])==typeid(D)){
		
			for(int j=0;j<3;j++) {
				stringa2+=vett[i]->nuova()[j];
			}
		}
	}
	cout << "nuova(3)= " << stringa2;

	return 0;
}

