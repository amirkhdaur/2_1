#include <iostream>
using namespace std;

template<class T>
class Pair1 {
private:
	T v1, v2;

public:
	Pair1(T _v1, T _v2) : v1(_v1), v2(_v2) {}

	T first() const { return v1; }
	T second() const { return v2; }
};

int main() {
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}

/*
Pair: 6 9
Pair: 3.4 7.8
*/