/*************************************
   Nome: Alessio Sferro
   File: main.cpp
   Data: 2015-12-14-16.51
*************************************/

/*
    Esercizio 1:
        Scrivere un metodo che prenda in input una matrice quadrata A di interi e restituisca
        un bool che indichi se esiste una riga contenente tre numeri consecutivi la cui somma
        è uguale alla somma di due numeri, non necessariamente consecutivi, di una stessa
        colonna di A.
*/


#include <iostream>
using namespace std;

const int DIM = 4;

bool metodo(int [][DIM]);

int main()
{
    srand(time(NULL));
    int matrix[][DIM] = {{11, 20, 30, 12},
                         {84, 76, 71, 54},
                         {21, 10, 20, 30},
                         {33, 43, 40, 40}};

    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    if(metodo(matrix))
        cout << "\nSUCCESS: Riga trovata!" << endl;
    else
        cout << "\nFAIL: Non esiste alcuna riga di questo tipo..." << endl;

    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}

bool metodo(int A[][DIM]){
    int i = 0;
    while(i < DIM){
        int j = 0;
        while(j < DIM-2){
            int y = 0, sum1 = A[i][j] + A[i][j+1] + A[i][j+2];
            while(y < DIM){
                int x = 0;
                while(x < DIM-1){
                    int k = x+1;
                    while(k < DIM){
                        int sum2 = A[x][y] + A[k][y];
                        if(sum1 == sum2){
                            // cout << i << " " << j << endl; PER DEBUG
                            // cout << x << " " << k << " " << y << endl; PER DEBUG
                            return true;
                        }
                        else k++;
                    }
                    x++;
                }
                y++;
            }
            j++;
        }
        i++;
    }
    return false;
}

