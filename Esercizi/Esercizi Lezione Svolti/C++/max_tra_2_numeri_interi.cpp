///////////////////////////
// Posted By IVAN JHAHY //
/////////////////////////
// Programma per calcolare il massimo tra 2 numeri.
#include <iostream>
 
using namespace std;
 
int main(){
        int x, y, z;
       
        cout << "\nInserire un valore per x\n";
        cin >> x;
        cout << "\nInserire un valore per y\n";
        cin >> y;
        z=x-y;
       
        if (z==0)
                cout <<"/nI due numeri sono uguali\n";
        else if (z>0)
                cout <<"\nIl numero " << x << " e' piu' grande del numero " << y <<"\n";
        else
                cout <<"\nIl numero " << y << " e' piu' grande del numero " << x <<"\n";
        return 0;
               
}
