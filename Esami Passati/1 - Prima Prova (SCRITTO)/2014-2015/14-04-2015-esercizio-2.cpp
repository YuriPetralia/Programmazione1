/*************************************
   Nome: Alessio Sferro
   File: main.cpp
   Data: 2015-12-14-17.21
*************************************/

/*
    Esercizio 2:
        Scrivere un metodo che prenda in input una stringa S, e due indici i e j
        (0 ≤ i < j < lenght(S)), e restituisca una nuova stringa T ottenuta da S
        invertendo i caratteri contenuti nell’intervallo [i, j].
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string metodo(string, int, int);

int main(){
    string s;
    cout << "Inserisci la stringa: ";
    cin >> s;

    int i, j;
    cout << "Inserisci l'indice i: ";
    cin >> i;
    cout << "Inserisci l'indice j: ";
    cin >> j;

    cout << "\nStringa risultante: " << metodo(s, i, j) << endl;

    cin.ignore();
    cout << "\nPremi INVIO per continuare...  ";
    cin.get();
    return 0;
}

string metodo(string s, int i, int j){
    string t = "";
    int k = j-i+1, m = 0;
    while(m < k){
        t += s[j--];
        m++;
    }
    return t;
}

