/*************************************
   Nome: Alessio Sferro
   File: main.cpp
   Data: 2016-02-16-20.50
*************************************/
 
/*
    Esercizio 2:
        Scrivere un metodo che prenda in input un vettore di stringhe S
        e restituisca un valore booleano che indichi se esiste una
        qualunque sottostringa in comune tra loro, di almeno tre caratteri
*/
 
#include <iostream>
using namespace std;
 
bool metodo(string [], const int);
 
int main(){
    const int DIM = 5;
    string vett[DIM] = {"aaaa", "bffbeee", "ccc", "debbb", "eccabbba"};
 
    cout << "Stampo l'array:" << endl;
    for(int i = 0; i < DIM; i++){
        cout << i+1 << ") " << vett[i] << endl;
    }
 
    if(metodo(vett, DIM))
        cout << "\nSUCCESS: sottostringa trovata!" << endl;
    else
        cout << "\nFAIL: sottostringa non trovata... " << endl;
 
    cout << "\nPremi INVIO per continuare...  ";
    cin.get();
    return 0;
}
 
bool metodo(string S[], const int DIM){
    for(int i = 0; i < DIM-1; i++){
        int k = S[i].length();
        for(int g = 3; g < k; g++){
            for(int j = 0; j < k-g+1; j++){
                string sub1 = S[i].substr(j, g);
                for(int h = i+1; h < DIM; h++){
                    int p = S[h].length();
                    for(int x = 0; x < p-g+1; x++){
                        string sub2 = S[h].substr(x, g);
                        if(sub1 == sub2) return true;
                    }
                }
            }
        }
    }
    return false;
}
