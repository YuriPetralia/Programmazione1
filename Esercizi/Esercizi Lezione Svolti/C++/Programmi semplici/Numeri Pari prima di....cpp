/* Creato da Giuseppe Dinatale - Il programma genera in output tutti i numeri pari interi esistenti prima del numero messo in input */

#include <iostream>
#include <stdlib.h>

using namespace std;

int main ()

{
	
	int a = 0;
	cout << "Inserisci un numero intero per vedere quali sono i numeri pari prima di questo:" << endl;
	cin >> a;
	int count = 0;
	cout << "I numeri pari prima del numero immesso sono:" << endl;
	
	while (count < a )
	{
		if (count%2 == 0)
		{
		cout << count << " " << endl;
		}
		count++;
		
		
	}
	system ("pause");
	return 0;
}
