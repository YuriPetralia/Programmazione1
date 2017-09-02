
#include <iostream>
#include <string>
                    // Gabriele Cubeda
using namespace std;
int main()
  {
    srand(time(NULL));
   int n = (rand()%4+2)*2;
   string V[] = {"a", "e", "i", "o", "u"};
   string C[] = {"B", "C", "D", "F", "G", "H", "L", "M", "N", "P", "Q", "R", "S", "T", "V", "Z"};
   string parola;
   cout << "n = " << n << endl << "La nostra parola e' ";
   for (int i=0; i<n/2; i++)
   {
   parola = (C[rand()%16]+V[rand()%5]);
   cout << parola;
   }
   cout << endl << endl;
system("PAUSE");
return 0;    
}
                   // Gabriele Cubeda
