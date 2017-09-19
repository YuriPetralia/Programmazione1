/*************************************
   Nome: Alessio Sferro
   Titolo: main.cpp
   Data: 13/12/2015
*************************************/

/*
    Esercizio 2:
        Scrivere un metodo che prenda in input una stringa S, e restituisca un bool
        che indichi se in S è contenuta una sottostringa palindroma di lunghezza maggiore di 3.
*/

#include <iostream>

using namespace std;

bool metodo(string);
bool checkPalindroma(string s);
string findPal(string s);

int main()
{
    string s = "vaabbaevnuarai";

    cout << "Stringa da controllare: " << s << endl;

    if(metodo(s))
        cout << "\nSUCCESS: Esiste una sottostringa palindroma di lunghezza > 3!" << endl;
    else
        cout << "\nFAIL: Non esiste alcuna sottostringa palindroma..." << endl;
    return 0;
}

bool metodo(string s){
    int i = 0, k = s.length();
    while(k - i > 3){
        int j = i+1;
        while(j < k){
            if(s[i] == s[j] && j-i+1 > 3)
                if(checkPalindroma(s.substr(i, j-i+1))) return true;
            j++;
        }
        i++;
    }
    return false;
}

bool checkPalindroma(string s){
    int k = s.length();
    int i = 0, j = k-1;
    while(i < k/2){
        if(s[i] == s[j])
            i++, j--;
        else
            return false;
    }
    return true;
}
