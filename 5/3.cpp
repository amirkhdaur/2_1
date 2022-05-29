#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair {
private:
	T1 v1;
	T2 v2;

public:
	Pair(T1 _v1, T2 _v2) : v1(_v1), v2(_v2) {}

	T1 first() const { return v1; }
	T2 second() const { return v2; }
};

template <typename T>
class StringValuePair : public Pair<string, T> {
public:
	StringValuePair(string _first, T _second) : Pair<string, T>(_first, _second) {}
};

int main() {
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}

// Pair: Amazing 7