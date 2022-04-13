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

	bool operator<(Laptop l) {
		return this->RAM < l.RAM;
	}

	friend ostream& operator<<(ostream& oStream, const Laptop& laptop) {
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
			for (int i = start-1; i < end; i++) {
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
	Laptop operator+(Laptop l2) {//l1 - este in this
		Laptop aux = *this;
		aux.RAM = this->RAM + l2.RAM;
		return aux;
	}

};

//Laptop operator+(Laptop l2,Laptop l3) {//l1 - este in this
//	Laptop aux = l2;
//	aux.RAM = this->RAM + l2.RAM;
//	return aux;
//}

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
	//de ce nu am folosit getteri
	aux.RAM = laptop.RAM + valoare;
	return aux;
}

void main() {
	//Laptop laptop1;
	//Laptop laptop2;
	//Laptop laptop3;

	////laptop3 = laptop1 + laptop2;
	//laptop3 = laptop1 + 4;
	//laptop3 = 4 + laptop2;
	////int val = aptop + 4;
	////etc

	//Laptop laptop6;
	////cin >> laptop6;
	////cout << laptop6;




	//laptop1.setRAM(6);
	//laptop2 = laptop1++;
	////laptop2- 6; laptop - 7

	//laptop1.setRAM(6);
	//laptop3 = ++laptop1;
	////laptop3 -7; laptop - 7


	//Laptop laptop9(10, "Intel", 13, true, 4, new int[4]{ 10,12,13,7 });
	//cout << laptop9[0];

	//laptop9[0] = 4;



	////int memorieRAMImplicit = laptop9;
	//int memorieRAMExplicit = (int)laptop9;


	//Laptop laptop10(10, "Intel", 13, true, 4, new int[4]{ 10,12,13,7 });
	//cout << endl;
	//cout << laptop10() << endl;
	//cout << laptop10(2)<<endl;
	//cout << laptop10(2, 4)<<endl;

	//cout << endl << endl;
	
	
	Laptop l34;
	l34.setRAM(1);
	cout << l34.getRAM()<<endl;
	cout << l34->getRAM()<<endl;

	//Laptop L23;
	//Laptop L24;
	//L23 = L24 + L24;
	//L23 = L24.operator+(L24);

	//cout << L23;
	//cin >> L23;

	////if (L23.getRAM() < L24.getRAM()) {

	////}

	////if (L23 < L24) {

	////}

	//L23.getNrApasariTasta()[0];
	//L23[0];

	//L23 = !L24;
}