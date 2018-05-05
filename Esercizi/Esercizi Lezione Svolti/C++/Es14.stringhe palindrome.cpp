#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int a[DIM];
bool esiste( string a[DIM])
{
	int y;
	int DIM=0;
	int x = 0;
	int b=0;
	while(b < DIM)
	{
		y = str.length(a[b]);
		while( x < y )
		{
			for(int z = y - 1; z >= 0; z--)
			{
				if( a[b].substr(x,1) == a[b].substr(z,1))
				{
					x++;
				}
				else
				{
					b++;
					x=0;
					y = str.length(a[b]);
				}
						
			}
			
		}
		return true;
		b++;
	}
return false;	
	
}


