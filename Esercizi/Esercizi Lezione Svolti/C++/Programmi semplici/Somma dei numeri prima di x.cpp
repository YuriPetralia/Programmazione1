/* Creato da Giuseppe Dinatale - Il programma fa la somma di tutti i numeri da 0 al numero immesso in input */

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	
	long double x = 0;
	long double cont = 0;
	long double somma = 0;
	
	cout << "Questo programma fa la somma di tutti i numeri da zero al numero immesso, immetti un numero:" << endl;
	
	cin >> x;
	
	while (cont <= x)
	{
		
		somma = somma + cont;
		cont++;
		
	}
	
	cout << "La somma di tutti i numeri è: " << somma << endl;
	system ("pause");
	return 0;
	
	
	
}
