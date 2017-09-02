#include <iostream>
#include <string>
using namespace std;
int main()
{
srand(time(NULL));
int x = rand()%4+2;
x=x*2;
cout<<"La dimensione dell array e' di "<< x <<endl;
string stringa46810[x];  
string consonanti [22]={"b","c","d","f","g","h","l","m","n","p","q","r","s","t","u","v","z","j","y","k","x","w"};
string vocali [5]=     {"a","e","i","o","u"};
int y=0;
int z=0;
int cont1=0;
while (cont1<x)
      {
      if (cont1%2==0)
         {
         y=rand()%24;
         stringa46810 [cont1]=consonanti[y];
         }
      else 
         {
         z=rand()%5;
         stringa46810 [cont1]=vocali[z];         
         }
      cout<< stringa46810 [cont1]<<"";
      cont1++;         
     
      }
cout<<"\n";
  
    
system("PAUSE");
return 0;    
}
