#include<iostream>
using namespace std;

class NumeClasa {
public:
	static int contor;
	const int id;
	int atribut1;
	float atribut2;
	void metoda1() {//metoda1(NumeClasa *this)
		cout << this->atribut1;
		//(*this).atribut1;
	};
	NumeClasa():id(10) {
		
		this->atribut1 = 5;
		this->atribut2 = 7;
	}

	NumeClasa(int p1, int p2) :atribut1(p1), atribut2(p2),id(10) {
		//this->atribut1 = p1;
	}

	~NumeClasa() {
		//destructor
	}
	//void metoda2(int a); //metoda2(NumeClasa* this, int a)
};
int NumeClasa::contor = 0;

void functie() {
	cout << "Functie;";
}

void main() {

	//NumeClasa obiect1;
	//obiect1.atribut1 = 1;

	//NumeClasa obiect2;
	//obiect2.atribut1 = 2;

	//obiect2.metoda1();

	//NumeClasa o1;
	//o1.metoda1();

	NumeClasa ob2;
	//NumeClasa ob3(12, 14);

	NumeClasa *p =new NumeClasa(12,14);


	delete p;


}

