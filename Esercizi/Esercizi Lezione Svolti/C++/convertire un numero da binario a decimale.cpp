/* Coded By Stefano Borzì & Vincenzo Aliperti */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string a = " ";
	cout << "Inserisci un numero binario" << endl;
	cin >> a;

	// Assegno ad i la lunghezza del numero binario inserito
	int i = a.length()-1;

	// Variabili di supporto e di controllo
	int x = 0, j =0;

	// ciclo while che converte in decimale il nostro numero binario
	while (i >= 0)
	{
		// controllo se il numero che sto leggendo è 1 o o
		// se è 1 converti il numero binario che sto leggendo in decimale e lo aggiungo a x
		if (a[i] == '1')
		{
			// elevo 2 alla "posizione" del numero che sto leggendo
			// (a.length()-1) - i => equivale alla posizione del numero binario che stiamo leggendo
			x += pow(2, (a.length()-1) - i);
		}
		// controllo se il numero che sto leggendo è un numero binario
		// se non lo è, esco dal ciclo con un "break;" e assegno j=1 in modo tale da non stampare nulla
		else if(a[i] != '1' && a[i] != '0')
		{
			cout << "Non hai inserito un numero binario!" << endl;
			j = 1;
			break;
		}
		// decremento i in modo tale da spostarmi man mano verso sinistra mentre leggo il numero binario
		i--;
	}

	if ( j != 1)
		cout << x << endl;

	return 0;
}


