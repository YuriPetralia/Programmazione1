/*************************************
   Nome: Alessio Sferro
   File: main.cpp
   Data: 2016-02-02-20.04
*************************************/
 
/*
    Esercizio 1:
        Scrivere un metodo che prenda in input una matrice quadrata A (nxn) di short e
        restituisca un bool che indichi se esistono in A due diagonali della stessa
        lunghezza parallele alla diagonale principale tali che l'una sia l'inversa
        dell'altra.
*/
 
#include <iostream>
using namespace std;
 
const int DIM = 5;
 
bool metodo(short mat[][DIM]);
 
int main()
{
    short mat[][DIM] = {{30, 50, 98, 43, 83},
                        {79, 84, 33, 94, 17},
                        {20, 8, 79, 65, 20},
                        {88, 94, 54, 64, 32},
                        {21, 74, 98, 65, 4}};
 
    cout << "MATRICE:" << endl;
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
 
    if(metodo(mat))
        cout << "\nSUCCESS: Esistono due diagonali della forma cercata!" << endl;
    else
        cout << "\nFAIL: Non esistono le diagonali ricercate..." << endl;
 
    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}
 
bool metodo(short matrix[][DIM]){
    for(int x = 1, k = DIM-2; x < DIM; x++, k--){
        int y = 0, c = DIM-1;
        bool notFound = false;
        for(int z = x, j = k; z < DIM && !notFound; z++, j--){
            if(matrix[z][y] == matrix[j][c]){
                if(z == DIM-1) return true;
                y++, c--;
            }else notFound = true;
        }
    }
    return false;
}

