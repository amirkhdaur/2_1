#include <iostream>
using namespace std;

class Ex : exception {
public:
	Ex(double _x) : x(_x) {}
	double get() { return x; }

private:
	double x;
};

class Bar {
public:
	Bar() : y(0) {}
	void set(double a) {
		if (y + a > 100) throw Ex(a * y);
		else y = a;
	}

private:
	double y;
};

int main() {
	Bar bar;

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		try {
			bar.set(n);
		}
		catch (Ex& ex) {
			cout << "Exception: " << ex.get() << endl;
		}
	}
}