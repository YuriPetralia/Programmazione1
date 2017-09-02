#include <cstdlib>
#include <iostream>
#include <time.h>
                      // Gabriele Cubeda
using namespace std;

int main()
{
    srand(time(NULL));
    int x = rand()%5+1, y = rand()%5+1, z = rand()%5+1; // grandezza vettori
    int A[x], B[y], C[z]; // vettori
    int i = 0, j = 0, k = 0; // contatori
    int comval; // common value o valore comune
    cout << "A[] e' " << x << ", B[] e' " << y << ", C[] e' " << z << endl;
    
    while (i<x || j<y || k<z) //inizializzazione vettori
    {
     if (i<x) {
     A[i] = (rand()%5+1);
     cout << "A[" << i << "] e' = " << A[i] << endl;     
     i++; }
     
     if (j<y) {
     B[j] = (rand()%5+1);
     cout << "B[" << j << "] e' = " << B[j] << endl;     
     j++; }
     
     if (k<z) {
     C[k] = (rand()%5+1);
     cout << "C[" << k << "] e' = " << C[k] << endl;     
     k++; }
     } // fine inizializzazione vettori
     j = 0;
while (j<y)
{
       i = 0;
       while (i<x)
       {
        comval = A[i];
           if (comval == B[j])
           {  
              k = 0;
              while (comval != C[k] && k < 5)
              {k++;}
                 if (comval == C[k])
                 {
                  cout << "Esiste almeno un valore in comune, che e' " << comval << endl;
                  j = 5, i = 5, k = 5;
                 } else i++;
                              
           } else i++;
        } 
j++;     
}

if (i < 5 || j < 5 || k < 5)
cout << "Non c'e' nessun valore in comune" << endl;
       
    system("PAUSE");
    return EXIT_SUCCESS;
}
                         // Gabriele Cubeda
