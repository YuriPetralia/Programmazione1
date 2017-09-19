/*************************************
   Nome: Alessio Sferro
   Titolo: main.cpp
   Data: 14/12/2015
*************************************/

/*
    Esercizio 1:
        Scrivere un metodo che prenda in input una matrice di interi, e
        restituisca un bool se esistono due estratti della matrice la cui
        media è uguale. Un estratto è una porzione della matrice ottenuta
        da quattro elementi contigui disposti a quadrato.
*/

#include <iostream>

using namespace std;

const int DIM  = 4;

bool metodo(int [][DIM]);
float mediaEstratto(int [][DIM], int, int);

int main()
{
    int matrix[][DIM] = {{5, 8, 9, 7},
                         {2, 1, 3, 4},
                         {8, 3, 2, 4},
                         {3, 1, 9, 8}};

    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    if(metodo(matrix))
        cout << "\nSUCCESS: Estratti con media uguale!" << endl;
    else
        cout << "\nFAIL: Non esistono estratti con media uguale..." << endl;

    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}

bool metodo(int A[][DIM]){
    int x = 0;
    while(x < DIM-1){
        int y = 0;
        while(y < DIM-1){
            // cout << "->"; per debug
            float mediaTemp = mediaEstratto(A, x, y);
            int i = x, j = y+1;
            while(i < DIM-1){
                while(j < DIM-1){
                    if(mediaTemp == mediaEstratto(A, i, j))
                        return true;
                    else j++;
                }
                j = 0, i++;
            }
            y++;
        }
        x++;
    }
    return false;
}

float mediaEstratto(int A[][DIM], int x, int y){
    // cout << (A[x][y] + A[x+1][y] + A[x][y+1] + A[x+1][y+1]) / 4.0 << endl; per debug
    return (A[x][y] + A[x+1][y] + A[x][y+1] + A[x+1][y+1]) / 4.0;
}

