/*************************************
   Nome: Alessio Sferro
   Titolo: main.cpp
   Data: 14/12/2015
*************************************/

/*
    Esercizio 2:
        Scrivere un metodo che prenda in input una stringa S e un carattere C e restituisca
        una nuova stringa da cui sono state rimosse tutte le occorrenze di C.
*/

#include <iostream>

using namespace std;

string metodo(string s, char c);

int main()
{
    string s;
    cout << "Inserisci una stringa: ";
    getline(cin, s);

    char c;
    cout << "Carattere da eliminare: ";
    cin >> c;

    cout << "\nStringa iniziale: " << s << endl;
    cout << "Stringa senza '" << c << "': " << metodo(s, c) << endl;

    cin.ignore();
    cout << "\nPremi INVIO per continuare... ";
    cin.get();
    return 0;
}

string metodo(string s, char c){
    /* Variante con erase()
    int k = s.length(), i = 0;
    while(i < k){
        if(s[i] == c)
            s.erase(i, 1);
        else i++;
    }
    return s;
    */  

    int k = s.length(), i = 0;
    string g = "";
    while(i < k){
        if(s[i] != c)
            g += s[i];
        i++;
    }
    return g;
}
