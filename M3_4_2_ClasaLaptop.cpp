//#include<iostream>
//using namespace std;
//
//class Laptop {
//private:
//	static int nrLaptopuri;
//	const int id;
//	int RAM;
//	string tipCPU;
//	float rezolutieEcran;
//	bool cameraWeb;
//	int nrTaste;
//	int* nrApasariTasta;
//
//public:
//
//	int getID() {
//		return this->id;
//	}
//	int getRAM() {
//		return this->RAM;
//	}
//	string getTipCPU() {
//		return tipCPU;
//	}
//	float getRezolutieEcran() {
//		return rezolutieEcran;
//	}
//	bool hasCameraWeb() {
//		return cameraWeb;
//	}
//
//	void setRAM(int RAM) {
//		if (RAM > 0) {
//			this->RAM = RAM;
//		}
//	}
//
//	void setTipCPU(string tipCPU) {
//		if (tipCPU.length() > 0) {
//			this->tipCPU = tipCPU;
//		}
//	}
//
//	void setRezolutieEcran(float rezolutieEcran) {
//		if (rezolutieEcran > 10) {
//			this->rezolutieEcran = rezolutieEcran;
//		}
//	}
//
//	void setCameraWeb(bool cameraWeb) {
//		this->cameraWeb = cameraWeb;
//	}
//
//	~Laptop() {
//		//dezalocari din HEAP
//	}
//
//	int getNrTaste() {
//		return nrTaste;
//	}
//
//	void setNrTaste(int nr) {
//		nrTaste = nr;
//	}
//
//	int* getNrApasariTasta() {
//		return nrApasariTasta;
//	}
//
//	void seNrApasariTasta(int* vector, int dim) {
//		if (dim > 0 && vector != NULL) {
//			if (this->nrApasariTasta != NULL) {
//				delete[]nrApasariTasta;
//			}
//			nrApasariTasta = new int[dim];
//			for (int i = 0; i < dim; i++) {
//				nrApasariTasta[i] = vector[i];
//			}
//			nrTaste = dim;
//		}
//	}
//
//	Laptop():id(0) {
//		RAM = 16;
//		tipCPU = "AMD";
//		rezolutieEcran = 13.3;
//		this->cameraWeb = true;
//		nrLaptopuri++;
//		nrTaste = 0;
//		nrApasariTasta = NULL;
//	}
//
//	Laptop(int newID, int RAM, string tipCPU, float rezolutieEcran, bool cameraWeb, int nrTaste, int* nrApasari):id(newID) {
//		this->RAM = RAM;
//		this->tipCPU = tipCPU;
//		this->rezolutieEcran = rezolutieEcran;
//		this->cameraWeb = cameraWeb;
//		this->nrTaste = nrTaste;
//		this->nrApasariTasta = new int[nrTaste];
//		for (int i = 0;i < nrTaste;i++) {
//			this->nrApasariTasta[i] = nrApasari[i];
//		}
//		nrLaptopuri++;
//	}
//	//constructor de copiere - semn de stop pentru incepatori
//	Laptop(Laptop &laptop):id(laptop.id) {
//		this->RAM = laptop.RAM;
//		this->tipCPU = laptop.tipCPU;
//		this->rezolutieEcran = laptop.rezolutieEcran;
//		this->cameraWeb = laptop.cameraWeb;
//		this->nrTaste = laptop.nrTaste;
//		//this->nrApasariTasta=laptop.nrApasariTasta; shalloCOpy - incorect
//		this->nrApasariTasta = new int[this->nrTaste];
//		for (int i = 0;i < this->nrTaste;i++) {
//			this->nrApasariTasta[i] = laptop.nrApasariTasta[i];
//		}
//		nrLaptopuri++;
//	}
//
//
//
//	//Laptop(int RAM, string tipCPU, float rezolutie, bool camera):id(0) {
//	//	this->RAM = RAM;
//	//	this->tipCPU = tipCPU;
//	//	this->rezolutieEcran = rezolutie;
//	//	this->cameraWeb = camera;
//	//}
//
//	//Laptop(int RAM, float rezolutie, bool camera):id(0) {
//	//	this->RAM = RAM;
//	//	this->tipCPU = "Intel";
//	//	this->rezolutieEcran = rezolutie;
//	//	this->cameraWeb = camera;
//	//}
//
//	//Laptop(int newRAM, float rezolutie, bool camera):RAM(newRAM),tipCPU("Intel"),
//	//												rezolutieEcran(rezolutie),
//	//												cameraWeb(camera) 
//	//{
//	//}
//
//	//Laptop(int RAM=12, string tipCPU="AMD", float rezolutie=15, bool camera=true) {
//	//	this->RAM = RAM;
//	//	this->tipCPU = tipCPU;
//	//	this->rezolutieEcran = rezolutie;
//	//	this->cameraWeb = camera;
//	//}
//
//
//
//	inline void modificaRAM(int RAM) {
//		this->RAM = RAM;
//	}
//
//	static int cateLaptopuriAvem() {
//		return nrLaptopuri;
//	}
//
//	void f(Laptop * l) {
//
//	}
//	
//
//	void modificaTipCPU(string newTipCPU);
//
//
//
//};
//
//void Laptop::modificaTipCPU(string newTipCPU) {
//	this->tipCPU = tipCPU;
//}
//
//int Laptop::nrLaptopuri = 0;
//
//void main() {
//	//Laptop laptop;
//
//
//	//{
//	//	Laptop l;
//	//	l.modificaRAM(40);
//	////1
//	//}
//	////2	
//
//	////Laptop l1(20, 13, true);
//	////Laptop l2(10, 15, false);
//
//	//cout << Laptop::cateLaptopuri();
//
//	//Laptop l;
//	//l.seNrApasariTasta(new int[4]{ 10,2,5,7 }, 4);
//	//cout<<l.getNrApasariTasta()[3];
//
//	Laptop l;
//	cout << l.getRAM();
//
//	cout << endl << Laptop::cateLaptopuriAvem();
//	cout << endl << l.cateLaptopuriAvem();
//
//	Laptop laptop1(1, 12, "AMD", 15, true, 3, new int[3]{ 3,4,2 });
//	Laptop laptopulPrietenului(laptop1);
//	Laptop laptop2 = laptop1;
//}
//
