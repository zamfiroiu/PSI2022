#include<iostream>

using namespace std;

//Magazin

//Produs
//Raft
//Vanzator

class Vanzator {
public:
	const int marca;
	string nume;
	static int nrVanzatori;
	int nrLuniLucrate;
	int* nrZilePeLuna;

	Vanzator() :marca(nrVanzatori++) {
		this->nume = "Vanzator incepator";
		this->nrLuniLucrate = 0;
		this->nrZilePeLuna = NULL;
	}

	Vanzator(string nume) :marca(nrVanzatori++) {
		this->nume = nume;
		this->nrLuniLucrate = 0;
		this->nrZilePeLuna = NULL;
	}

	Vanzator(string nume, int nrLuniLucrate, int* nrZilePeLuna) :marca(nrVanzatori++) {
		this->nume = nume;
		this->nrLuniLucrate = nrLuniLucrate;
		this->nrZilePeLuna = new int[nrLuniLucrate];
		for (int i = 0; i < nrLuniLucrate; i++) {
			this->nrZilePeLuna[i] = nrZilePeLuna[i];
		}
	}

	void afisare() {
		cout << this->marca<<". Vanzatorul " << this->nume << " a lucrat " << this->nrLuniLucrate << " luni, cu urmatoarele zile: ";
		for (int i = 0; i < this->nrLuniLucrate; i++) {
			cout << this->nrZilePeLuna[i] << ", ";
		}
		cout << endl;
	}

	~Vanzator() {
		if (this->nrZilePeLuna != NULL) {
			delete[]this->nrZilePeLuna;
		}
	}

};
int Vanzator::nrVanzatori = 0;

class Produs {
public:
	const int cod;
	static int contorCoduri;
	string denumire;
	float pret;
	float greutateReala;
	int cantitate;
	char* taraOrigine;

	Produs() :cod(contorCoduri++) {
		this->denumire = "";
		this->pret = 0;
		this->greutateReala = 0;
		this->cantitate = 0;
		this->taraOrigine = NULL;
	}

	Produs(string denumire, float pret, int cantitate) :cod(contorCoduri++) {
		this->denumire = denumire;
		this->pret = pret;
		this->cantitate = cantitate;
		this->greutateReala = 0;
		this->taraOrigine = new char[strlen("Romania") + 1];
		strcpy_s(this->taraOrigine, strlen("Romania") + 1, "Romania");
	}

	Produs(string denumire, float pret, float greutateReala, int cantitate,const  char* taraOrigine) :cod(contorCoduri++) {
		this->denumire = denumire;
		this->pret = pret;
		this->greutateReala = greutateReala;
		this->cantitate = cantitate;
		this->taraOrigine = new char[strlen(taraOrigine) + 1];
		strcpy_s(this->taraOrigine, strlen(taraOrigine) + 1, taraOrigine);
	}

	~Produs() {
		if (this->taraOrigine) {
			delete[]this->taraOrigine;
		}
	}

	void afisare() {
		cout << "Cod: " << this->cod<<". ";
		cout << "Denumire: " << this->denumire << ". ";
		cout << "Pret: " << this->pret<<". ";
		cout << "Greutate: " << this->greutateReala << ". ";
		cout << "Cantitate: " << this->cantitate << ". ";
		if (this->taraOrigine != NULL) {
			cout << "Tara: " << this->taraOrigine << endl;
		}
		else {
			cout << endl;
		}
	}
};
int Produs::contorCoduri = 1000;

class Raft {
public:
	const int nrRaft;
	string zona;
	int nrProduse;
	Produs* produse;
	float greutateSuportata;

	Raft() :nrRaft(1) {
		this->zona = "";
		this->nrProduse = 0;
		this->produse = NULL;
		this->greutateSuportata = 100000;
	}

	Raft(int nrRaftNou) :nrRaft(nrRaftNou) {
		this->zona = "";
		this->nrProduse = 0;
		this->produse = NULL;
		this->greutateSuportata = 100000;
	}
	Raft(int nrRaftNou, string zona, int nrProduse, Produs* produse, float greutateSuportata) :nrRaft(nrRaftNou) {
		this->zona = zona;
		this->nrProduse = nrProduse;
		this->produse = new Produs[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			//this->produse[i] = produse[i];
		}
		this->greutateSuportata = greutateSuportata;
	}

	~Raft() {
		if (this->produse) {
			delete[]this->produse;
		}
	}

	void afisare() {
		cout << "Numar raft: " << this->nrRaft << ". ";
		cout << "Zona: " << this->zona << ". ";
		cout << "Greutate suportata: " << this->greutateSuportata << ". ";
		cout << "Numar produse: " << this->nrProduse<<". "<<endl;
		for (int i = 0; i < this->nrProduse; i++) {
			cout << "\t";
			this->produse[i].afisare();
		}
		cout << endl;
	}
};

void main() {

	Vanzator vanzator1;
	Vanzator vanzator2("Ionescu");
	int* vectorZile = new int[4] {22, 20, 21, 18};
	Vanzator vanzator3("Vasilescu", 4, vectorZile);

	vanzator1.afisare();
	vanzator2.afisare();
	vanzator3.afisare();

	Produs produs1;
	Produs produs2("Lapte", 12, 5);
	Produs produs3("Carne", 34, 1000, 3, "Turcia");

	cout << "Produse:" << endl;
	produs1.afisare();
	produs2.afisare();
	produs3.afisare();

	Raft raft1;
	Raft raft2(7);
	Produs* vector = new Produs[3];
	Raft raft3(5, "Lactate", 3, vector, 1000000);
	raft1.afisare();
	raft2.afisare();
	raft3.afisare();

	Vanzator vanzator;

}