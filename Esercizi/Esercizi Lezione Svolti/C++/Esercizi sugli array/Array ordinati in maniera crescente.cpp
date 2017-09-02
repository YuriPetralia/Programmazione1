#include <iostream>
using namespace std;
int main()
{
int a [6];
int b [4];
int c [10]; 
int cont1=0;
int cont2=0;
int cont3=0;
a [0] = 1 ;  
a [1] = 3 ;
a [2] = 7 ;
a [3] = 11 ;
a [4] = 13;
a [5] = 19 ;
  
b [0] = 2 ;
b [1] = 5 ;
b [2] = 7 ;
b [3] = 18 ;

while (cont1<10)
      {
       if (a[cont2]<=b[cont3])
          {
          c[cont1]=a[cont2];
          if(cont2<6)
                {
                cont2++;
                }      
          }         
       else
          {
          c[cont1]=b[cont3];
          if (cont3<4)
             {
             cont3++;
             }
          }
       cont1++;
      } 

cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<" "<<c[5]<<" "<<c[6]<<" "<<c[7]<<" "<<c[8]<<" "<<c[9];

  
    
    
system("Pause");
return 0;    
}
