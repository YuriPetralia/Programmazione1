// Programma = Convertire un numero da binario in decimale
// Autore = Michael Platania
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main ()
{
string numeri_binari ;                           //numero binario 
int contatore = 0;                               //contatori per i cicli
int contatore2 = 0;                                          
int lunghezza_binario;                           //lunghezza numero binario
int somma=0;                                     //somma dei vari lenght per dare il decimale
cout<<"Digita il numero binario di cui vuoi conoscere il valore in decimale"<<endl;
cin>> numeri_binari;                                               //diamo il binario alla nostra variabile
lunghezza_binario=numeri_binari.length();                          //vediamo quanto è lungo
string primo_numero[lunghezza_binario];                            //creiamo un array della lunghezza del nostro binario
int primo_Numero[lunghezza_binario];
//assegnamento dell array
while (contatore<lunghezza_binario)                                
      {
      primo_numero[contatore]=numeri_binari.substr(contatore,1);
      contatore++ ;
      }         
      contatore--;      //sottraggo -1 perche nn abbiamo l'arrai n+1 ma n poichè dal while x uscire necessitavamo di n+1  
while (contatore2<lunghezza_binario)
      {
      if (primo_numero [contatore] == "1")
         {
         primo_Numero[contatore]=  pow(2,contatore2);            //il secondo contatore mi serve perche il 2 lo devo elevare alla 0 poi 1 poi 2 ecc.
         somma = somma + primo_Numero[contatore];
         }
    
      contatore--;
      contatore2++;
      }
 cout<<"Il numero in decimali e'" <<somma<<endl;
 system ("PAUSE");
 return 0;
}
