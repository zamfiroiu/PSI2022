#include<iostream>
#include<string>

using namespace std;
//
//Pentru crearea unei liste de Cafele trebuie să reținem aroma 
// cafelei și cantitatea acesteia.
// 
//Creați doi vectori pentru reținerea acestor informații.
// Unul pentru reținerea aromelor și unul pentru reținerea
//cantitatilor.Citiți de la tastatură informațiile necesare acestor cafele.
// De asemenea citiți și numărul de cafele.
// 
// 300, 400, 500, 600....350
// 
// Creați o funcție care calculează cantitatea tuturor cafelelor.
// 
// Creați o funcție care calculează cantitatea cafelelor care au 
// denumirea aromei mai lunga de o valoare primita ca parametru.
// 
// Creați o funcție care determina cate cafele au cantitatea mai mica decât o valoare primita.
// 
//Creați o funcție care returnează un vector cu aromele cafelelor care au cantitatea mai mare decât o valoare primită.
// 
// Creați alte doua funcții la alegere de procesare asupra celor doi 
// vectori si explicați utilitatea acestora.
//

int calculeazaCantitateTotala(int* vector, int nrCafele) {
	int total = 0;
	for (int i = 0; i < nrCafele; i++) {
		total = total + vector[i]; //total += vector[i]
	}
	return total;
}

int calculeazaCantitatePentruAnumiteCafele(int* cantitati, string* arome, int nrCafele, int lungimeMinima) {
	int total = 0;
	for (int i = 0; i < nrCafele; i++) {
		if (arome[i].length() >= lungimeMinima) {
			total += cantitati[i];
		}
	}
	return total;
}

int calculeazaNumarCafele(int prag, int* cantitati, int nrCafele) {
	int nr = 0;
	for (int i = 0; i < nrCafele; i++) {
		if (cantitati[i] < prag) {
			nr++;
		}
	}
	return nr;
}

//i:prag,cantitati,arome, nrCafele
//o:vector arome, nrElemente

string* determinaCafelelecuCantitateMare(int prag, int* cantitati, string* arome, int nrCafele, int& nrElemente) {
	string* rezultat;
	nrElemente = nrCafele - calculeazaNumarCafele(prag, cantitati, nrCafele);
	rezultat = new string[nrElemente];
	int j = 0;
	for (int i = 0; i < nrCafele; i++) {
		if (cantitati[i] >= prag) {
			rezultat[j] = arome[i];
			j++;
		}
	}
	return rezultat;
}


void main() {
	int nrCafele; //retine cate elemente vom avea in vectori
	string* arome; //vectorul cu arome
	int* cantitati;//vectorul cu cantitati
	cout << "Introduceti numarul de cafele:";
	cin >> nrCafele;
	arome = new string[nrCafele];
	cantitati = new int[nrCafele];
	char buffer[20];

	for (int i = 0; i < nrCafele; i++) {
		cout << "Cafea "<<i+1<<": aroma:";
		cin.getline(buffer, 20);
		cin.getline(buffer, 20);
		arome[i] = buffer;
		cout << "cantitate: ";
		cin >> cantitati[i];
	}

	for (int i = 0; i < nrCafele; i++) {
		cout << "Aroma:" << arome[i] << ", cantitate: " << cantitati[i] << endl;
	}

	cout <<endl<< "Cantitate totala de cafea: " << calculeazaCantitateTotala(cantitati, nrCafele)<<endl;
	int prag;
	cout << "Care este lungimea minima pentru aroma:";
	cin >> prag;
	cout << endl << "Cantitate pentru cafelele cu aroma de lungime data: " 
		<< calculeazaCantitatePentruAnumiteCafele(cantitati, arome, nrCafele, prag)<<endl;

	cout << "Care este cantitatea maxima pentru cafele: ";
	cin >> prag;
	cout << calculeazaNumarCafele(prag, cantitati, nrCafele) << " cafele au cantitatea mai mica decat " << prag << "." << endl;

	int nrCafeleSelecte=0;
	string* aromeSelecte = determinaCafelelecuCantitateMare(prag, cantitati, arome, nrCafele, nrCafeleSelecte);

	cout << "cafele selecte:" << endl;
	for (int i = 0; i < nrCafeleSelecte; i++) {
		cout << aromeSelecte[i] << ", ";
	}
}


