#include<iostream>

using namespace std;

//Magazin

//Produs
//Raft
//Vanzator

class Vanzator {
private:
	const int marca;
	string nume;
	static int nrVanzatori;
	int nrLuniLucrate;
	int* nrZilePeLuna;
public:

	int getNrLuniLucrate() {
		return this->nrLuniLucrate;
	}
	int* getNrZilePeLuna() {
		return this->nrZilePeLuna;
	}

	int getNumarZileByLuna(int index) {
		if (index >= 0 && index < this->nrLuniLucrate) {
			return this->nrZilePeLuna[index];
		}
		else {
			return 0;
		}
	}
	void setLuniLucrate(int nrLuni, int* nrZilePeLuna) {
		if (nrLuni > 0 && nrZilePeLuna != NULL) {
			this->nrLuniLucrate = nrLuni;
			if (this->nrZilePeLuna != NULL) {
				delete[]this->nrZilePeLuna;
			}
			this->nrZilePeLuna = new int[nrLuni];
			for (int i = 0; i < nrLuni; i++) {
				this->nrZilePeLuna[i] = nrZilePeLuna[i];
			}
		}
	}

	int getMarca() {
		return this->marca;
	}
	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 2) {
			this->nume = nume;
		}
	}

	static int getNrVanzatori() {
		return nrVanzatori;
	}


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

	Vanzator(const Vanzator& v):marca(nrVanzatori++) {
		this->nume = v.nume;
		this->nrLuniLucrate = v.nrLuniLucrate;
		this->nrZilePeLuna = new int[v.nrLuniLucrate];
		for (int i = 0; i < v.nrLuniLucrate; i++) {
			this->nrZilePeLuna[i] = v.nrZilePeLuna[i];
		}
	}

	Vanzator operator=(const Vanzator& v) {
		if (this != &v) { //verificare de autoasignare
			this->nume = v.nume;
			this->nrLuniLucrate = v.nrLuniLucrate;
			if (this->nrZilePeLuna != NULL) {
				delete[]this->nrZilePeLuna;
			}
			this->nrZilePeLuna = new int[v.nrLuniLucrate];
			for (int i = 0; i < v.nrLuniLucrate; i++) {
				this->nrZilePeLuna[i] = v.nrZilePeLuna[i];
			}
		}
		return *this;
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
private:
	const int cod;
	static int contorCoduri;
	string denumire;
	float pret;
	float greutateReala;
	int cantitate;
	char* taraOrigine;
public:
	int getCod() {
		return this->cod;
	}

	string getDenumire() {
		return this->denumire;
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}

	float getGreutate() {
		return this->greutateReala;
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutateReala = greutate;
		}
	}

	int getCantitate() {
		return this->cantitate;
	}

	void setCantitate(int cantitate) {
		if (cantitate > 0) {
			this->cantitate = cantitate;
		}
	}

	char* getTaraOrigine() {
		return this->taraOrigine;
	}

	void setDenumire(string denumire) {
		if (denumire.length() > 0) {
			this->denumire = denumire;
		}
	}

	void setTaraOrigine(const char* tara) {
		if (strlen(tara) > 2) {
			if (this->taraOrigine != NULL) {
				delete[]this->taraOrigine;
			}
			this->taraOrigine = new char[strlen(tara) + 1];
			strcpy_s(this->taraOrigine, strlen(tara) + 1, tara);
		}
	}

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

	Produs(string denumire, float pret, float greutateReala, int cantitate, const char* taraOrigine) :cod(contorCoduri++) {
		this->denumire = denumire;
		this->pret = pret;
		this->greutateReala = greutateReala;
		this->cantitate = cantitate;
		this->taraOrigine = new char[strlen(taraOrigine) + 1];
		strcpy_s(this->taraOrigine, strlen(taraOrigine) + 1, taraOrigine);
	}

	Produs(const Produs& p) :cod(contorCoduri++) {
		this->denumire = p.denumire;
		this->pret = p.pret;
		this->greutateReala = p.greutateReala;
		this->cantitate = p.cantitate;
		if (p.taraOrigine != NULL) {
			this->taraOrigine = new char[strlen(p.taraOrigine) + 1];
			strcpy_s(this->taraOrigine, strlen(p.taraOrigine) + 1, p.taraOrigine);
		}else{
			this->taraOrigine = NULL;
		}
	}

	Produs operator=(const Produs& p) {
		if (this != &p) {//verificare de autoasignare
			this->denumire = p.denumire;
			this->pret = p.pret;
			this->greutateReala = p.greutateReala;
			this->cantitate = p.cantitate;
			if (this->taraOrigine != NULL) {
				delete[]this->taraOrigine;
			}
			if (p.taraOrigine != NULL) {
				this->taraOrigine = new char[strlen(p.taraOrigine) + 1];
				strcpy_s(this->taraOrigine, strlen(p.taraOrigine) + 1, p.taraOrigine);
			}
			else {
				this->taraOrigine = NULL;
			}
		}
		return *this;
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
private:
	const int nrRaft;
	string zona;
	int nrProduse;
	Produs* produse;
	float greutateSuportata;
public:

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
			this->produse[i] = produse[i];
		}
		this->greutateSuportata = greutateSuportata;
	}

	Raft(const Raft& r) :nrRaft(r.nrRaft) {
		this->zona = r.zona;
		this->nrProduse = r.nrProduse;
		this->produse = new Produs[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->produse[i] = r.produse[i];
		}
		this->greutateSuportata = r.greutateSuportata;
	}

	Raft operator=(const Raft& r) {
		if (this != &r) {
			this->zona = r.zona;
			this->nrProduse = r.nrProduse;

			if (this->produse) {
				delete[]this->produse;
			}
			this->produse = new Produs[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->produse[i] = r.produse[i];
			}
			this->greutateSuportata = r.greutateSuportata;
		}
		return *this;
	}

	~Raft() {
		if (this->produse) {
			delete[]this->produse;
		}
	}

	float getGreutate() {
		return this->greutateSuportata;
	}

	void setGreutate(float greutate) {
		if (greutate > 10) {
			this->greutateSuportata = greutate;
		}
	}

	int getNrProduse() {
		return this->nrProduse;
	}

	Produs* getProduse() {
		return this->produse;
	}

	int getNrRaft() {
		return this->nrRaft;
	}
	string getZona() {
		return this->zona;
	}
	void setZona(string zona) {
		if (zona.length() > 2) {
			this->zona = zona;
		}
	}
	void setProduse(int nrProduse, const Produs* produse) {
		if (nrProduse > 0 && produse != NULL) {
			this->nrProduse = nrProduse;
			if (this->produse != NULL) {
				delete[]this->produse;
			}
			this->produse = new Produs[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->produse[i] = produse[i];
			}
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

bool verificaGreutateDisponibilaRaft(Raft raft) {
	float greutateTotala = 0;
	for (int i = 0; i < raft.getNrProduse(); i++) {
		greutateTotala = greutateTotala + raft.getProduse()[i].getGreutate();
	}

	if (greutateTotala < raft.getGreutate()) {
		return true;
	}
	else {
		return false;
	}
}

void main() {

	Vanzator* v = new Vanzator[100];
	//cout<<Vanzator::getNrVanzatori();

	//Vanzator vanzator1;
	//Vanzator vanzator2("Ionescu");
	//int* vectorZile = new int[4] {22, 20, 21, 18};
	//Vanzator vanzator3("Vasilescu", 4, vectorZile);
	//Vanzator vanzator4 = vanzator3;
	//vanzator1 = vanzator4;
	//vanzator1.setNume("Georgescu");
	//int* vector2 = new int[3] {15, 18, 22};
	//vanzator1.setLuniLucrate(3, vector2);

	//cout << vanzator1.getMarca() << "." << vanzator1.getNume() << " a lucrat " 
	//	<< vanzator1.getNrLuniLucrate()<<" luni.";
	//for (int i = 0; i < vanzator1.getNrLuniLucrate(); i++)
	//{
	//	cout << vanzator1.getNumarZileByLuna(i)<<", ";
	//}
	//cout << endl;

	//cout << vanzator4.getMarca() << "." << vanzator4.getNume() << " a lucrat "
	//	<< vanzator4.getNrLuniLucrate() << " luni.";
	//for (int i = 0; i < vanzator4.getNrLuniLucrate(); i++)
	//{
	//	cout << vanzator4.getNumarZileByLuna(i) << ", ";
	//}
	//cout << endl;
	//vanzator1.afisare();
	//vanzator2.afisare();
	//vanzator3.afisare();

	//Produs produs1;
	//Produs produs2("Lapte", 12, 5);
	//Produs produs3("Carne", 34, 1000, 3, "Turcia");
	//Produs produs4 = produs3;
	//produs1 = produs3;
	//produs1.setDenumire("Paine");
	//cout << produs1.getDenumire() << " " << produs1.getGreutate() << " " << produs1.getTaraOrigine() << endl;
	//cout << produs4.getDenumire() << " " << produs4.getGreutate() << " " << produs4.getTaraOrigine() << endl;

	//cout << "Produse:" << endl;
	//produs1.afisare();
	//produs2.afisare();
	//produs3.afisare();

	//Raft raft1;
	//Raft raft2(7);
	//Produs* vector = new Produs[3];
	//vector[0] = produs1;
	//vector[1] = produs2;
	//vector[2] = produs3;
	//Raft raft3(5, "Lactate", 3, vector, 10000);
	//Raft raft4 = raft3;
	//raft1 = raft2;
	//cout << raft4.getNrRaft() << ". " << raft4.getGreutate() << " " << raft4.getZona() << " " << raft4.getNrProduse() << ":";
	//for (int i = 0; i < raft4.getNrProduse(); i++) {
	//	cout << raft4.getProduse()[i].getDenumire()<<", ";
	//}
	//raft1.afisare();
	//raft2.afisare();
	//raft3.afisare();

	//Vanzator vanzator;
	//cout << vanzator3.getNrZilePeLuna()[1];
	//cout << endl << vanzator3.getNumarZileByLuna(1);
	//cout<<verificaGreutateDisponibilaRaft(raft3);
}