/*************************************
   Nome: Alessio Sferro
   File: main.cpp
   Data: 2015-12-14-20.54
*************************************/

/*
    Esercizio 2:
        Scrivere un metodo che prenda in input un array di n numeri interi e restituisca
        true se sono presenti due valori che sono l'uno il doppio dell'altro, false altrimenti.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

bool metodo(int [], const int);

int main(){
    srand(time(NULL));


    int x;
    cout << "Inserisci la dimensione dell'array: ";
    cin >> x;
    const int DIM = x;

    int vett[DIM];
    x = 0;

    cout << "\n";
    while(x < DIM){
        vett[x] = rand()%20+1;
        cout << vett[x++] << " ";
    }

    if(metodo(vett, DIM))
        cout << "\nSUCCESS: Presenti due valori l'uno il doppio dell'altro!" << endl;
    else
        cout << "\nFAIL: Valori non presenti." << endl;

    cin.ignore();
    cout << "\nPremi INVIO per continuare...  ";
    cin.get();
    return 0;
}

bool metodo(int A[], const int DIM){
    int x = 0;
    while(x < DIM-1){
        int k = x+1;
        while(k < DIM){
            if(A[x] == 2*A[k] || 2*A[x] == A[k]){
                cout << "\nIndici: " << x << " e " << k << endl;
                return true;
            }
            else k++;
        }
        x++;
    }
    return false;
}

