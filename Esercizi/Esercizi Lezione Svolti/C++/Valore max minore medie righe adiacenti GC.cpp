 #include <iostream>
 #include <ctime>
 #include <cstdlib>
using namespace std;
int main()
{
  srand(time(NULL));
  float A[7][10], media1, media2;
  short i, j, sum = 0, valmax;
  bool val = false;
  
  cout << endl << "I valori di A sono i seguenti: " << endl << endl;
  for (i=0; i<7; i++)
  {    
     for (j=0; j<10; j++)
        {   
               A[i][j] = rand()%9+1;         // inizializzazione matrice
               cout << A[i][j] << " ";
        }
   cout << endl;
  }
  
      for (i=0; i<5 && !val; i++)  // ciclo controlli
      {
         for (sum=0, j=0; j<10; j++)
              sum += A[i][j];
         media1 = sum / 10.0;     // media riga sovrastante
              
         valmax = A[i+1][0];
         for (j=0; j<10; j++)
         {
             if (A[i+1][j] > valmax) 
             valmax = A[i+1][j];     // valore max riga
         }
         for (sum=0, j=0; j<10; j++)
              sum += A[i+2][j];
         media2 = sum / 10.0;      // media riga sottostante
         if ((valmax < media1) && (valmax < media2))
         //se il valore massimo e' minore delle medie delle righe adiacenti
         {
         cout<<endl<<" Nella riga con indice "<<i+2<<", il valore massimo e' ";
         cout<<valmax<<endl<<" ed e' maggiore della media della riga sovrastante (";
         cout<<media1<<") "<<endl;
         cout<<" e della riga sottostante ("<<media2<<")."<<endl;
         i = 5;
         } else if (i == 4){ // altrimenti se il ciclo di controllo e' finito
                val = true;
         cout<<endl<<" Nessun valore massimo delle righe e' minore delle "<<endl;
         cout<<" righe adiacenti, quindi restituisco il valore: -"<<val<<endl<<endl;}
      }       
             
    system("PAUSE");
    return EXIT_SUCCESS;
}
