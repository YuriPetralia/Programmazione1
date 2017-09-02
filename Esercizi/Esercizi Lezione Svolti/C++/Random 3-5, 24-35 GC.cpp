#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	srand (time(NULL));
	int prob = rand() % 15; /* i numeri sono in tutto 15 (3,4,5 sono 3, mentre 
    da 24 a 35 sono 12), quindi abbiamo una PROBabilità su 15 che uno di 
    loro esca*/
	int x = (prob<=2 ? ((rand()%3)+3) : (rand()%11)+24); /* abbiamo 3 probabilità
	su 15 che esca un numero compreso tra 3 e 5, e 12 probabilità su 15 che ne esca 
	uno compreso tra 24 e 35 quindi mi chiedo: questa prob è compresa tra 0 e 
	2 (0, 1, 2 sono 3 numeri)? se si, allora assegno a x un numero compreso tra
	3 e 5, altrimenti gliene do uno compreso tra 24 e 35 */
	
	cout << x << endl;
	
	
	system("PAUSE");
	return 0;	
}
 
                                                 // Gabriele Cubeda
    
    
