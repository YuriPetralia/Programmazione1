#include <cstdlib>
#include <iostream>
#include <ctime>          // uguaglianza somme righe
using namespace std;        // Gabriele Cubeda
int main()
{
  srand(time(NULL));
  int n, m, i, j, k;
  cin >> n;
  m = n;
  float A[n][m], s1, s2;
  
  for (i=0; i<n; i++)
     {
        for(j=0; j<n; j++)
        {
            A[i][j] = (rand()%5)/2.0;
            cout << "          " << A[i][j];
        }
     cout << endl;
     }

  for (k=0; k<n; k++)
     for (j=k+1; j<n; j++)
        {
         for (i=0, s1=0, s2=0; i<n; i++)
          {
              s1 += A[i][k];
              s2 += A[i][j];
          }
           if (s1 == s2)
              {
                  cout <<" Esistono due colonne le cui somme sono uguali"<<endl;
                  cout << " che sono " << k << " e " << j << endl << endl;
                  cout << " poiche' le loro somme sono rispettivamente ";
                  cout << s1 << " e " << s2 << endl << endl;
                  j = n;
                  k = n;
              }
        }
  if (k != n+1)
  cout <<" Non esistono colonne le cui somme sono uguali. "<< endl;
        
  system("PAUSE");
    return EXIT_SUCCESS;     // Gabriele Cubeda
}
               
