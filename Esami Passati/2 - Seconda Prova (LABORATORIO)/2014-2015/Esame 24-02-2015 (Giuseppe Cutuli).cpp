//Sistemare scostamento prezzo totale della composizione di un PC
//Creato da Cutuli Giuseppe
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;


class Componente
{
	private:
		string codID;
		string marca;
		double prezzo;
		unsigned int numero;
		Componente *succ;
	public:
		Componente(string _codID,string _marca,double _prezzo,int _numero)
		{
			codID=_codID;
			marca=_marca;
			prezzo=_prezzo;
			numero=_numero;
			succ=NULL;
		}

		Componente(string _codID,string _marca,double _prezzo,int _numero, Componente *_succ)
		{
			codID=_codID;
			marca=_marca;
			prezzo=_prezzo;
			numero=_numero;
			succ=_succ;
		}

		string getcodID(){ return codID; }
		string getmarca(){ return marca; }
		double getprezzo(){ return prezzo; }
		int getnumero(){ return numero; }
		Componente* getsucc (){ return succ; } 

		void setprezzo(double _prezzo){ prezzo=_prezzo; }
		void setnumero(int _numero){ numero=_numero; }
		void setsucc(Componente *_succ){ succ=_succ; }
};

class PC
{
	private:
		Componente *SCHEDA_MADRE;
		Componente *RAM;
		Componente *PROCESSORE;
		int codiceID;
		PC *succ;
	public:
		PC(Componente *SCHEDA_MADRE,Componente *RAM,Componente *PROCESSORE, int codiceID)
		{
			this->SCHEDA_MADRE=SCHEDA_MADRE;
			this->RAM=RAM;
			this->PROCESSORE=PROCESSORE;
			this->codiceID=codiceID;
			succ=NULL;
		}
		PC(Componente *SCHEDA_MADRE,Componente *RAM,Componente *PROCESSORE,int codiceID,PC *succ)
		{
			this->SCHEDA_MADRE=SCHEDA_MADRE;
			this->RAM=RAM;
			this->PROCESSORE=PROCESSORE;
			this->codiceID=codiceID;
			this->succ=succ;
		}

		void setsucc(PC *succ) { this->succ=succ; }

		Componente* getSCHEDA_MADRE(){ return SCHEDA_MADRE; }
		Componente* getRAM(){ return RAM; }
		Componente* getPROCESSORE(){ return PROCESSORE; }
		PC* getsucc(){ return succ; }
		int getcodID(){ return codiceID; }
};

class Gestione
{
	private:
		Componente *RAM;
		Componente *SCHEDA_MADRE;
		Componente *PROCESSORE;
		PC *primo;

	public:
		Gestione()
		{
			RAM=NULL;
			SCHEDA_MADRE=NULL;
			PROCESSORE=NULL;
			primo=NULL;
		}

		void scelta()
		{
			int scelta;
			do
			{
				cout<<"Quale Componente vuoi inserire? : "<<endl;
				cout<<"1- RAM"<<endl;
				cout<<"2- PROCESSORE"<<endl;
				cout<<"3- SCHEDA_MADRE"<<endl;
				cout<<"4- Ritorna al MENU"<<endl;
				cin>>scelta;
				switch(scelta)
				{
					case 1 : addRAM();break;
					case 2 : addPROCESSORE();break;
					case 3 : addSCHEDA_MADRE();break;
					default : cout<<"Errore, scelta non presente!"<<endl;break;
				}
			}while(scelta!=4);
		}

		void addRAM()
		{
			Componente *nuovo;
			string cod,marca;
			double prezzo;
			unsigned int numero;
			cout<<"Inserisci i dati della RAM"<<endl;
			cout<<"Marca : ";
			cin>>marca;
			cout<<"Codice Identificativo (e' univoco quindi se gia' esiste dovrai reinserire i dati) : ";
			cin>>cod;
			cout<<"Prezzo : ";
			cin>>prezzo;
			cout<<"Numero Componenti presenti : ";
			cin>>numero;
			if(RAM==NULL) RAM = new Componente(cod,marca,prezzo,numero);
			else if(!controllo(RAM,cod,numero))
				{
					nuovo=new Componente(cod,marca,prezzo,numero,RAM);
					RAM=nuovo;
				}
		} 

		void addPROCESSORE()
		{
			Componente *nuovo;
			string cod,marca;
			double prezzo;
			unsigned int numero;
			cout<<"Inserisci i dati del PROCESSORE"<<endl;
			cout<<"Marca : ";
			cin>>marca;
			cout<<"Codice Identificativo (e' univoco quindi se gia' esiste dovrai reinserire i dati) : ";
			cin>>cod;
			cout<<"Prezzo : ";
			cin>>prezzo;
			cout<<"Numero Componenti presenti : ";
			cin>>numero;
			if(PROCESSORE==NULL) PROCESSORE = new Componente(cod,marca,prezzo,numero);
			else if(!controllo(PROCESSORE,cod,numero))
				{
					nuovo=new Componente(cod,marca,prezzo,numero,PROCESSORE);
					PROCESSORE=nuovo;
				}
		}

		void addSCHEDA_MADRE()
		{
			Componente *nuovo;
			string cod,marca;
			double prezzo;
			unsigned int numero;
			cout<<"Inserisci i dati del SCHEDA MADRE"<<endl;
			cout<<"Marca : ";
			cin>>marca;
			cout<<"Codice Identificativo (e' univoco quindi se gia' esiste dovrai reinserire i dati) : ";
			cin>>cod;
			cout<<"Prezzo : ";
			cin>>prezzo;
			cout<<"Numero Componenti presenti : ";
			cin>>numero;
			if(SCHEDA_MADRE==NULL) SCHEDA_MADRE = new Componente(cod,marca,prezzo,numero);
			else if(!controllo(SCHEDA_MADRE,cod,numero))
				{
					nuovo=new Componente(cod,marca,prezzo,numero,SCHEDA_MADRE);
					SCHEDA_MADRE=nuovo;
				}
		}

		bool controllo(Componente *lista,string _codID,int numero)
		{
			if(lista==NULL)
				return false;
			Componente *app;
			app=lista;
			do
			{
				if(app->getcodID()==_codID){
					app->setnumero(app->getnumero()+numero);
					cout<<"Componente gia' presente, esso verra' incrementato delle unita inserite."<<endl;
					return true;
				}
					
				app=app->getsucc();
			}while(app!=NULL);
			return false;
		}
	
		void componiPC()
		{
			if(SCHEDA_MADRE==NULL||PROCESSORE==NULL||RAM==NULL)
				cout<<"Attualmente non sono presenti alcuni componenti quindi non è possibile fare una lista di personal computer."<<endl;
			else{
				Componente *app=SCHEDA_MADRE ,*app2=RAM,*app3=PROCESSORE;
				double prezzo;
				int id=0;
				PC *temp=NULL;
				cout<<"Inserisci il prezzo totale per i componenti e ti verra' visualizzata una lista con le combinazioni possibili . "<<endl;
				cin>>prezzo;
				cout<<"LISTA CREATA : "<<endl;
				do
				{
					if(app->getnumero()==0)
						continue;
					double prezzo_sc=app->getprezzo();
					do
					{
						if(app2->getnumero()==0)
							continue;
						double prezzo_ram=app2->getprezzo();
						do
						{
							if(app3->getnumero()==0)
								continue;
							double prezzo_pro=app3->getprezzo();
							double tot=prezzo_sc+prezzo_ram+prezzo_pro;
							double scostamento = tot*(5/100);
							if(prezzo>=(tot-scostamento)&&prezzo<=(tot+scostamento))
							{
								cout<<"INIZIO CONFIGURAZIONE PC ------ "<<endl;
								if(temp==NULL)
									temp=new PC(app,app2,app3,id);
								else
								{
									++id;
									PC *nuovo = new PC(app,app2,app3,id,temp);
									temp=nuovo;
								}
								cout<<"CODICE Identificativo PC : "<<id<<endl;
								cout<<"SCHEDA_MADRE : "<<endl;
								stampa(app);
								cout<<"RAM : "<<endl;
								stampa(app2);
								cout<<"PROCESSORE : "<<endl;
								stampa(app3);
								cout<<"Prezzo totale PC : "<<tot<<endl;
								cout<<"FINE CONFIGURAZIONE PC ----"<<endl;
							}
							app3=app3->getsucc();
						}while(app3!=NULL);
						app2=app2->getsucc();

					}while(app2!=NULL);
					app=app->getsucc();

				}while(app!=NULL);

				cout<<"Vuoi salvare una CONFIGURAZIONE PC? S/N"<<endl;
				string c;
				cin>>c;
				if(c=="S"||c=="s")
				{
					int codiceid;
					bool ok=false;
					PC *scorri=temp;
					cout<<"Inserisci il Codice Identificativo del PC"<<endl;
					cin>>codiceid;
					while(!ok && scorri!=NULL)
					{
						if(scorri->getcodID()==codiceid)
						{
							if(primo==NULL)
								primo=scorri;
							else{
								scorri->setsucc(primo);
								primo=scorri;
							}
							ok=true;
						}
					}
					if(ok)
						cout<<"PC salvato con successo!"<<endl;
					else
						cout<<"Errore PC non salvato!"<<endl;
				}
			}

		}

		void stampa(Componente* obj)
		{
			cout<<"Codice Identificativo : "<<obj->getcodID()<<endl;
			cout<<"Marca : "<<obj->getmarca()<<endl;
			cout<<"Prezzo : "<<obj->getprezzo()<<endl;
		}


		void stampaCONF()
		{
			if(primo==NULL){
				cout<<"Nessuna CONFIGURAZIONE salvata!"<<endl;
				return;
			}
			PC *app=primo;
			do
			{
				cout<<"Codice Identificativo PC : " <<app->getcodID()<<endl;
				cout<<"SCHEDA_MADRE : "<<endl;
				stampa(app->getSCHEDA_MADRE());
				cout<<"RAM : "<<endl;
				stampa(app->getRAM());
				cout<<"PROCESSORE : "<<endl;
				stampa(app->getPROCESSORE());
				app=app->getsucc();
			}while(app!=NULL);
		}

		void stampatutto()
		{
			Componente *app=SCHEDA_MADRE;
			cout<<"----- SCHEDA_MADRE------"<<endl;
			if(app!=NULL)
				do
				{
					stampa(app);
					app=app->getsucc();
				}while(app!=NULL);
			cout<<"----- RAM ------"<<endl;
			app=RAM;
			if(app!=NULL)
				do
				{
					stampa(app);
					app=app->getsucc();
				}while(app!=NULL);
			cout<<"----- PROCESSORE ------"<<endl;
			app=PROCESSORE;
			if(app!=NULL)
				do
				{
					stampa(app);
					app=app->getsucc();
				}while(app!=NULL);

		}
};

int main()
{
	Gestione obj;
	int scelta;
	do
	{
		cout<<"Cosa vuoi fare? "<<endl;
		cout<<"1- Inserire nuovo componente "<<endl;
		cout<<"2- Richiedere configurazione di un nuovo personal computer"<<endl;
		cout<<"3- Visualizzare configurazione di personal computer gia' salvate "<<endl;
		cout<<"4- Cancella schermo"<<endl;
		cout<<"5- Stampa componenti presenti"<<endl;
		cout<<"6- Esci"<<endl;
		cin>>scelta;
		switch(scelta)
		{
			case 1: obj.scelta();break;
			case 2: obj.componiPC();break;
			case 3: obj.stampaCONF();break;
			case 4: cout << "\x1B[2J\x1B[?6h" << endl;break;
			case 5: obj.stampatutto();break;
			case 6: cout<<"Stai per uscire"<<endl;break;
			default: cout<<"Errore reinserisci il numero"<<endl;
		}
	}while(scelta!=6);

	return 0;

}
