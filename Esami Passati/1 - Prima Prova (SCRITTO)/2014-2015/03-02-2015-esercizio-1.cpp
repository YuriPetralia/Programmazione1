/*************************************
   Nome: Alessio Sferro
   Titolo: main.cpp
   Data: 16/12/2015
*************************************/

/*
    Esercizio 1:
        Scrivere un metodo che prenda come parametro formale una matrice di numeri
        reali n x m, esamini solamente gli elementi presenti nella terza colonna,
        e restituisca in output il prodotto dei due numeri più “vicini” tra loro
        (cioè la cui differenza in valore assoluto è minima).
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int DIM = 5;

double metodo(double A[][DIM]);

int main(){
    srand(time(NULL));
    double mat[DIM][DIM];

    cout << "MATRICE DI DOUBLE:\n" << endl;
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            mat[i][j] = (rand()%1000+1)/100.0;
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nProdotto dei numeri: " << metodo(mat) << endl;

    cout << "\nPremi INVIO per continuare...";
    cin.get();
    return 0;
}

double metodo(double A[][DIM]){
    int y = 2, mx, my;
    double minDif = 0;
    bool stop = false;
    for(int i = 0; i < DIM-1; i++){
        for(int j = i+1; j < DIM; j++){
            double diff = abs(A[i][y] - A[j][y]);
            if(!stop || minDif > diff){
                minDif = diff;
                mx = i, my = j;
                stop = true;
            }
        }
    }

    cout << "\nIndici: A[" << mx << "][" << y << "] e A[" << my << "][" << y << "]" << endl;
    cout << "\nDistanza tra i due numeri: " << minDif;
    return A[mx][y] * A[my][y];
}
