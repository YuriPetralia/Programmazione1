//Contatore che ordina 2 array di interi in modo crescente
#include <iostream>
using namespace std;
int main()
{
cout<<"Questo programma somma 2 array di interi in ordine crescente in un terzo array"<<endl;
int x;
int y;
cout<<"Digita l'intero della dimensione del 1' array"<<endl;
cin>>x;
cout<<"Digita l'intero della dimensione del 2' array"<<endl;
cin>>y;
int a [x];
int b [y];
int c [x+y];
int cont1=0;
int cont2=0;
int cont3=0;




while (cont1<x)
      {
     
      cout<<"Digita il " << cont1+1<< "' valore dell 1' array"<<endl;
      cin>> a [cont1];
      if(cont1>0)
                {
                      while (a[cont1] <
                       a [cont1-1])
                     {
                     cout<<"Attenzione il numero che hai digitato e' piu' piccolo del precedente, riprova"<<endl;
                     cin>>a[cont1];
                     }
                }
      
      cont1++;        
      }
cont1=0;

while (cont1<y)
      {
      cout<<"Digita il " << cont1+1<< "' valore dell 2' array"<<endl;
      cin>> b [cont1];
      if(cont1>0)
                {
                      while (b[cont1] < b [cont1-1])
                     {
                     cout<<"Attenzione il numero che hai digitato e' piu' piccolo del precedente, riprova"<<endl;
                     cin>>b[cont1];
                     }
                }
      cont1++;        
      }
cont1=0;
 
while (cont1<x+y)
      {
       if (a[cont2]<=b[cont3])
          {
          c[cont1]=a[cont2];
          if(cont2<x)
                {
                cont2++;
                }      
          }        
       else
          {
          c[cont1]=b[cont3];
          if (cont3<y)
             {
             cont3++;
             }
          }
       cont1++;
      }
cont1=0;
while (cont1<x+y)
      {
      cout<<c[cont1]<<" ";
      cont1++;
      }
 
 
   
system("Pause");
return 0;    
}
