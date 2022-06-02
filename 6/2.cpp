#include <iostream>
using namespace std;

class Endll {
public:
	friend ostream& operator<< (ostream& c_out, Endll& endll) {
		c_out << endl << endl;
		c_out.clear();
		return c_out;
	}
};

int main() {
	Endll endll;
	cout << "Hello" << endll << "World";
}