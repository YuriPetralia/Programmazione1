///////////////////////////
// Posted By IVAN JHAHY //
/////////////////////////
// Programma per riconoscere se un numero è pari o dispari
#include <iostream>
 
using namespace std;
 
int main(){
        int x;
       
        cout << "\nInserire un numero per stabilire se sia pari o dispari\n";
        cin >> x;
       
        if(x%2==0)
                cout << "\nIl numero e' PARI\n";
        else
                cout << "\nIl numero e' DISPARI\n";
        return 0;
        
       
}
