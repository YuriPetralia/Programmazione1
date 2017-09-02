#include <iostream>
#include <string>

//Creato da Cutuli Giuseppe

using namespace std;

class Nodo{
	private:
		int data;
		Nodo* punt_dx;
		Nodo* punt_sx;
	public:
		Nodo(int data){
			this->data=data;
			punt_dx=NULL;
			punt_sx=NULL;
		}
		
		~Nodo(){}
		
		int getData(){
			return data;
		}
		
		Nodo* getPunt_dx(){
			return punt_dx;
		}
		
		Nodo* getPunt_sx(){
			return punt_sx;
		}
		
		void setPunt_dx(Nodo *x){
			punt_dx=x;
		}
		
		void setPunt_sx(Nodo *x){
			punt_sx=x;
		}
};

class Gestione{
	private:
		Nodo* primo;
		
		Nodo* chiedi(){
			int data;
			Nodo* n;
			cout<<"Inserisci un intero"<<endl;
			cin>>data;
			n = new Nodo(data);
			return n;
		}
	public:
		Gestione(){
			primo=NULL;
		}
		
		void inserisci(){
			Nodo* nuovo=chiedi();
			if(primo==NULL)
				primo=nuovo;
			else{
				bool ok=false;
				if(primo->getData()>nuovo->getData()){
					nuovo->setPunt_sx(primo);
					primo->setPunt_dx(nuovo);
					primo=nuovo;
				}else{
					Nodo *app,*app2;
					app=primo;
					app2=primo;
					while(app!=NULL && !ok ){
						if(app->getData() > nuovo->getData()){
							nuovo->setPunt_dx(app2);
							app2->setPunt_sx(nuovo);
							nuovo->setPunt_sx(app);
							ok=true;
						}
						app2=app;
						app=app->getPunt_sx();
					}
					if(ok==false){
						app2->setPunt_sx(nuovo);
						nuovo->setPunt_dx(app2);
					}
		
				}
			}
			cout<<"Numero inserito nella lista!"<<endl;
		}
		
		void stampat(){
			Nodo* app=primo;
			cout<<endl<<" ";
			while(app!=NULL){
				cout<<app->getData()<<" ";
				app=app->getPunt_sx();
			}
			cout<<endl;
		}
		
		void trova(){
			if(primo==NULL)
				cout<<"Lista vuota"<<endl;
			else{
				int data;
				Nodo *app=primo;
				int i=1;
				cout<<"Inserisci il numero da trovare : ";
				cin>>data;
				while(app!=NULL){
					if(app->getData()==data){
						cout<<"Numero trovato, ho impiegato "<<i<<" cicli"<<endl;
						break;
					}
					app=app->getPunt_sx();
					i++;
				}
			}
		}
		
		void minorik(){
			if(primo==NULL)
				cout<<"Lista vuota"<<endl;
			else{
				int data;
				Nodo *app=primo;
				int i=1;
				cout<<"Inserisci il numero confrontare (k) : ";
				cin>>data;
				while(app!=NULL && app->getData()<=data){
					if(app->getData()<=data)
						cout<<app->getData()<<" ";
					app=app->getPunt_sx();
				}
				cout<<endl;
			}
		}
		
		void minmax(){
			if(primo==NULL)
				cout<<"Lista vuota"<<endl;
			else{
				int max=primo->getData(),min=primo->getData();
				Nodo *app=primo;
				while(app->getPunt_sx()!=NULL)
					app=app->getPunt_sx();
				max=app->getData();
				cout<<"Il numero minimo e' "<<min<<", massimo "<<max<<endl;
			}
		}
};

int main(){
	int scelta;
	Gestione obj;
	do{
		cout<<"Inserisci : "<<endl<<endl;
		cout<<"1) Inserire un nuovo numero."<<endl;
		cout<<"2) Stampare la lista."<<endl;
		cout<<"3) Trova un numero."<<endl;
		cout<<"4) Inserisci k e trova tutti i numeri minori o uguali ad esso"<<endl;
		cout<<"5) Visualizza massimo e minimo della lista"<<endl;
		cout<<"6) Esci."<<endl;
		cin>>scelta;
		switch(scelta){
			case 1: obj.inserisci();break;
			case 2: obj.stampat();break;
			case 3: obj.trova();break;
			case 4: obj.minorik();break;
			case 5: obj.minmax();break;
			case 6: cout<<"Stai per uscire.";break;
		}
	}while(scelta!=6);

	return 0;
}
