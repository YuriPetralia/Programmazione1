/*Es15. Data una matrice quadrata di interi, dire se esiste una diagonale parallela alla principale, 
a somma nulla(includa la principale)*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int DIM=15;

bool Es15(int[][DIM]);

int main()
{
	int A[DIM][DIM];
	int i, j;
	bool diag;
	

	srand(time(NULL));

	for(i=0; i<DIM; i++)
	{
		for(j=0; j<DIM; j++)
		{
			A[i][j]=(rand()%15)-7;
			cout << right << setw(3) << A[i][j];
		}
		cout << endl;
	}

	diag= Es15(A);

	cout << endl << endl << diag;
    
	return 0;
}

bool Es15(int A[][DIM])
{
	int i, j, r, c, somma;
	bool diag0=false;

	for(j=0, i=0; j<DIM-1; j++)
	{
		for(c=j, r=i, somma=0; c<DIM; c++, r++)
		{
			somma += A[r][c];
		}
		if(somma==0)
		{
			diag0=true;
			cout << endl << endl << i+1 << "-" << j+1;
			return(diag0);
		}
	}

	for(i=1, j=0; i<DIM-1; i++)
	{
		for(r=i, c=j, somma=0; r<DIM; r++, c++)
		{
			somma += A[r][c];
		}
		if(somma==0)
		{
			diag0=true;
			cout << endl << endl << i+1 << "-" << j+1;
			return(diag0);
		}
	}
    
	return(diag0);	
}
