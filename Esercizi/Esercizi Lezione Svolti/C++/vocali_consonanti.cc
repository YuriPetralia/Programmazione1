/* Scrivere un metodo che prenda in input un array S di stringhe, e restituisca un boolean che indichi se 
 * la stringa x contiene più vocali o più consonanti, dove x è la concatenazione, nell'ordine, di tutti i caratteri di posto pari delle stringhe 
 * in S di indice dispari.
 * AUTORE: Luca Cavallaro <luca.cavallaro@outlook.it> */

#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool piu_vocali_o_consonanti(string *array);

const int DIMENSIONE_ARRAY = 4;

int main()
{
	string array[DIMENSIONE_ARRAY] = {"Libro", "Cane", "Computer", "Chitarra"};

	if(piu_vocali_o_consonanti(array)) { // Torna true se ci sono più vocali
		cout << "Ci sono piu vocali";
	} else {
		cout << "Ci sono piu consonanti";
	}

	cout << endl;
	return 0;
}

bool piu_vocali_o_consonanti(string *array)
{
	string x = "";

	for(int i = 0; i < DIMENSIONE_ARRAY; i++) // scorro l'array di stringhe
		if(i % 2 == 0) // se l'INDICE è pari vado avanti con il ciclo
			continue;
		else // se invece è dispari
			for(int j = 0; j < array[i].size(); j++) // scorro la stringa di posizione i (dispari)
				if(j % 2 == 0) // controllo se l'indice della stringa è pari, se lo è
					x += array[i].at(j); // concateno il carattere (di indice pari) alla stringa x

	cout << "Stringa generata: " << x << endl;

	/* Dichiaro e definisco una espressione regolare (vedi fondamenti)
	 * che riconosce se un carattere è una vocale. in C++ la pipe ( | )
	 * è l'OR, quello che in fondamenti indichiamo con il più. Quindi questa
	 * espressione regolare riconosce quando un carattere è "a" oppure "A"
	 * oppure "e" e così via */

	regex vocali("a|A|e|E|i|I|o|O|u|U");
	int contatore_vocali = 0, contatore_consonanti = 0;

	for(int i = 0; i < x.size(); i++) { // scorro la stringa x

		/* questo è un "trucco" che ho dovuto usare per
		 * far diventare x.at(i) una stringa di un carattere
		 * invece che un char. Non si può fare il casting diretto
		 * quindi ho creato una stringa vuota e poi ho concatenato
		 * il carattere. A cosa mi serve? Le funzioni regolari in C++
		 * funzioano solo sulle stringhe, senza "trucco" non potevo controllare
		 * il char. */

		string carattere = "";
		carattere += x.at(i);

		/* uso regex_match(...) per controllare se il carattere viene 
		 * riconosciuto come vocale dalla espressione regolare definita 
		 * sopra. regex_match torna TRUE se l'e. r. riconosce la stringa */

		if(regex_match(carattere, vocali))
			contatore_vocali++; // il carattere è una vocale, incremento il suo contatore
		else // se non viene riconosciuto dalla e. r. il carattere è una consonante
			contatore_consonanti++;
	}

	/* infine, torno TRUE se ci sono più vocali, altrimenti torno FALSE */
	return contatore_vocali > contatore_consonanti;
}