#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;        // Gabriele Cubeda
int main()
{
  srand(time(NULL));
  int i, j, ccx, ccy, dim, hp = 10;
  cout << " Inserire la dimensione del campo: ";
  cin >> dim;
  bool A[dim][dim];
  cout << endl << " Le carote sono cresciute in questi punti: " << endl << endl;
  for (i=0; i<dim; i++)
  {
     for (j=0; j<dim; j++)
        {
               A[i][j] = rand()%2;
               cout << A[i][j] << " ";
        }
   cout << endl;
  }
  
  ccx = (dim/2);
  ccy = ccx;
  cout << endl << " Bug parte dalle coordinate " << dim/2+1 << ", " << dim/2+1 << endl;
  while (hp > 0)
  {
      if (A[ccx][ccy])
      {
         hp += 1;
         cout << " Bug ha mangiato una carota e ha acquistato 1 hp! " << endl;
         cout << " Adesso la sua vita e' a " << hp << " hp!" << endl << endl;
         A[ccx][ccy] = false;
      } else {
              cout << " Bug non ha trovato nessuna carota. " << endl;
              hp -= 1;
              cout << " Adesso la sua vita e' a " << hp <<" hp." << endl << endl;
             }
  if (rand()%2 == 0) ccx = rand()%2 == 0 ? ccx - 1 : ccx + 1;
  else ccy = rand()%2 == 0 ? ccy - 1 : ccy + 1;
  
  if (ccx > dim || ccy > dim || ccx < 0 || ccy < 0)
      {
         cout << " Bug e' uscito dal campo! Adesso e' in pericolo!" << endl<< endl;
         hp = 0;
      } 
  }
  cout << " Oh no! E' morto!!! :( " << endl << endl;
  cout << " Adesso, pero', il programma e' senza Bug... LOL " << endl << endl;       
             
  system("PAUSE");
    return EXIT_SUCCESS;     // Gabriele Cubeda
}
               
