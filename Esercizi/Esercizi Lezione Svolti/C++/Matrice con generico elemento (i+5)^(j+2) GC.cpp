#include <cstdlib>
#include <iostream>
#include <ctime>  
#include <time.h>
             // Matrice con generico elemento (i+5)^(j+2)
using namespace std;        //Gabriele Cubeda
 
int main()
{
clock_t start,end;  // tempo di esecuzione
double tempo;
start=clock();
srand(time(NULL));
  
  int i, j, k, n=5, m=7, A[n][m];
  cout << " La matrice e' la seguente: "<<endl<<endl;
  for (i=0; i<n; i++)
    {
    for (j=0; j<m; j++)
      {
        A[i][j] = 1;
        for (k=0; k<j+2; k++)
        A[i][j] *= (i+5);
        cout << " " << A[i][j]; 
      }  
    cout<<endl;
    }
    
   end=clock();  // visualizzazione tempo di esecuzione
tempo=((double)(end-start))/CLOCKS_PER_SEC;
cout << endl <<" Il tempo di esecuzione e' stato: "<<tempo << endl<< endl;
    system("PAUSE");
    return 0;
}
