/*
Data una matrice A 7x10 float restituire l'indice di una riga il cui
elemento massimo é strettamente minore dei valori medi della riga
sovrastante e di quella sottostante o restituisca il valore -1 se tale
riga non esiste. Non usare array ausiliari.
*/


/* Coded By Stefano Borzì */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));

	float A[7][10];
	int i = 0, j = 0;
	
	// Inizializzo l'array
	for(i = 0; i< 7; i++)
	{
		for(j = 0; j < 10; j++)
		{
			A[i][j] = (rand() % 500);
			A[i][j] /= 100;
			cout << fixed;
			cout.precision(2);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	// Inizializzo variabili di supporto e varie
	int max = 0, k = 0;
	float media1 = 0, media2 = 0;

	/* Utilizzo un ciclo for per scorrere il primo indice dell'array (A[i])
	    in modo tale da scorrere le righe

	    Utilizzo altre due cicli for annidati per scorrere gli indici della riga
	
	    Nel primo ciclo for controllo qual è il valore massimo e lo assegno 
	     alla variabile "max" inizializzata precedentemente
	
	     Nel secondo ciclo for  controllo le righe sovrastanti e sottostanti e fa la media
	     dalla riga A[1] e A[6] (quindi A[i+1] e A[i-1] considerando che A[i] non può essere ne A[0]
	     ne A[7] cioè le righe devono avere per forza righe sovrastanti e sottostanti)
	*/
	for(i = 1; i< 6; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if(max < A[i][j])
			{
				max = A[i][j];
			}
		}

		for(k = 0; k < 10; k++)
		{
			if(i != 0 && i != 7)
			{
				media1 += A[i-1][k];
				media2 += A[i+1][k];
			}
		}
		
		media1 /= 10;
		media2 /= 10;

		cout << "MAX: " << max << endl;
		cout << "MEDIA1: " << media1 << endl;
		cout << "MEDIA2: " << media2 << endl;

		if(max < media1 && max < media2)
		{
			cout << "## ESISTE!" << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
	}

	return 0;
}

