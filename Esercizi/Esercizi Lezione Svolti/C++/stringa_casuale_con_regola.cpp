/////////////////////////////////
//// Posted By Ivan Jhahy ///////
////////////////////////////////

/* Generare una stringa casuale di lunghezza compresa tra 3 e 8 in cui ci siano i caratteri "a", "b", "c" e "d" che vengono inseriti nella stringa
 secondo le seguenti probabilità: a--> 1/7, b---> 3/7, c---> 2/7, d---> 1/7 */
 
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(){
    
    srand(time(NULL));
    
    int i=0, dim = (int)rand()%6+3;
    char A[dim];
    string s = "abbbccd";
    
    for(i=0; i<dim; i++)
             A[i] = s.at((int)rand()%7);
             
    for(i=0; i<dim; i++)
             cout << A[i];
    cout << endl;
    
    system("PAUSE");
    return 0;
}
