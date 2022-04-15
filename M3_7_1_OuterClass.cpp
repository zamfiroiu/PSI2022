//#include<iostream>
//
//using namespace std;
//
//class OuterClass {
//public:
//	int aOuterClass;
//	class NestedClass {
//	public:
//		int aNestedClass;
//	};
//};
//
//class Laptop {
//public:
//	int RAM;
//
//	class Tasta {
//	public:
//		int latime;
//		char caracter;
//	};
//
//
//};
//
//
//class Outer {
//private:
//	int x;
//	class Nested {
//		int y;
//		void metodaNested(Outer e) {
//			cout << e.x;
//		}
//	};
//};
//
//
////class Outer {
////	int x;
////	class Nested {
////	private:
////		int y;
////	}; 
////	void EnclosingFun(Nested n) {
////		cout << n.y; 
////	}
////};
//
//
//void main() {
//	OuterClass::NestedClass n;
//	n.aNestedClass = 9;
//
//	Laptop::Tasta tasta;
//	tasta.caracter = 'A';
//	tasta.latime = 2;
//}