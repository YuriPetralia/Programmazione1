/*************************************
   Nome: Alessio Sferro
   Titolo: main.cpp
   Data: 14/12/2015
*************************************/

/*
    Esercizio 2:
        Scrivere un metodo che prenda in input una matrice quadrata A di caratteri e due
        indici i e j, con i > j e restituisca una stringa ottenuta dalla concatenazione
        di tutti i caratteri presenti nella diagonale dell'elemento a(ij) parallela a
        quella principale.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 10;

string metodo(char [][DIM], int, int);

int main()
{
    srand(time(NULL));
    char matrix[DIM][DIM];
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            matrix[i][j] = char(rand()%26+97);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int i, j;
    cout << "\nInserisci i e j (i > j obbligatoriamente!)" << endl;
    do{
        cout << "Inserisci i: ";
        cin >> i;
        cout << "Inserisci j: ";
        cin >> j;
    }while(i < j);

    cout << "\nStringa risultante: " << metodo(matrix, i, j) << endl;

    cin.ignore();
    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}

string metodo(char A[][DIM], int i, int j){
    while(j > 0)
        i--, j--;

    string s = "";
    while(i < DIM)
        s += A[i++][j++];

    return s;
}

