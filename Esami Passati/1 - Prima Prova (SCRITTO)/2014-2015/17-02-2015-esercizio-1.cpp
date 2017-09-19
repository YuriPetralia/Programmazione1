/*************************************
   Nome: Alessio Sferro
   Titolo: main.cpp
   Data: 12/12/2015
*************************************/

/*
    Esercizio 1:
        Scrivere un metodo che prenda in input una matrice A di short e restituisca
        un bool che indichi se esistono in A due righe tali che l’una sia una permutazione
        dell’altra.
        N.B.: Ogni singola riga contiene elementi distinti e non è possibile
        ordinare le righe!
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM1 = 4, DIM2 = 5;

bool metodo(short A[][DIM2]);
bool perm(short A[][DIM2], int i, int j);

int main(){
    short matrix[][DIM2] = {{26, 78, 84, 73, 87},
                            {31, 15, 21, 35, 42},
                            {77, 57, 28, 86, 51},
                            {42, 21, 35, 15, 31}};

    cout << "STAMPO MATRICE\n";
    for(int x = 0; x < DIM1; x++){
        for(int y = 0; y < DIM2; y++)
            cout << matrix[x][y] << " ";
        cout << endl;
    }

    if(metodo(matrix))
        cout << "\nSUCCESS: Esistono due righe con i requisiti cercati!" << endl;
    else
        cout << "\nFAIL: Non esiste alcuna riga con i requisiti cercati..." << endl;

    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}

bool metodo(short A[][DIM2]){
    for(int i = 0; i < DIM1-1; i++){
        for(int j = i+1; j < DIM1; j++){
            if(perm(A, i, j)) return true;
        }
    }
    return false;
}

bool perm(short A[][DIM2], int i, int j){
    int a = 0, b = 0;
    while(b < DIM2){
        if(A[i][a] == A[j][b]){
            a++, b = 0;
            if(a == DIM2) return true;
        }else b++;
    }
    return false;
}
