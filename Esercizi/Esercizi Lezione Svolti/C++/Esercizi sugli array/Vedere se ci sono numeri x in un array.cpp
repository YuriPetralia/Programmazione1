#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
int main ()
{
 int numeri_casuali [10];
 int numerox = 3;
 int contatore = 0;

 srand(time(NULL));
 while (contatore<10)
       {
        numeri_casuali [contatore] = rand()%9+1;
        contatore++;
        }   
 contatore=0; //azzero il contatore x un nuovo utilizzo
 while (contatore<10)
       {
      
       if (numeri_casuali [contatore] == numerox )
          {
          cout<<"il valore x e' presente nel "<<contatore<<" array!"<<endl;               
          }
       else
          {
          cout<<"No il valore x non e' presente "<<contatore<<" array!"<<endl;        
          }
       contatore++;
       }
 system ("PAUSE");
 return 0;
}
