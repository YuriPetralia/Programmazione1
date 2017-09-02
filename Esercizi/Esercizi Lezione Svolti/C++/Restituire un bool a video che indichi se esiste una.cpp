/* Data una matrice A di stringhe restituire un bool a video che indichi se esiste una
colonna in cui siano presenti due stringhe l'una inversa dell'altra. */

/* Coded By Stefano Borzì (alias Helias) */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));

	// Dichiaro ed inizializzo l'array e alcune variabili di supporto per i cicli for
	string A[10][10];
	int i = 0, j = 0, k = 0;	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			for(k = 0; k < 3; k++)
			{
				A[i][j] += 65 + (rand() % 5);
			}
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;

	// Dichiaro ed inizializzo la variabile tmp che usero' per registrare le stringhe inverse
	string tmp = "";
	int l = 0; // variabile di supporto
	
	// Con i seguenti cicli for confronto le varie stringhe della matrice colonna per colonna
	for (j = 0; j < 10; j++)
	{
		for ( i = j; i < 10; i++)
		{
			int len= A[i][j].length();
			tmp = "";
			for (l = 0; l < len; l++)
			{
//				cout << " i: " << i << " j: " << j << endl;
				tmp = tmp + A[i][j][(len-1) - l];
			}

			for (k = 0; k < 10; k++)
			{
				if (A[k][j] == tmp && k != i)
				{
					cout << "##YES!! riga " << k << " colonna " << j << " con riga " << i << endl;
				}
			}
		}
	}

	return 0;
}
