#include <iostream>
using namespace std;

class Fruit {
public:
	Fruit(string _color, string _name) : color(_color), name(_name) {}
	string getName() { return name; }
	string getColor() { return color; }
private:
	string name;
	string color;
};

class Apple : public Fruit {
public:
	Apple(string _color = "red", string _name = "apple") : Fruit(_color, _name) {}
};

class Banana : public Fruit {
public:
	Banana(string _color = "yellow", string _name = "banana") : Fruit(_color, _name) {}
};

class GrannySmith : public Apple {
public:
	GrannySmith(string _color = "green", string _name = "Granny Smith apple") : Apple(_color, _name) {}
};

int main() {
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}