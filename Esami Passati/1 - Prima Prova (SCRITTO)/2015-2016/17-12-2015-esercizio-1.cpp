/*************************************
   Nome: Alessio Sferro
   File: main.cpp
   Data: 2015-12-17-18.36
*************************************/
 
/*
    Esercizio 1:
        Scrivere un metodo che prenda in input una matrice quadrata di stringhe nxn e restituisca
        true se esiste una stringa nella diagonale secondaria avente i primi tre caratteri
        coincidenti con gli ultimi tre di una qualunque s tringa nella diagonale principale,
        false altrimenti.
*/
 
#include <iostream>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
const int DIM = 4;
 
bool metodo(string M[][DIM]);
bool confronto(string M[][DIM], string s);
 
int main(){;
    srand(time(NULL));
    string mat[DIM][DIM] = {{"aeifj", "gurhau", "ubvrva", "ngbur"},
                            {"vnura", "pcasd", "asdqm", "bijqmw"},
                            {"cpqoe", "vmiqm", "biqjm", "viqjwq"},
                            {"asdqw", "bvuqw", "bppoqw", "bnfsd"}};
 
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
 
    if(metodo(mat))
        cout << "\nSUCCESS: la diagonale principale contiene la sottostringa!" << endl;
    else
        cout << "\nFAIL: Nessuna sottostringa trovata." << endl;
 
    cout << "\nPremi INVIO per continuare...  ";
    cin.get();
    return 0;
}
 
bool metodo(string M[][DIM]){
    int x = 0, y = DIM-1;
    while(y >= 0){
        string k = M[x][y].substr(0, 3);
        if(confronto(M, k)) return true;
        else x++, y--;
    }
    return false;
}
 
bool confronto(string M[][DIM], string s){
    int x = 0, y = 0;
    while(y < DIM){
        int j = M[x][y].length();
        if(M[x][y].substr(j-3, 3) == s) return true;
        else y++, x++;
    }
    return false;
}
