#include <cstdlib>
#include <iostream>
#include <string>                  
                        // Gabriele Cubeda
using namespace std;

int main()
{
    string Parole[] = {"abc", "defgh", "fbbcurg", "ecdsfgfgfgba"};
    string suff = "ba";
    

   for (short i=0; i<4; i++) // selezione parole da controllare
   {
      if (suff == Parole[i].substr(((Parole[i].size())-2), 2))
           
           {
           cout << "Il suffisso 'ba' e' presente in " << Parole[i] << endl;
           break;
           }
   }    

    system("PAUSE");
    return EXIT_SUCCESS;
}
                         // Gabriele Cubeda
