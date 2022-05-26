#include <iostream>
using namespace std;

class Figure {
public:
	virtual double area() = 0;
};

class Parallelogram : public Figure {
public:
	Parallelogram(double _a = 0, double _h = 0) : a(_a), h(_h) {}
	double area() override {
		return a * h;
	}
private:
	double a, h;
};

class Circle : public Figure {
public:
	Circle(double _radius) : radius(_radius) {}
	double area() override {
		return pi * radius * radius;
	}
private:
	double radius;
	double pi = 3.141592653589793;
};

class Rectangle : public Parallelogram {
public:
	Rectangle(double _a, double _b) : a(_a), b(_b) {}
	double area() override {
		return a * b;
	}
private:
	double a, b;
};

class Square : public Parallelogram {
public:
	Square(double _a) : a(_a) {}
	double area() override {
		return a * a;
	}
private:
	double a;
};

class Rhombus : public Parallelogram {
public:
	Rhombus(double _d1, double _d2) : d1(_d1), d2(_d2) {}
	double area() override {
		return d1 * d2 * 0.5;
	}
private:
	double d1, d2;
};

int main() {

}