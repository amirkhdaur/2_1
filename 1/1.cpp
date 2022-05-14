#include <iostream>
using namespace std;

class Power {
public:
	Power() { a = 0, b = 0; }
	void set_nums(int _a, int _b) { a = _a; b = _b; }
	void calculate() { cout << pow(a, b); }
private:
	int a, b;
};

int main() {
	Power P;
	P.set_nums(5, 3);
	P.calculate();
}