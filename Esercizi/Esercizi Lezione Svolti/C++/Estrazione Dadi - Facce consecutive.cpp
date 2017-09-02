/* Programma di Salvatore Pizzimento, Alessandro Midolo, Alessio Sferro */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int dado = 0;
	int lancio = 0;
	int numero_fac = 0;
	int stessa_fac = 0;
	
	while(numero_fac < 4)
	{		
		dado = rand() % 6 + 1;		
		if(dado == stessa_fac )
		{
			lancio++;
			numero_fac++;
		}
		else 
		{
			lancio++;
			numero_fac = 0;
		}		
		stessa_fac = dado;
		cout << dado << endl;
	}
	
	cout << "Numero lanci: " << lancio-1 << endl;
	cout << "Numero ripetuto cinque volte: " << dado << endl;
	cout << "\nProgramma di Alessio, Alessandro e Salvo scritto in data 13/11/2014";
	system ("PAUSE");  
	// aggiungete il system paus� by Giuseppe Dinatale <3
	
	return 0;
}



