//////////////////////////////////////
///// Posted By Ivan Jhahy ///////////
//////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>

#define RAGGIO 1

using namespace std;

int main(){
    
    int count=0, num_lanci=0, hits=0, not_hits=0; // hits sarebbe il numero di volte che il punto ricade all'interno del cerchio 
    float coord_x=0.0, coord_y=0.0, distanza=0.0, pi_greco_approx=0.0;
    
    cout << "Poniamo l'esistenza di un Quadrato di lato 2," << endl << 
            "e di un cerchio la cui circonferenza tange in alcuni punti il perimetro del quadrato." << endl;
    cout << "Adesso prendiamo dei punti che ricadranno all'interno del quadrato con coordinate x e y." << endl <<
            "Tali punti ricadranno a volte all'interno del cerchio, altre volte nell'area tra cerchio e quadrato." << endl <<
            "Calcoliamone la probabilita'" << endl;
    
    cout << "Inserite il numero di lanci da effettuare: " << endl;
    cin >> num_lanci;

    srand(time(NULL));
    
    
    //Calcoliamo la probabilità che cada all'interno del cerchio
    
       while(count<num_lanci){
               // Dovrei scrivere qui i punti, l'area in cui ricadono e sapere quando cadono all'interno dell'area del cerchio. 
               coord_x = (float) rand() / (float) RAND_MAX;
               coord_y = (float) rand() / (float) RAND_MAX;
               distanza = sqrt((coord_x*coord_x) + (coord_y*coord_y));
                      if (distanza<RAGGIO){      //controllo se il punto ricade all'interno
                          hits++;                // Ho fatto centro!
                      }
                      else {
                          not_hits++;            // NON ho fatto centro.. :(
                      }
               count++;
       }
       pi_greco_approx = 4.0 * ((float)hits / (float)num_lanci);
       cout << "Il numero di centri: " << hits << " su " << num_lanci << " tentativi." << endl << 
               "Il numero di tiri sbagliati: " << not_hits << " su " << num_lanci << " tentativi." << endl <<
               "Il valore approssimativo di Pi Greco: " << pi_greco_approx << "." << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
