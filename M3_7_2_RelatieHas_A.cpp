//
//#include<iostream>
//
//using namespace std;
//
//
//class Laptop {
//private:
//	int RAM;
//	string tipCPU;
//	float rezolutieEcran;
//	bool cameraWeb;
//
//public:
//
//	Laptop(const Laptop& laptop) {
//		RAM = laptop.RAM;
//		tipCPU = laptop.tipCPU;
//		rezolutieEcran = laptop.rezolutieEcran;
//		this->cameraWeb = laptop.cameraWeb;
//	}
//
//	Laptop() {
//		RAM = 16;
//		tipCPU = "AMD";
//		rezolutieEcran = 13.3;
//		this->cameraWeb = true;
//	}
//
//	Laptop(int Ram, bool cameraWeb) {
//		this->RAM = Ram;
//		this->cameraWeb = cameraWeb;
//		this->tipCPU = "AMD";
//		this->rezolutieEcran = 13.3;
//	}
//
//	bool hasCameraWeb() {
//		return cameraWeb;
//	}
//
//	int getRAM() {
//		return this->RAM;
//	}
//
//	void setRAM(int RAM) {
//		if (RAM > 0) {
//			this->RAM = RAM;
//		}
//	}
//};
//
//class Programator {
//private:
//	string nume;
//	Laptop laptop;
//public:
//
//	Laptop getLaptop() {
//		return this->laptop;
//	}
//	void setLaptop(Laptop laptop) {
//		this->laptop = laptop;
//	}
//	Programator(const Programator& programator) {
//
//	}
//	bool poateIntraInConferintaVideo() {
//		return this->laptop.hasCameraWeb();
//	}	
//	//Programator() {
//	//	nume="Popescu";
//	//	Laptop aux(12, true);
//	//	this->laptop=aux;
//	//}
//	//Programator() {
//	//	this->nume="Popescu";
//
//	//	this->laptop.setRAM(12);
//	//}
//
//	Programator():laptop(12,true) {
//		this->nume = "Popescu";
//	}
//
//	void functieMetoda(Laptop laptop) {
//
//	}
//};
//
//
//void functieGlobala(Laptop laptop, Programator programator) {
//	programator.functieMetoda(laptop);
//}
//
//void main() {
//	
//	Programator programator;
//	cout << (programator.poateIntraInConferintaVideo() ? "Are video" : "Nu are video");
//	Laptop laptop(12, true);
//	functieGlobala(laptop, programator);
//
//	laptop.setRAM(24);
//	programator.getLaptop().setRAM(32);
//
//}