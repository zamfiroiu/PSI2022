//
//#include<iostream>
//
//using namespace std;
//
//class Tasta{
//
//};
//
//
//class Laptop {
//private:
//	Tasta tasta;
//	int RAM;
//	string tipCPU;
//	float rezolutieEcran;
//	bool cameraWeb;
//
//public:
//
//	Laptop() {
//		RAM = 16;
//		tipCPU = "AMD";
//		rezolutieEcran = 13.3;
//		this->cameraWeb = true;
//	}
//
//	~Laptop() {
//		
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
//	Laptop *laptop;
//public:
//	bool poateIntraInConferintaVideo() {
//		return this->laptop->hasCameraWeb();
//	}
//
//	Programator()  {
//		this->nume = "Popescu";
//		this->laptop = new Laptop(12, true);
//	}
//	~Programator() {
//		if (this->laptop) {
//			delete this->laptop;
//		}
//	}
//};
//
//
//void main() {
//
//	Programator programator;
//	cout << (programator.poateIntraInConferintaVideo() ? "Are video" : "Nu are video");
//
//
//}