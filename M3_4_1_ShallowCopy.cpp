#include<iostream>

using namespace std;

class Clasa {
public:
	char* pointer;
	int atribut;

	const Clasa& operator=(const Clasa &c) {
		if (this->pointer != NULL)
		{
			delete[]this->pointer;
		}
		
		this->pointer = new char[strlen(c.pointer) + 1];
		strcpy(this->pointer, c.pointer);
		this->atribut = c.atribut;
		return *this;
	}
	
	Clasa(const Clasa &c) {
		this->pointer = new char[strlen(c.pointer) + 1];
		strcpy(this->pointer, c.pointer);
		this->atribut = c.atribut;
	}

	Clasa() {
		this->pointer = NULL;
	}

	void metoda(Clasa c) {

	}

	Clasa metoda2() {
		Clasa c;
		c.pointer = new char[strlen("default") + 1];
		strcpy(c.pointer, "default");
		return c;
	}


};

void main() {
	Clasa c1;
	c1.pointer = new char[strlen("text") + 1];
	strcpy(c1.pointer, "text");
	c1.atribut = 10;

	
	Clasa c2 = c1;
	strcpy(c2.pointer, "newT");

	Clasa c3;
	c3 = c1;

	cout << c1.pointer;

	//Clasa c1;
	//c1.pointer = new char[strlen("text") + 1];
	//strcpy(c1.pointer, "text");

	////c1.metoda(c1);
	////c1.metoda2();

	//Clasa c2;
	//c2 = c1;

	c1.metoda(c2);

	c1.metoda2();
}