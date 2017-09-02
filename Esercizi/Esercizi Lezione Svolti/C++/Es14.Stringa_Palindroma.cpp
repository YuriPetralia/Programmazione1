/*Es14. Dire se una stringa è palindroma;*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool Es14(string);

int main()
{
	string A;
	bool pali;

	cout << "Inserisci una stringa: ";
	cin >> A;

	pali= Es14(A);

	if(pali==1)
		cout << endl << "La stringa e' palindroma";
	else if(pali==0)
		cout << endl << "La stringa NON e' palindroma";

	cout << endl << endl;

}

bool Es14(string A)
{
	bool yes=true;
	int i;

	for(i=0; i<(A.length()/2)+1 && yes==true; i++)
	{
		if(A.at(i) != A.at(A.length()-1-i))
			yes=false;
	}

	return(yes);
	return 1;
	system("pause");
}
