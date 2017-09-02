 #include <iostream>
 #include <ctime>
 #include <cstdlib>
                         // Gabriele Cubeda
 using namespace std;
 
 int main()
{
     srand(time(NULL));
     string l = "abc", temp,
      X[4], Y[4], Z[4], A[4][4];
      
     int i, j, k;
     bool cond = false;
     
     cout << endl << " X e' composto da: ";
     for(i=0; i<4; i++)
     {
     X[i] = l.substr(rand()%3,1);
     cout << X[i] << " ";
     }
     cout << endl << " Y e' composto da: ";
     for(i=0; i<4; i++)
     {
     Y[i] = l.substr(rand()%3,1);
     cout << Y[i] << " ";
     }
     cout << endl << " Z e' composto da: ";
     for(i=0; i<4; i++)
     {
     Z[i] = l.substr(rand()%3,1);
     cout << Z[i] << " ";
     }
     
     cout << endl << endl << " Vediamo la matrice di stringhe: " << endl;
     for (i=0; i<4; i++)
     {
        for (j=0; j<4; j++)
        {
            A[i][j]= X[rand()%4]+Y[rand()%4]+Z[rand()%4];
            cout << " " << A[i][j] << "   ";
        }
      cout << endl;
     }      
     for (j=0; j<4; j++)
        for (i=0; i<4; i++)
           for (k=i+1; k<4; k++)
                 {
                  temp = A[k][j].substr(2,1)+A[k][j].substr(1,1)+A[k][j].substr(0,1);
                  if ((A[i][j] == temp) && !cond)
                  {
                    cout << endl << " Nella colonna numero " << j+1; 
                    cout << " e' presente l'inverso di " << A[i][j] << endl;
                    cond = true;
                    cout << " quindi il nostro boolean e' " << cond << endl << endl;
                  }
                 }
if (!cond)
{
  cout<<endl<<" Non esiste nessuna stringa opposta ad un'altra della stessa colonna "<<endl; 
  cout << " quindi il nostro boolean e' " << cond << endl << endl;
}

system("PAUSE");
return 0;
}
                       // Gabriele Cubeda
