///////////////////////////
// Posted By IVAN JHAHY //
/////////////////////////
/* si legge un numero da tastiera che vogliamo sia compreso tra 0 e 100; 
se tale valore risulta essere negativo, si esce dal ciclo, 
mentre se è maggiore di cento si richiede di inserire un valore valido; 
se il valore è tra 1 e 100, si stampa a video il suo quadrato, se è zero si esce. */

#include <stdio.h>

main(){
	int valore;
 
while (scanf("%d", &valore) == 1 && valore != 0)
{
   if (valore < 0)
   {
      printf("Valore non consentito\n");
      break;
      /* esce dal ciclo */
   }
 
   if (valore > 100)
   {
      printf("Valore non consentito\n");
      continue;
      /* continua il ciclo anche se il valore non è consentito! */
   }
 
   int quadrato = valore * valore;
   printf("%d \n", quadrato);
}
}
