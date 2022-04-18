#include<iostream>
#include<string>
using namespace std;


class Laptop {
	static int nrLaptopuri;
	const int id;
	int RAM;
	string tipCPU;
	float rezolutieEcran;
	bool cameraWeb;
	int nrTaste;
	int* nrApasariTasta;

protected:
	int atributProtected;

public:

	Laptop operator=(const Laptop &laptop) {
		this->RAM = laptop.RAM;
		this->tipCPU = laptop.tipCPU;
		this->rezolutieEcran = laptop.rezolutieEcran;
		this->cameraWeb = laptop.cameraWeb;
		this->nrTaste = laptop.nrTaste;
		if (this->nrApasariTasta != NULL) {
			delete[]nrApasariTasta;
		}
		this->nrApasariTasta = new int[this->nrTaste];
		for (int i = 0; i < this->nrTaste; i++) {
			this->nrApasariTasta[i] = laptop.nrApasariTasta[i];
		}

		return *this;
	}

	Laptop(const Laptop& laptop):id(laptop.id) {
		this->RAM = laptop.RAM;
		this->tipCPU = laptop.tipCPU;
		this->rezolutieEcran = laptop.rezolutieEcran;
		this->cameraWeb = laptop.cameraWeb;
		this->nrTaste = laptop.nrTaste;
		this->nrApasariTasta = new int[this->nrTaste];
		for (int i = 0;i < this->nrTaste;i++) {
			this->nrApasariTasta[i] = laptop.nrApasariTasta[i];
		}
	}


	int getID() {
		return id;
	}
	int getRAM() {
		return RAM;
	}
	string getTipCPU() {
		return tipCPU;
	}
	float getRezolutieEcran() {
		return rezolutieEcran;
	}
	bool hasCameraWeb() {
		return cameraWeb;
	}

	void setRAM(int RAM) {
		if (RAM > 0) {
			this->RAM = RAM;
		}
	}

	void setTipCPU(string tipCPU) {
		if (tipCPU.length() > 0) {
			this->tipCPU = tipCPU;
		}
	}

	void setRezolutieEcran(float rezolutieEcran) {
		if (rezolutieEcran > 10) {
			this->rezolutieEcran = rezolutieEcran;
		}
	}

	void setCameraWeb(bool cameraWeb) {
		this->cameraWeb = cameraWeb;
	}

	~Laptop() {
		//dezalocari din HEAP
		if (this->nrApasariTasta != NULL) {
			delete[]nrApasariTasta;
		}
	}

	int getNrTaste() {
		return nrTaste;
	}

	void setNrTaste(int nr) {
		nrTaste = nr;
	}

	int* getNrApasariTasta() {
		return nrApasariTasta;
	}

	void seNrApasariTasta(int* vector, int dim) {
		if (dim > 0 && vector != NULL) {
			if (this->nrApasariTasta != NULL) {
				delete[]nrApasariTasta;
			}
			nrApasariTasta = new int[dim];
			for (int i = 0; i < dim; i++) {
				nrApasariTasta[i] = vector[i];
			}
			nrTaste = dim;
		}
	}

	Laptop() :id(0) {
		RAM = 16;
		tipCPU = "AMD";
		rezolutieEcran = 13.3;
		this->cameraWeb = true;
		this->nrLaptopuri++;
		nrTaste = 0;
		nrApasariTasta = NULL;
	}

	Laptop(int RAM, string tipCPU, float rezolutie, bool camera) :id(0) {
		this->RAM = RAM;
		this->tipCPU = tipCPU;
		this->rezolutieEcran = rezolutie;
		this->cameraWeb = camera;
	}

	Laptop(int RAM, string tipCPU, float rezolutie, bool camera, int nrTaste, int*nrApasariTaste) :id(0) {
		this->RAM = RAM;
		this->tipCPU = tipCPU;
		this->rezolutieEcran = rezolutie;
		this->cameraWeb = camera;
		this->nrTaste = nrTaste;
		this->nrApasariTasta = new int[nrTaste];
		for (int i = 0; i < nrTaste; i++) {
			this->nrApasariTasta[i] = nrApasariTaste[i];
		}
	}

	Laptop(int RAM, float rezolutie, bool camera) :id(0) {
		this->RAM = RAM;
		this->tipCPU = "Intel";
		this->rezolutieEcran = rezolutie;
		this->cameraWeb = camera;
	}


	Laptop operator+(int valoare) {
		Laptop aux = *this;
		aux.RAM = this->RAM + valoare;
		return aux;
	}
	friend Laptop operator+ (int, Laptop);


	friend ostream& operator<<(ostream& oStream, Laptop laptop) {
		oStream << laptop.id << " " << laptop.RAM << " " << laptop.tipCPU << " ";
		oStream << laptop.nrTaste << " " << laptop.rezolutieEcran << " cu numarul de apasari:";
		for (int i = 0; i < laptop.nrTaste; i++) {
			oStream << laptop.nrApasariTasta[i];
		}
		return oStream;
	};
	friend istream& operator>>(istream& iStream, Laptop& laptop) {
		cout << "RAM:";
		iStream >> laptop.RAM;
		cout << "Tip CPU:";
		iStream >> laptop.tipCPU;
		cout << "Rezolutie:";
		iStream >> laptop.rezolutieEcran;
		cout << "Numar taste:";
		iStream >> laptop.nrTaste;
		if (laptop.nrApasariTasta != NULL) {
			delete[]laptop.nrApasariTasta;
		}
		laptop.nrApasariTasta = new int[laptop.nrTaste];
		for (int i = 0; i < laptop.nrTaste; i++) {
			cout << "Numarul de apasari pntru tasta " << (i + 1) << ":";
			iStream >> laptop.nrApasariTasta[i];
		}
		return iStream;
	};

	Laptop operator++() {
		this->RAM++;
		return *this;
	}

	Laptop operator++(int) {
		Laptop copie = *this;
		this->RAM++;
		return copie;
	}


	int& operator[](int index) {
		if (index >= 0 && index < nrTaste) {
			return nrApasariTasta[index];
		}
	}


	explicit operator int() {
		return RAM;
	}

	Laptop operator! () {
		Laptop copie = *this;
		copie.cameraWeb = !copie.cameraWeb;
		return copie;
	}

	//numarul total de apasari
	int operator()() {
		int suma = 0;
		for (int i = 0; i < this->nrTaste; i++) {
			suma += this->nrApasariTasta[i];
		}
		return suma;
	}

	//numarul de apasari pt primele n taste
	int operator()(int n) {
		if (n > 0 && n < this->nrTaste) {
			int suma = 0;
			for (int i = 0; i < n; i++) {
				suma += this->nrApasariTasta[i];
			}
			return suma;
		}
		else {
			return 0;
		}
	}

	//numarul de apasari pt tastele dintr-un interval
	int operator()(int start, int end) {
		if (start > 0 && start < this->nrTaste && end <= this->nrTaste && start < end) {
			int suma = 0;
			for (int i = start - 1; i < end; i++) {
				suma += this->nrApasariTasta[i];
			}
			return suma;
		}
		else {
			return 0;
		}
	}

	Laptop* operator->() {
		this->RAM = 1000;
		return this;
	}



};

int Laptop::nrLaptopuri = 0;


//ostream& operator<<(ostream& oStream, Laptop laptop) {
//	oStream << laptop.id << " " << laptop.RAM << " " << laptop.tipCPU<<" ";
//	oStream << laptop.nrTaste << " " << laptop.rezolutieEcran << " cu numarul de apasari:";
//	for (int i = 0; i < laptop.nrTaste; i++) {
//		oStream << laptop.nrApasariTasta[i];
//	}
//	return oStream;
//}
//istream& operator>>(istream& iStream, Laptop& laptop) {
//	cout << "RAM:";
//	iStream >> laptop.RAM;
//	cout << "Tip CPU:";
//	iStream >> laptop.tipCPU;
//	cout << "Rezolutie:";
//	iStream >> laptop.rezolutieEcran;
//	cout << "Numar taste:";
//	iStream >> laptop.nrTaste;
//	if (laptop.nrApasariTasta != NULL) {
//		delete[]laptop.nrApasariTasta;
//	}
//	laptop.nrApasariTasta = new int[laptop.nrTaste];
//	for (int i = 0; i < laptop.nrTaste; i++) {
//		cout << "Numarul de apasari pntru tasta " << (i + 1) << ":";
//		iStream >> laptop.nrApasariTasta[i];
//	}
//	return iStream;
//}
//

Laptop operator+ (int valoare, Laptop laptop) {
	Laptop aux = laptop;
	aux.RAM = laptop.RAM + valoare;
	return aux;
}

class LaptopTouchScreen :public Laptop {
private:
	int nrPuncteTouch;
protected:
	bool touchActiv;
public:

	void metoda() {
		this->atributProtected = 4;
		this->getID();
	}

	LaptopTouchScreen() :Laptop() {
		nrPuncteTouch = 2;
		touchActiv = true;
	}

	LaptopTouchScreen(int nrPuncte, bool touchActiv) :Laptop(12, 13, true) {
		this->nrPuncteTouch = nrPuncte;
		this->touchActiv = touchActiv;
	}

	LaptopTouchScreen(int RAM, float rezolutie, bool camera, int nrPuncte, bool touchActiv) :Laptop(RAM, rezolutie, camera) {
		this->nrPuncteTouch = nrPuncte;
		this->touchActiv = touchActiv;
	}

	~LaptopTouchScreen() {
		//este dezalocata memoria alocata pentu atributele clasei derivate
		//apoi este apelat destructorul clasei de baza(Laptop)
	}

	LaptopTouchScreen(const LaptopTouchScreen& lts):Laptop(lts) {
		this->nrPuncteTouch = lts.nrPuncteTouch;
		this->touchActiv = lts.touchActiv;
	}

	LaptopTouchScreen& operator=(const LaptopTouchScreen& l) {
		Laptop::operator=(l);
		//((Laptop)*this) = ((Laptop)l);
		this->nrPuncteTouch = l.nrPuncteTouch;
		this->touchActiv = l.touchActiv;
		return *this;
	}

	LaptopTouchScreen(const Laptop& l):Laptop(l) {
		this->nrPuncteTouch = 3;
		this->touchActiv = true;
	}

	LaptopTouchScreen operator=(const Laptop& l) {
		Laptop::operator=(l);
		this->nrPuncteTouch = 2;
		this->touchActiv = true;
		return *this;
	}
	
};

class Persoana {

};

class Programator:public Persoana {
public:
	Persoana teamLeader;
	string nume;
	Laptop laptopPersonal;
	LaptopTouchScreen laptopMunca;

};

void main() {

	Laptop laptopNou;
	//laptopNou.atributProtected;

	LaptopTouchScreen lts;
	lts.getID();
	laptopNou.getID();

	LaptopTouchScreen lts2(lts);

	Laptop l;
	LaptopTouchScreen lts3(l);
	lts3 = lts2;

	Laptop laptop = lts2;

	LaptopTouchScreen lts4 = laptop;
}