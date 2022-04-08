#include<iostream>

using namespace std;


class Cana {
private:
	char* culoare;
	float cantitate;
	int inaltime;

public:
	Cana() {
		this->culoare = NULL;
		this->cantitate = 0;
		this->inaltime = 0;
	}
	Cana(const char* culoare, float cantitate, int inaltime) {
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
		this->cantitate = cantitate;
		this->inaltime = inaltime;
	}

	void afisareCana() {
		cout << "Cana de culoare " << culoare << " are " << cantitate << " ml si o inaltime de " << inaltime << " cm." << endl;
	}
	void setCuloare(const char* culoare) {
		if (culoare) {
			if (this->culoare) {
				delete[]this->culoare;
			}
			this->culoare = new char[strlen(culoare) + 1];
			strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
		}
	}
	char* getCuloare() {
		return this->culoare;
	}
	~Cana() {
		if (this->culoare) {
			delete[]this->culoare;
		}
	}
	Cana(const Cana& c) {
		this->culoare = new char[strlen(c.culoare) + 1];
		strcpy_s(this->culoare, strlen(c.culoare) + 1, c.culoare);
		this->cantitate = c.cantitate;
		this->inaltime = c.inaltime;
	}

	const Cana& operator=(const Cana &b) {
		if (this != &b) {
			if (this->culoare) {
				delete[]this->culoare;
			}
			this->culoare = new char[strlen(b.culoare) + 1];
			strcpy_s(this->culoare, strlen(b.culoare) + 1, b.culoare);
			this->cantitate = b.cantitate;
			this->inaltime = b.inaltime;			
		}
		return *this;
	}

	explicit operator int() {
		return this->inaltime;
	}

	explicit operator float() {
		return this->cantitate;
	}

};

void main() {
	//Cana a("Alb",250,9);
	//Cana b("Crem",180,7);

	//a = b;
	//a.operator=(b);// operator=(a,b)

	//a = a;//operator=(a,a);

	//vector de obiecte
	Cana* cani;

	int nrCani = 2;
	cani = new Cana[nrCani];
	for (int i = 0;i < nrCani;i++) {
		cani[i].setCuloare("Rosie");
	}

	for (int i = 0;i < nrCani;i++) {
		cout << cani[i].getCuloare() << endl;
	}
	//dezalocare vector de obiecte
	if (cani) {
		delete[]cani;
	}

	//vector de pointeri
	Cana* * raftDeCani;
	int nrCaniRaft = 3;
	raftDeCani = new Cana * [nrCaniRaft];
	for (int i = 0;i < nrCaniRaft;i++) {
		raftDeCani[i] = new Cana("Crem",(i+1)*100,i+5);
	}

	for (int i = 0;i < nrCaniRaft;i++) {
		raftDeCani[i]->afisareCana();
	}
	//dezalocare vector de pointeri
	if (raftDeCani) {
		for (int i = 0;i < nrCaniRaft;i++) {
			delete raftDeCani[i];
		}
		delete[]raftDeCani;
	}

	int a = 5;
	float b = a;
	double c = 5.8;
	b = 5.6f;
	a = (float)c;

	Cana cana("Alba", 200, 7);
	int inaltime = (int)cana;
	float cantitate = (float)cana;

	cout <<endl<< "Inaltime: " << inaltime << " Cantitate: " << cantitate << endl;

}