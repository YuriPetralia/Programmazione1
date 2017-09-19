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

const int DIM = 4;

bool metodo(short A[][DIM]);

int main(){
    short matrix[][DIM] = {{26, 78, 84, 73},
                           {31, 15, 21, 35},
                           {77, 57, 28, 86},
                           {21, 35, 15, 31}};

    cout << "STAMPO MATRICE\n";
    for(int x = 0; x < DIM; x++){
        for(int y = 0; y < DIM; y++)
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

bool metodo(short A[][DIM]){
    for(int i = 0; i < DIM-1; i++){
        bool lastRow = false;
        int x = i+1;
        while(!lastRow){
            bool notFound = false;
            while(!notFound){
                int j = 0, y = 0;
                bool stop = false;
                while(!stop){
                    if(A[i][j] == A[x][y]){
                        j++, y = 0;
                        if(j == DIM) return true;
                    }else{
                        y++;
                        if(y == DIM) stop = true;
                    }
                }
                notFound = true;
                x++;
            }
            if(x == DIM) lastRow = true;
        }
    }
    return false;
}
