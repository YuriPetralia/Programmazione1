 #include <iostream>
 #include <ctime>
 #include <cstdlib>  
     // Confronto coppia elementi matrici senza 'a' con elementi vettore 
                         // Gabriele Cubeda
 using namespace std;
 
 const int DIMMc = 5, DIMMr = 5, DIMA = 5;
  
 bool esisteCoppia(string m[DIMMr][DIMMc], string a[DIMA])
{
     int i, j, k, w, ii;
     string conc, strwoa;
     
     for (w=0; w<DIMMc; w++)
       for (k=0; k<DIMMr; k++)
          for (j=0; j<DIMMc; j++)
            for (i=0; i<DIMMr; i++)  
            {
                if (m[k][w] != m[i][j])
                {
                  conc = m[k][w] + m[i][j];
                  strwoa = "";
                  for (ii=0; ii<conc.size(); ii++)
                  if (conc.at(ii) != 'a')
                  strwoa += conc.at(ii);
                  for (ii=0; ii<DIMA; ii++)
                  if (strwoa == a[ii]) return true;
                }
            }
     return false;  
}
 
 int main()
{
     srand(time(NULL));
     int i, j, k;
     string A[DIMMc][DIMMr], B[DIMA], stringa="aabbbbbbbbbbbb";
     
     cout << endl << endl << " Vediamo la matrice di stringhe: " << endl;
     for (i=0; i<DIMMr; i++)
     {
        B[i] = "bbbbbbb";
        for (j=0; j<DIMMc; j++)
        {
            A[i][j] = stringa.at(rand()%stringa.size());
            for (k=0; k<(rand()%3+4); k++)
            A[i][j] += stringa.at(rand()%stringa.size());
            cout << " " << A[i][j] << "   ";
        }
      cout << endl;
     } 
     if (esisteCoppia(A, B))
     cout<<" La matrice contiene una coppia che, senza 'a', e' contenuta nel vettore. "<<endl;
     else 
     cout<<" Non esiste nessuna coppia che, senza 'a', e' contenuta nel vettore"<<endl;

system("PAUSE");               // Gabriele Cubeda
return 0;
} 
