#include <cstdlib>
#include <iostream>
#include <string>                  
                        // Gabriele Cubeda
using namespace std;

int main()
{
    string Parole[] = {"abc", "defgh", "fbbcurg", "ecdsfgfgfg"};
    string subst;
for (bool t = true; t; ) //ciclo per tentativi di trovare la substring (infinito)
{ 
     cout << "Inserire subst = "; 
     cin >> subst; // inserisco la substring
     cout << endl;
     
   for (short i=0; i<4; i++) // selezione parole da controllare
   {
       for (short start=0; start<(Parole[i].size()); start++)
       /* in quale posizione della parola cominciare il controllo
        se start (posizione dentro la parola dal quale inizio il controllo)
        è maggiore della dimensione della parola allora esco dal ciclo
        altrimenti crasha il programma*/
       {
           
           if (subst == Parole[i].substr(start, subst.size()))
           /*per ogni posizione della parola, controllo se la substring che
           ho inserito coincide con qualche parte della parola controllata
           e, se così fosse, esco da tutti i cicli*/
           {
           cout << "la substring coincide con " << Parole[i] << endl;
           i = 4;
           t = false;
           break;
           }
       }
   }    
}   
    system("PAUSE");
    return EXIT_SUCCESS;
}
                         // Gabriele Cubeda
