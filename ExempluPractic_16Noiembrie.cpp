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

	int calculNumarTotalZile()const {
		int suma = 0;
		for (int i = 0; i < this->nrLuniLucrate; i++) {
			suma += this->nrZilePeLuna[i];
		}
		return suma;
	}

public:

	//operator<< - de afisare
	//cout<<vanzator;
	friend ostream& operator<<(ostream& monitor, const Vanzator& v) {
		monitor << v.marca << ". Vanzatorul " << v.nume << " a lucrat " << v.nrLuniLucrate << " luni, cu urmatoarele zile: ";
		for (int i = 0; i < v.nrLuniLucrate; i++) {
			monitor << v.nrZilePeLuna[i] << ", ";
		}
		monitor << endl;
		return monitor;
	}
	//operator>> - de citire
	friend istream& operator>>(istream& tastatura, Vanzator& v) {
		cout << "Numele:";
		tastatura >> v.nume;
		cout << "Numar luni lucrate:";
		tastatura >> v.nrLuniLucrate;
		if (v.nrZilePeLuna != NULL) {
			delete[]v.nrZilePeLuna;
		}
		v.nrZilePeLuna = new int[v.nrLuniLucrate];
		for (int i = 0; i < v.nrLuniLucrate; i++) {
			cout << "Numarul de zile lucrate in luna " << (i + 1)<<":";
			tastatura >> v.nrZilePeLuna[i];
		}
		return tastatura;
	}
	//operator[]
	int& operator[](unsigned int index) {
		if (index < this->nrLuniLucrate) {
			return this->nrZilePeLuna[index];
		}
	}

	//operator+ cu un intreg - numarul de zile dintr-o luna noua
	// 3 luni {20,21,22}
	// obiect1=obiect2+19;
	// obiect2+=19;
	// 4 luni{20,21,22,19}
	Vanzator operator+=(int nrZile) {
		int* temp = new int[this->nrLuniLucrate + 1];
		for (int i = 0; i < this->nrLuniLucrate; i++) {
			temp[i] = this->nrZilePeLuna[i];
		}
		temp[this->nrLuniLucrate] = nrZile;
		this->nrLuniLucrate++;
		if (this->nrZilePeLuna) {
			delete[]this->nrZilePeLuna;
		}
		this->nrZilePeLuna = temp;
		return *this;
	}

	Vanzator operator+(int nrZile) const {
		Vanzator aux = *this;

		int* temp = new int[aux.nrLuniLucrate + 1];
		for (int i = 0; i < aux.nrLuniLucrate; i++) {
			temp[i] = aux.nrZilePeLuna[i];
		}
		temp[aux.nrLuniLucrate] = nrZile;
		aux.nrLuniLucrate++;
		if (aux.nrZilePeLuna) {
			delete[]aux.nrZilePeLuna;
		}
		aux.nrZilePeLuna = temp;
		return aux;
	}
 
	//operator < (dupa numarul total de zile lucrate)
	bool operator<(const Vanzator& v) {
		return this->calculNumarTotalZile() < v.calculNumarTotalZile();
	}

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

	static void adaugaVanzatorInVector(Vanzator* &vector, int &dimensiune, const Vanzator& vanzator) {
		Vanzator* aux = new Vanzator[dimensiune + 1];
		for (int i = 0; i < dimensiune; i++) {
			aux[i] = vector[i];
		}
		aux[dimensiune] = vanzator;
		delete[]vector;
		vector = aux;
		dimensiune++;
	}


	static void adaugaPointerVanzatorInVector(Vanzator**& vector, int &dimensiune, const Vanzator& vanzator) {
		Vanzator** aux = new Vanzator * [dimensiune + 1];
		for (int i = 0; i < dimensiune; i++) {
			aux[i] = vector[i];
		}

		aux[dimensiune] = new Vanzator(vanzator);
		delete[]vector;
		vector = aux;
		dimensiune += 1;
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

	//operator++ pentru cantitate
	Produs operator++() {//forma prefixata
		this->cantitate++;
		return *this;
	}

	Produs operator++(int) {//forma postfixata
		Produs aux = *this;
		this->cantitate++;
		return aux;
	}
	
	//operator== pentru denumire, pret si cantitate
	bool operator==(const Produs& p)const {
		return this->cantitate == p.cantitate 
			&& this->pret == p.pret 
			&& this->denumire == p.denumire;
	}
	//operator+ adaugare de sufix la nume;
	Produs operator+(string sufix)const {
		Produs p = *this;
		p.denumire = p.denumire + sufix;
		return p;
	}

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

	//operator+ cu un produs
	Raft operator+(Produs p) {
		Raft aux = *this;
		Produs* temp = new Produs[aux.nrProduse + 1];
		for (int i = 0; i < aux.nrProduse; i++) {
			temp[i] = aux.produse[i];
		}
		temp[aux.nrProduse] = p;
		if (aux.produse) {
			delete[]aux.produse;
		}
		aux.nrProduse++;
		aux.produse = temp;
		return aux;
	}
	//operator+= cu un produs
	Raft operator+=(Produs p) {
		Produs* temp = new Produs[this->nrProduse + 1];
		for (int i = 0; i < this->nrProduse; i++) {
			temp[i] = this->produse[i];
		}
		temp[this->nrProduse] = p;
		if (this->produse != NULL) {
			delete[]this->produse;
		}
		this->nrProduse++;
		this->produse = temp;
		return *this;
	}
	//operator[] pentru vectorul de produse
	Produs& operator[](int index) {
		if (index >= 0 && index < this->nrProduse) {
			return this->produse[index];
		}
	}
	
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
	//*vector de obiecte de tip Vanzator
	//*adaugare obiect in vector
	//*vector de pointeri la Vanzator
	//*adaugarea unui pointer in vector
	
	//int nrVanzatori;
	//cout << "Cati vanzatori sunt in Magazin: ";
	//cin >> nrVanzatori;//2

	//Vanzator* vVanzatori = new Vanzator[nrVanzatori];
	//for (int i = 0; i < nrVanzatori; i++) {
	//	cin >> vVanzatori[i];
	//}

	//Vanzator vanzator("Georgescu");
	//Vanzator::adaugaVanzatorInVector(vVanzatori, nrVanzatori, vanzator);

	//for (int i = 0; i < nrVanzatori; i++) {
	//	cout << vVanzatori[i];
	//}

	//if (vVanzatori != NULL) {
	//	delete[]vVanzatori;
	//}


	//vector de pointeri
	int nrPointeri;
	cout << "Cati vanzatori:";
	cin >> nrPointeri;
	Vanzator** vpVanzatori = new Vanzator * [nrPointeri];
	for (int i = 0; i < nrPointeri; i++) {
		vpVanzatori[i] = new Vanzator();
		cin >> *(vpVanzatori[i]);
	}

	Vanzator vanzator("Georgescu Ionel");
	Vanzator::adaugaPointerVanzatorInVector(vpVanzatori, nrPointeri, vanzator);


	for (int i = 0; i < nrPointeri; i++) {
		cout << *(vpVanzatori[i]) << endl;
	}


	for (int i = 0; i < nrPointeri; i++) {
		delete vpVanzatori[i];
	}
	delete[]vpVanzatori;
}