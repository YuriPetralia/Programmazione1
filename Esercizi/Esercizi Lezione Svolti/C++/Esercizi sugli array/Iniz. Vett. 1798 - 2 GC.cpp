#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int A[100] = {1800}, i=1;

   while (i<101)
   {  
   A[i] = A[i-1] - 2;
   cout << A[i] << endl;
   i++;
   }     
    system("PAUSE");
    return EXIT_SUCCESS;
}
        // Gabriele Cubeda
