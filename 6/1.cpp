#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string str;
	int num;
	bool isNum = false;
	while (!isNum) {
		cout << "Enter a number: ";
		getline(cin, str);
		for (int i = 0; i < str.length(); i++) {
			if (!isdigit(str.at(i))) {
				cerr << "it's not a number" << endl << endl;
				isNum = false;
				break;
			}
			else
				isNum = true;
		}
	}
	stringstream qwe;
	qwe << str;
	qwe >> num;

	cout << num;
}