/*************************************
   Nome: Alessio Sferro
   Titolo: main.cpp
   Data: 12/12/2015
*************************************/

/*
    Esercizio 2:
        Scrivere un metodo che prende in input una matrice quadrata A di n x n
        puntatori a stringhe, e restituisca un puntatore ad una stringa ottenuta
        concatenando tutti i caratteri centrali delle stringhe di lunghezza dispari
        presenti nella diagonale secondaria di A.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 4;

string* metodo(string**);
void printMatrix(string**&);

int main()
{
    srand(time(NULL));
    string** matrix;
    printMatrix(matrix);

    cout << "\nStringa generata: " << *metodo(matrix) << endl;
    return 0;
}

void printMatrix(string** &A){
    A = new string* [DIM];
    for(int i = 0; i < DIM; i++)
        A[i] = new string [DIM];

    cout << "MATRICE:\n";
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            int z = rand()%5+3, k = 0;
            while(k < z){
                A[i][j] += char(rand()%26+97);
                k++;
            }
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

string* metodo(string** A){
    string s = "";
    string* p = &s;

    int y = DIM-1, x = 0;
    while(y >= 0){
        int k = A[x][y].length();
        if(k % 2 != 0){
            int z = k/2;
            s += A[x][y][z];
        }
        y--, x++;
    }
    return p;
}

