#include <cstdlib>
#include <iostream>
#include <ctime>  
              //Esistenza somma nulla di 3 elementi stessa colonna
 
using namespace std;        //Gabriele Cubeda
 
int main()
{
srand(time(NULL));
int n = 5, i, j, k, w;
float A[n][n];
bool cond = false;

    for (i=0; i<n; i++)
     {
        for(j=0; j<n; j++)
        {
            A[i][j] = rand()%10-5;
            cout << " " << A[i][j];
        }
     cout << endl;
     }
     
  for (k=0; k<n-2 && !cond; k++)
     for (w=0; w<n-2 && !cond; w++)
       for (j=w+1; j<n-1 && !cond; j++)
         for (i=j+1; i<n && !cond; i++)
         if (A[i][k] + A[j][k] + A[w][k] == 0)
         {
             cond = true;
             cout<<endl<<" "<<A[i][k]<<" "<<A[j][k]<<" "<<A[w][k]<<endl;
             cout<<" Nella colonna "<<k<<endl;
         }
cout << endl << " "<< cond << endl;
   
    system("PAUSE");     // Gabriele Cubeda
    return 0;
}
