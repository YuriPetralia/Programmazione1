/*
	Coded By Stefano Borzì, Vincenzo Aliperti, Luigi La Spina


	Testo dell'esercizio:
	
	presi due array di n numeri interi (es. 10), creare un terzo array composto
	dagli elementi dei due array precedenti ordinati in ordine crescente.  
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(NULL));
	int x[10], y[10], z[20];
	int i = 0, j = 0, t = 0, tmp = 0, b = 0;

	for(;i < 10; i++)
	{ 
		x[i] = rand() % 100 + 1;
//		cout << x[i] << endl;
		y[i] = rand() % 100 + 1;
//		cout << y[i] << endl;
	}

	for(t = 0; t < 20; t++)
	{
		tmp = 101;
		for(i = 0; i < 10; i++)
		{
			if(x[i] < tmp)
			{
				tmp = x[i];
				b = 1;
				j = i;
			}
			if(y[i] < tmp)
			{
				tmp = y[i];
				b = 2;
				j = i;
			}
		}
		
		if(b == 1)
		{
			x[j] = 101;
		}
		else if (b == 2)
		{
			y[j] = 101;
		}
		z[t] = tmp;
	}

//	cout << "##############################" << endl;

	for(t = 0; t < 20; t++)
	{
		cout << z[t] << endl;
	}

	return 0;
}
