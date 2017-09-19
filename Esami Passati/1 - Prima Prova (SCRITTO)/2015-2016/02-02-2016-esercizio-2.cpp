/*************************************
   Nome: Alessio Sferro
   File: main.cpp
   Data: 2016-02-02-20.25
*************************************/
 
/*
    Esercizio 2:
        Scrivere un metodo che prenda in input una matrice A di nxm stringhe ed ordini in senso
        non decrescente ogni singola colonna di A.
*/
 
 
#include <iostream>
#include <cstdlib>
#include <ctime>
 
const int DIM1 = 5, DIM2 = 6;
 
using namespace std;
 
void metodo(string matrix[][DIM2]);
 
int main()
{
    srand(time(NULL));
 
    string matrix[DIM1][DIM2];
 
    cout << "MATRICE NON RIORDINATA:" << endl;
    for(int x = 0; x < DIM1; x++){
        for(int y = 0; y < DIM2; y++){
            int k = rand()%5+3;
            for(int i = 0; i < k; i++){
                matrix[x][y] += char(rand()%4+97);
            }
            cout << matrix[x][y] << " ";
        }
        cout << endl;
    }
 
    metodo(matrix);
 
    cout << "\nMATRICE RIORDINATA:" << endl;
    for(int x = 0; x < DIM1; x++){
        for(int y = 0; y < DIM2; y++){
            cout << matrix[x][y] << " ";
        }
        cout << endl;
    }
    return 0;
}
 
void metodo(string matrix[][DIM2]){
    for(int y = 0; y < DIM2; y++){
        for(int x = 0; x < DIM1-1; x++){
            for(int p = x + 1; p < DIM1; p++){
                if(matrix[x][y] > matrix[p][y]){
                    string s = matrix[x][y];
                    matrix[x][y] = matrix[p][y];
                    matrix[p][y] = s;
                }
            }
        }
    }
}

