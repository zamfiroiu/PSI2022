#include<iostream>

using namespace std;

void interschimbare1(int a, int b) {
	int aux = a;
	a = b;
	b = aux;
}

void interschimbare2(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void interschimbare3(int &a, int &b) {
	int aux = a;
	a = b;
	b = aux;
}


void main() {

	int x = 10;
	int y = 20;

	cout << x << " " << y << endl;

	interschimbare3(x, y);

	cout << x << " " << y << endl;
}