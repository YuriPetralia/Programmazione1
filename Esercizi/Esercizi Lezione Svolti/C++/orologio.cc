/* CONSEGNA: Progettare una classe “Orologio” che permetta visualizzazione 24h oppure am/pm 
 * AUTORE: LUCA CAVALLARO <luca.cavallaro@outlook.it>
 * - PER L'USO DEI DUE COSTRUTTORI E DEL METODO INIT LEGGERE http://stackoverflow.com/questions/308276/c-call-constructor-from-constructor
 * - PER INFORMAZIONI SULLA STRUTTURA `struct tm` UTILIZZATA PER PRENDERE L'ORA ATTUALE LEGGERE http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c */

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class Orologio
{
private:
	short int ore, minuti, secondi, formato; // formato assume i due valori interi 12 o 24
	void init(short int ore, short int minuti, short int secondi, short int formato);
	short int converti_24_12();
	string n_to_string(short int n);
public:
	Orologio(short int ore, short int minuti, short int secondi, short int formato = 24);
	Orologio(short int formato = 24);
	void cambia_formato(short int formato);
	void stampa_ora(short int formato = 0); // 0 = non settato, usa quindi il valore di default
	Orologio operator++(int);
};

Orologio::Orologio(short int ore, short int minuti, short int secondi, short int formato)
{
	if(formato == 12) ore += 12;
	ore = (ore == 24) ? 0 : ore;
	init(ore, minuti, secondi, formato);
}

Orologio::Orologio(short int formato)
{
	time_t t = time(0);
	struct tm *now = localtime(&t);
	init(now->tm_hour, now->tm_min, now->tm_sec, formato);
}

void Orologio::init(short int ore, short int minuti, short int secondi, short int formato)
{
	this->ore = ore;
	this->minuti = minuti;
	this->secondi = secondi;
	this->formato = formato;
}

short int Orologio::converti_24_12()
{
	return abs(this->ore - 12);
}

string Orologio::n_to_string(short int n)
{
	return (n < 10 ? "0" : "") + to_string(n);
}

void Orologio::cambia_formato(short int formato)
{
	this->formato = formato;
}

void Orologio::stampa_ora(short int formato)
{
	formato = formato == 0 ? this->formato : formato;
	string out = n_to_string((formato == 12 ? converti_24_12() : ore)) + ":" + n_to_string(minuti) + ":" + n_to_string(secondi) + (formato == 12 ? (ore > 12 ? " p.m." : " a.m.") : "");
	cout << out << endl;
}

Orologio Orologio::operator++(int)
{
	this->ore = (this->ore == 23) ? 0 : ++ore;
	return *(this);
}

int main()
{
	// OROLOGIO CON ORA ATTUALE (stampo in formato 12h)
	Orologio orologio_attuale(12);
	orologio_attuale.stampa_ora();

	// POSSO STAMPARE L'ORA ANCHE IN FORMATO 24h SENZA CAMBIARE LO STATO
	orologio_attuale.stampa_ora(24);

	// OROLOGIO CON ORA STABILITA (stampo in formato 24h)
	Orologio orologio_custom(14, 5, 27);
	orologio_custom.stampa_ora();

	// CAMBIO FORMATO
	orologio_custom.cambia_formato(12);
	orologio_custom.stampa_ora();

	// INCREMENTO L'ORA (overload operatore ++)
	orologio_custom++;
	orologio_custom.stampa_ora();

	cout << "HAPPY CODING!" << endl;

	return 0;
}