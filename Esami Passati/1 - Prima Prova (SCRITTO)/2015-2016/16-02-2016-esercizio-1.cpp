/*************************************
   Nome: Alessio Sferro
   File: main.cpp
   Data: 2016-02-16-20.53
*************************************/
 
/*
    Esercizio 1:
        Scrivere un metodo che prenda in input una matrice nxm di int, e restituisca
        un bool che indichi se esiste in una colonna una sequenza palindroma di numeri (es: 45254)
*/
 
#include <iostream>
 
using namespace std;
 
const int DIM1 = 5, DIM2 = 6;
 
bool metodo(int [DIM1][DIM2]);
 
int main(){
    int A[][DIM2] = {{21, 53, 68, 18, 45, 41},
                     {64, 22, 34, 20, 74, 65},
                     {24, 65, 19, 19, 32, 33},
                     {17, 81, 20, 24, 57, 64},
                     {18, 30, 19, 23, 96, 79}};
 
    cout << "Stampo la matrice:" << endl;
    for(int i = 0; i < DIM1; i++){
        for(int j = 0; j < DIM2; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
 
    if(metodo(A))
        cout << "\nSUCCESS: Colonna con sequenze palindrome trovata!" << endl;
    else
        cout << "\nFAIL: Colonna non trovata... " << endl;
 
    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}
 
bool metodo(int A[][DIM2]){
    for(int j = 0; j < DIM2; j++){
        bool found = false;
        for(int k = 2; k <= DIM1; k++){
            for(int p = 0; p < DIM1-k+1; p++){
                for(int i = p, x = p+k-1; i < (i+x)/2.0; i++, x--){
                    if(A[i][j] == A[x][j]) found = true;
                    else found = false;
                }
                if(found) return true;
            }
        }
    }
    return false;
}

