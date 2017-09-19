/*************************************
   Nome: Alessio Sferro
   File: main.cpp
   Data: 2015-12-17-18.48
*************************************/
 
/*
    Esercizio 2:
        Scrivere un metodo che prenda in input un vettore di interi e restituisca un bool
        che indichi se esistono due numeri "più vicini" (cioè differenza in valore assoluto
        minima) la cui somma è un multiplo di 7.
*/
 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
 
using namespace std;
 
const int DIM = 10;
 
bool metodo(int vett[]);
 
int main()
{
    srand(time(NULL));
    int vett[DIM];
    for(int i = 0; i < DIM; i++){
        vett[i] = rand()%100+1;
        cout << vett[i] << " ";
    }
 
    if(metodo(vett))
        cout << "\nSUCCESS: La somma dei numeri piu' vicini e' un multiplo di 7!" << endl;
    else
        cout << "\n\nFAIL: La somma dei numeri piu' vicini non e' un multiplo di 7." << endl;
 
    return 0;
}
 
bool metodo(int vett[]){
    int x = 0, i = 1, a = x, b = i;
    int minDif = abs(vett[x] - vett[i]);
    while(x < DIM-1){
        i = x + 1;
        while(i < DIM){
            int dif = abs(vett[x] - vett[i]);
            if(minDif > dif){
                minDif = dif;
                a = x;
                b = i;
            }
            i++;
        }
        x++;
    }
    if((vett[a] + vett[b]) % 7 == 0){
        cout << "\n\nIndici: " << a << " e " << b;
        return true;
    }
    else return false;
}

