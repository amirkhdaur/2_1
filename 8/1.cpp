#include <iostream>
using namespace std;

template <typename A, typename B>
auto div(A a, B b) {
	if (b == 0) throw "DivisionByZero";
	return a / b;
}

int main() {
	try {
		cout << div<double, int>(5.5, 0) << endl;
	}
	catch (const char* ex) {
		cout << ex << endl;
	}
}