/* Coded By Stefano Borzì (Helias) */

// Per chi usa Windows deve modificare il comando system("clear") in system("cls")

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int G, tmp = 0, life = 100, X, Y, movements = 0;

	cout << "Inserisci la grandezza della matrice" << endl;
	cin >> G;

	bool M[G][G];
	for(int i = 0; i < G; i++)
	{
		for(int j = 0; j < G; j++)
		{
			M[i][j] = rand() % 2;
		}
	}

	if(G % 2 == 0)
		tmp = rand() % 2;

	X = G/2 + tmp;
	Y = G/2 + tmp;

	M[X][Y] = false;

	bool the_end = false, all_false = false;

	while(!the_end && life > 0)
	{
		system("cls");
		// muoviti
		if(rand() % 2)
		{
			X += rand() % 2;
			Y += rand() % 2;
		}
		else
		{
			X -= rand() % 2;
			Y -= rand() % 2;			
		}

		if(X > G)
			X -= 2;
		else
			if(X < 0)
				X += 2;

		if(Y > G)
			Y -= 2;
		else
			if(Y < 0)
				Y += 2;

		cout << "X: " << X << " ";
		cout << "Y: " << Y << endl;

		if(M[X][Y] == 1)
		{
			life += 10;
			M[X][Y] = false;
		}
		else
		{
			life--;
		}

		movements++;

		for(int i = 0; i < G; i++)
		{
			for(int j = 0; j < G; j++)
			{
				cout << M[i][j] << " ";
			}
			cout << endl;
		}
		
		cout << "Vita: " << life << endl;
		cout << "Spostamenti: " << movements << endl;
		system("sleep .5");

		// Controlla se c'è almeno un true nella matrice
		for(int i = 0; i < G; i++)
		{
			for(int j = 0; j < G; j++)
			{
				if(M[i][j] == true)
				{
					all_false = false;
					i = G;
					break;
				}
				else
				{
					all_false = true;
				}
				

				if(i == G-1 && j == G-1 && all_false)
				{
					the_end = true;
					break;
				}
			}
		}

		//Stampa spostamenti e vita del coniglio simultaneamente
		cout << endl;
		cout << "Spostamenti: " << movements << endl;
		cout << "Vita: " << life << endl;
	}

	if(all_false)
		cout << "Il coniglio si e' mangiato tutte le carote!" << endl;
	else
		cout << "Il coniglio e' MORTO!" << endl;
	return 0;
}
