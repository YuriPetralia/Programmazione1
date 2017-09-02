/*Es13. Data una matrice di stringhe, dire se esiste una riga contenente due stringhe congruenti di ordine 3. 
Due stringhe si dicono congruenti di ordine N se il prefisso di lunghezza N della prima, 
è uguale al suffisso di lunghezza N della seconda;*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

const int COLONNE=10;

bool Es13(string[][COLONNE], int);

int main()
{
	const int righe=10;
	string A[righe][COLONNE];
	bool si;
	int i, j, k, l;

	srand(time(NULL));

	for(i=0; i<righe; i++)
	{
		for(j=0; j<COLONNE; j++)
		{
			l=(rand()%3)+4;
			for(k=0, A[i][j]=""; k<l; k++)
			{
				A[i][j] += (rand()%26)+97;
			}
		}
	}

	for(i=0; i<righe; i++)
	{
		for(j=0; j<COLONNE; j++)
		{
			cout << left << setw(7) << A[i][j];
		}

		cout << endl;
	}

	cout << "\n\n\n";

	si= Es13(A, righe);

	cout << "\n\n" << si;

	return 0;
}

bool Es13(string A[][COLONNE], int righe)
{
	const int N=3;
	int i, j1, j2, k, l;
	bool yes=false;
	
	for(i=0; i<righe; i++)
	{
		for(j1=0; j1<COLONNE; j1++)
		{
			for(j2=0; j2<COLONNE; j2++)
			{
				if(j1!=j2)
				{
					for(k=0, yes=true; k<N && yes==true; k++)
					{
						if(A[i][j1].at(k) != A[i][j2].at(A[i][j2].length()-N+k))
							yes=false;
					}

					if(yes==true)
					{
						cout << "("<< i+1 << ")" << j1+1 << "-" << j2+1;
						return (yes);
					}
				}
			}
		}
	}

	return(yes);
}