#include<iostream>
#include<string>

using namespace std;

class ExceptieImpartire
{
private:
	string mesaj;
public:
	ExceptieImpartire(string msg) {
		mesaj = msg;
	}
	string getMesaj() {
		return mesaj;
	}
};

class ClasaCuExceptii {
public:
	ClasaCuExceptii() throw (float) {
		//throw 7.6;
	}

	int sumaNumerePozitive(int a, int b) throw (int) {
		if (a < 0 || b < 0) {
			throw 301;
		}
		return a + b;
	}

	float impartire(float a, float b) {
		if (b == 0) {
			throw new ExceptieImpartire("NU pot realiza impartirea la 0");
		}
		return a / b;
	}

	int functie() {
		return 6;
	}
};



void main() {
	try {
		ClasaCuExceptii cce;
		cout<<cce.sumaNumerePozitive(4, 9)<<endl;
		cout << cce.impartire(8, 0)<<endl;

	}	
	catch (int codEroare) {
		cout << codEroare;
	}
	catch (ExceptieImpartire exI) {
		cout << exI.getMesaj()<<" prin valoare"<<endl;
	}
	catch (ExceptieImpartire* exP) {
		cout << exP->getMesaj() << " prin pointer." << endl;
	}
	catch (exception* ex) {
		cout << "Exceptie";
	}
	catch (...) {
		cout << "A aparut o problema necunoscuta.";
	}

}