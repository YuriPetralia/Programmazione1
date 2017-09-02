/*
Due stringhe si dicono simili se esse coincidono in almeno p posizioni
dove p è la metà (troncata) della lunghezza della stringa più corta.
Scrivere un metodo che prenda in input una matrice di stringhe e
restituisca un boolean che indichi se esiste una colonna della matrice
in cui sono presenti almeno due stringhe simili.

Versione di ADRIANO FERRAGUTO
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Dimensioni della matrice
const int n=5,m=5;
	
// Controlla se ci sono colonne con stringhe simili
bool stringhesimili(string A[n][m]){
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			for(int k=i+1;k<n;k++){
				int p2;
				if(A[i][j].length()<A[k][j].length()){
					p2=A[i][j].length();
				}
				else{
					p2=A[k][j].length();
				}
				int corrisp=0;
				for(int l=0;l<p2;l++){
					if(A[i][j].at(l)==A[k][j].at(l)){
						corrisp++;
					}
				}
				if(corrisp>=p2/2){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	// Genera di una matrice nxm di stringhe casuali
	string A[n][m];
	srand(time(NULL));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int lunghezzaStringa = rand()%5+5;
			string stringa = "";
			for(int k=0;k<lunghezzaStringa;k++){
				stringa += rand()%26+97;
			}
			A[i][j] = stringa;
			// Stampa la matrice in maniera ordinata
			cout <<stringa;
			for(int l=0;l<(10-stringa.length());l++){
				cout << " ";
			}
		}
		cout << endl;
	}
	// Chiama il metodo che controlla se ci sono colonne con stringhe simili e ne interpreta il risultato
	if(stringhesimili(A)){
		cout << "Esiste una colonna della matrice con almeno due stringhe simili";
	}
	else{
		cout << "Non esiste una colonna della matrice con almeno due stringhe simili";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}
