#include<iostream>
#include<string>

using namespace std;

/*
Sa se foloseasca un vector penru gestiunea unui magazin de piese auto
Se considera produsele din acel magazin - vector de string-uri
Sunt de asemenea considerate si preturile de la producator pentru aceste produse - vector de float
si preturile de vanzare - vector de float-uri

Cerinte:
1. O functie care sa calculeze profitul agregat pentru toate produsele
2. O functie pentru determinarea piesei cu profitul cel mai mare.
3. O functe care determina piesele cu pierderi si valorile acestor pierderi.
4. O functie care calculeaza TVA-ul platit pentru fiecare piesa
5. O functie care calculeaza TVA-ul total

*/

//I:vectorul de tva-uri - float*, nr piese -int
//O: valoarea totalTVA - float

float calculeazaTVATotal(float* TVA_uri, int nrPiese) {
	float suma = 0;
	for (int i = 0;i < nrPiese;i++) {
		suma += TVA_uri[i];
	}
	return suma;
}

//I: preturile de achizitie - float* , TVA - int, numarul de piese -int 
//O: valorile TVA platite - float*

float* calculeazaTVAPlatit(float* preturiAchizitie, int nrPiese, int TVA) {
	float* TVA_uri = new float[nrPiese];
	for (int i = 0;i < nrPiese;i++) {
		TVA_uri[i] = preturiAchizitie[i] - (preturiAchizitie[i] / ((100 + TVA) / 100.0f));
	}
	return TVA_uri;
}


//I: denumiripese - string*, preturivanzare - float*,preturi achizitie-float*, numarul piese - int
//O:vector denumiri - string*, profitNegativ- float*, numarul de piese cu profitNegativ- int

void getPieseCuPierderi(string* denumiri, float* preturiV, float* preturiA, int nrPiese, 
	string*& denumiriPiese, float*& profituri, int& nrPieseNegative) {
	int nrPieseDeterminate = 0;
	for (int i = 0;i < nrPiese;i++) {
		if (preturiV[i] - preturiA[i] < 0) {
			nrPieseDeterminate++;
		}
	}
	nrPieseNegative = nrPieseDeterminate;
	denumiriPiese = new string[nrPieseDeterminate];
	profituri = new float[nrPieseDeterminate];
	
	int k = 0;
	for (int i = 0;i < nrPiese;i++) {
		if (preturiV[i] - preturiA[i] < 0) {
			denumiriPiese[k] = denumiri[i];
			profituri[k] = preturiV[i] - preturiA[i];
			k++;
		}
	}
}



//I:vectorAchizitii - float*, vectorVanzari-float*, numarul de elemente - int
//O: profitul agregat - float
float calculareProfitAgregat(float* pretAchizitie, float* pretVanzare, int n) {
	float profitAgregat = 0.0f;
	for (int i = 0;i < n;i++) {
		float diferenta = pretVanzare[i] - pretAchizitie[i];
		profitAgregat += diferenta;//profitAgregat=profitAgregat + diferenta;
	}
	return profitAgregat;
}

//I: denumirepiese - string* , preturiachizitie - float*, preturiVanzare - float*, nrPiese- int
//O: denumire piesa - string; 
string getPiesaProfitMaxim(string* denumiri, float* pretAchizitie, float* pretVanzare, int nrPiese) {
	if (nrPiese > 0) {
		string rezultat = denumiri[0];
		float profitMaxim = pretVanzare[0] - pretAchizitie[0];
		for (int i = 1;i < nrPiese;i++) {
			if (profitMaxim < pretVanzare[i] - pretAchizitie[i]) {
				rezultat = denumiri[i];
				profitMaxim = pretVanzare[i] - pretAchizitie[i];
			}
		}
		return rezultat;
	}
	else {
		return "Nu avem produse";
	}
}



void main() {
	string* denumiriProduse = NULL;
	float* preturiAchizitie = NULL;
	float* preturiVanzare = NULL;
	int nrProduse;
	cout << "Introduceti numarul de produse:";
	cin >> nrProduse;

	denumiriProduse = new string[nrProduse];
	preturiAchizitie = new float[nrProduse];
	preturiVanzare = new float[nrProduse];

	for (int i = 0;i < nrProduse;i++) {
		cout << "Denumire produs:";
		cin >> denumiriProduse[i];
		cout << "Pret achizitie:";
		cin >> preturiAchizitie[i];
		cout << "Pret vanzare:";
		cin >> preturiVanzare[i];
	}

	for (int i = 0;i < nrProduse;i++) {
		cout << denumiriProduse[i] << " " << preturiAchizitie[i] << " " << preturiVanzare[i] << endl;
	}

	cout << "Profitul total este: " << calculareProfitAgregat(preturiAchizitie, preturiVanzare, nrProduse) << endl;

	cout << "Piesa cu profitul maxim este:" << getPiesaProfitMaxim(denumiriProduse, preturiAchizitie, preturiVanzare, nrProduse)<<endl;

	string* denumiriPieseCuPierderi = NULL;
	float* profituriNegative = NULL;
	int nrPieseCuPierderi = 0;
	getPieseCuPierderi(denumiriProduse, preturiVanzare, preturiAchizitie, nrProduse, 
		denumiriPieseCuPierderi, profituriNegative, nrPieseCuPierderi);

	for (int i = 0;i < nrPieseCuPierderi;i++) {
		cout << "Piesa " << denumiriPieseCuPierderi[i] << " a avut pierdere de " 
			<< profituriNegative[i] << " RON." << endl;
	}

	float* TVA_uri = calculeazaTVAPlatit(preturiAchizitie, nrProduse, 19);
	for (int i = 0;i < nrProduse;i++) {
		cout << "Piesa " << denumiriProduse[i] << " a avut TVA-ul de "
			<< TVA_uri[i] << " RON." << endl;
	}
	//TVATotal
	cout << "TVA-ul total platit este: " << calculeazaTVATotal(TVA_uri, nrProduse)<<endl;
	delete[]denumiriProduse;
	delete[]preturiAchizitie;
	delete[]preturiVanzare;
	delete[]denumiriPieseCuPierderi;
	delete[]profituriNegative;
	delete[]TVA_uri;
}
