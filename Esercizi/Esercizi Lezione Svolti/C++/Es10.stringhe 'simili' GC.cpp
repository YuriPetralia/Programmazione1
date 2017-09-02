/*Es9. Data una matrice A di float,
determinare un bool che indica se esistono in A 3 elementi,
nella stessa colonna,
ma in posizioni distinte, la cui somma è nulla;*/

 #include <iostream>
 #include <ctime>
 #include <cstdlib>      // Stringhe "simili"
                         // Gabriele Cubeda
 using namespace std;

 const int gr = 5;

 bool stringheSimili(string m[gr][gr])
{
     int p, grstr1, grstr2, // variabili
     i_p, i_at, i, j, k;  // contatori

     p = m[0][0].size();    // calcolo p
     for (j=0; j<gr; j++)
       for (i=0; i<gr; i++)
          if (m[i][j].size() < p)
              p = m[i][j].size();
     p /= 2;
   for (k=0; k<gr; k++)
     for (j=0; j<gr-1; j++)
       for (i=j+1; i<gr; i++)
       {
          grstr1 = m[j][k].size();
          grstr2 = m[i][k].size();
          i_p = 0;
          i_at = 0;
          while (i_p < p && grstr1 && grstr2)
          {
                if (m[j][k].at(i_at) == m[i][k].at(i_at)) i_p++;
                if (i_p == p) return true;
                grstr1--;
                grstr2--;
                i_at++;
          }
       }
 return false;
}

 int main()
{
     srand(time(NULL));
     int i, j, k;
     string A[gr][gr], stringa="abcde";

     cout << endl << endl << " Vediamo la matrice di stringhe: " << endl;
     for (i=0; i<gr; i++)
     {
        for (j=0; j<gr; j++)
        {
            A[i][j] = stringa.at(rand()%5);//inizializzo con stringhe a caso
            for (k=0; k<(rand()%3+4); k++)
            A[i][j] += stringa.at(rand()%5);
            cout << " " << A[i][j] << "   ";
        }
      cout << endl;
     }

    if (stringheSimili(A))
    cout<<" Esistono almeno due stringhe nella stessa colonna simili!"<<endl;
    else
    cout<<" Non esiste nessuna stringa simile. "<<endl;

system("PAUSE");
return 0;
}
/* NOTE: Il metodo dev'essere messo prima del main.
         Per poter inserire una matrice come parametro formale,
         deve essere inserita con le dimensioni COSTANTI.
         Ho risolto mettendo una costante globale.

            Gabriele Cubeda */
