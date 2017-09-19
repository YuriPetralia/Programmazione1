/*************************************
   Nome: Alessio Sferro
   Titolo: main.cpp
   Data: 14/12/2015
*************************************/

/*
    Esercizio 1:
        Scrivere un metodo che prenda in input una matrice quadrata di interi A, e restituisca
        true se esiste una diagonale, parallela alla diagonale principale, la cui somma degli
        elementi è un multiplo di 7; false altrimenti.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 4;

bool metodo(int [][DIM]);
int somma(int [][DIM], int, int);

int main()
{
    srand(time(NULL));
    int matrix[][DIM] = {{34, 51, 82, 41},
                         {81, 23, 75, 16},
                         {14, 29, 38, 62},
                         {71, 99, 84, 53}};

    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    if(metodo(matrix))
        cout << "\nSUCCESS: La diagonale ricercata esiste!" << endl;
    else
        cout << "\nFAIL: La diagonale ricercata non esiste..." << endl;

    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}

bool metodo(int A[][DIM]){
    int x = 0, y = 0;
    if(somma(A, x, y) % 7 == 0) return true;
    else{
        int i = 1, j = 1;
        while(i < DIM){
            if(somma(A, i, y) % 7 == 0 || somma(A, x, j) % 7 == 0) return true;
            else i++, j++;
        }
    }
    return false;
}

int somma(int A[][DIM], int i, int j){
    int sum = 0;
    while(i < DIM && j < DIM)
        sum += A[i++][j++];
    return sum;
}
