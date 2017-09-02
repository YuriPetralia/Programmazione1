/*Es1. Scrivere un metodo che prenda in input due array A e B di int
di lunghezza n ed m rispettivamente, e restituisca una matrice
di dimensione nxm di int
contenente il prodotto AxB se in A tutti gli elementi sono distinti e
la matrice identità altrimenti;*/

#include <cstdlib>
#include <iostream>
#include <ctime>
                      // Gabriele Cubeda
using namespace std;

int main()
{
    srand(time(NULL));
    int i, j, n = 5, m = 5,
        A[n], B[m], C[n][m];

cout << endl << "A ha i seguenti valori = "; // inizializzazione vettori
for (i=0; i<n; i++){
A[i] = rand()%10+1;
cout << A[i] << " ";}

cout << endl << endl << "B ha i seguenti valori = ";
for (j=0; j<m; j++){
B[j] = rand()%10+1;
cout << B[j] << " ";}
cout << endl;

    for (i=0; i<n; i++) // controllo elementi in A
         for (j=i+1; j<m; j++)
         if (A[i] == A[j]) // se ci sono elementi uguali, stampa matrice identita'
         {
    cout << endl << "Trovati elementi uguali in A. Matrice identita':" << endl << endl;
                  for (i=0; i<n; i++)
                       for (j=0; j<m; j++)
                       {
                           if (i==j) C[i][j] = 1;
                           else C[i][j] = 0;
                       }
         }
         if (i==n) //se il controllo e' finito, stampa il prodotto A x B
         {
         cout << endl << "Nessun elemento uguale in A. Prodotto dei vettori" << endl << endl;
                     for (i=0; i<n; i++)
                        for (j=0; j<m; j++)
                        C[i][j]= A[i]*B[j];
         }
for (i=0; i<n; i++){   // visualizzazione matrice C (identita' o AxB)
   for (j=0; j<m; j++)
    cout << C[i][j] << " ";
    cout << endl << endl;}




    system("PAUSE");
    return EXIT_SUCCESS;
}
                         // Gabriele Cubeda
