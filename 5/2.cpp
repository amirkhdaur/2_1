#include <iostream>
using namespace std;

template <class T1, class T2>
class Pair {
private:
	T1 v1;
	T2 v2;

public:
	Pair(T1 _v1, T2 _v2) : v1(_v1), v2(_v2) {}

	T1 first() const { return v1; }
	T2 second() const { return v2; }
};

int main()
{
	Pair<int, double> p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}

/*
Pair: 6 7.8
Pair: 3.4 5
*/