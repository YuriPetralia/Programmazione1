#include <iostream>
#include <cstdlib>
#define DIM 50

using namespace std;

class A {
    
private:
    string x;
    
public:
    A(string _x) {x = _x;}
    string getX(){return x;}
    string virtual select() = 0;
    bool moreThan3(){
        for(int i = 0; i < x.length(); i++) {
            int cont = 0;
            for(int j = 1; j < x.length(); j++) {              
                if(x.at(i) == x.at(j)) {
                    cont++;
                }
            }
            if(cont == 3) {
                return true;              
            }
        }
    }   
    virtual ostream& output(ostream& out) = 0;   
};

class B : public A {
    
private:
    string y;
    float f;
    
public:
    B(string s, float _f) : A(s.substr(0,9)) { 
        for(int j = 10; j < s.length(); j++) {
            y += s.at(j);
        }
        f = _f;
    }
    char extract(){
        int indice = (int)(f*10.0f)%10;
        return y.at(indice);
    }
    string select(){
        string stringa = "";
        for (int i = 0; i < getX().length(); i++) {
            if (getX().at(i) == 'a' || getX().at(i) == 'e' ||
                    getX().at(i) == 'i' || getX().at(i) == 'o' ||
                    getX().at(i) == 'u') {
                stringa += getX().at(i);
            }
        }
        for (int j = 0; j < y.length(); j++) {
            if (y.at(j) == 'a' || y.at(j) == 'e' || y.at(j) == 'i' ||
                    y.at(j) == 'o' || y.at(j) == 'u') {
                stringa += y.at(j);
            }
        }
        return stringa;
    }
    ostream& output(ostream& out){        
        out << getX() << endl;
        return out;
    }    
};

class C : public A {
    
private:
    short* b;
    short n;
    
public:
    C(string s) : A(s.substr(0, 9)){ 
        n = s.length();
        b = new short[n];
        for(int i = 0; i < n; i++) {                   
            b[i] = s[i]%5;           
        }       
    }
    ~C() {delete[] b;}
    string select(){      
        string stringa = "";
        for(int i = 0; i < getX().length(); i++) {
            stringa += getX()[b[i]];            
        }        
    }
    ostream& output(ostream& out){        
    	out << getX() << endl; 
    	for(int i = 0; i < n; i++) {
       		out << b[i] << " "; 
        }
    	cout << endl;
    }    
};

ostream& operator<<(ostream& stream, A* a) {
    
    return a->output(stream);
    
}


int main(int argc, char** argv) {

    srand(111222333);
    A* vett[DIM];
    string extract = "";
    int moreThan3 = 0;
    B* b;
  
    for(int i = 0; i < DIM; i++) {       
        string str = "";
        for(int j = 0; j < 20; j++) {
            str += (char) ('a' +rand()%12);
            if(rand()%2 == 1) {
                vett[i] = new B(str, (float)rand()/RAND_MAX);
                } else {
                vett[i] = new C(str); 
                }           
                //if(typeid (vett[i]) == (B)) {
                //    b = vett[i];
                //    extract += b.extract();
                //}
            }
            cout << vett[i];
            if (vett[i]->moreThan3()== true) {
            cout << "Stringa moreThan3 all'indice: " << i << endl;                    
            }
        }
    
  /*  string select = "";
    select += vett[13]->select() + vett[48]->select();
    cout << "La stringa ottenuta concatenando select(13) e (48) e' " << select << endl;
    cout << "La stringa ottenuta con extract e' : " << extract << endl;*/
    return 0;
}
    
