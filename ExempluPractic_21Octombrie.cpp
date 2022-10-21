#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>

using namespace std;

//i: float float
//o: bool

bool functieComparare(float a, float b) {
	return a > b;
}

void main() {
	//string sir = "un sir de caractere";
	//cout<<sir.at(0)<<endl;
	//cout << sir[1] << endl;
	vector<float> preturi;

	preturi.push_back(6.7);
	preturi.push_back(8.3);
	preturi.push_back(1.5);
	preturi.push_back(7.4);

	sort(preturi.begin(), preturi.end(),functieComparare);

	for (int i = 0; i < preturi.size(); i++) {
		cout << preturi[i] << ", ";
	}

	
}