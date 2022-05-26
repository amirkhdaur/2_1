#include <iostream>
using namespace std;

class Fraction {
public:
	Fraction(int _numerator, int _denominator) {
		if (_denominator == 0) {
			cout << "denominator cannot be zero" << endl;
		}
		else {
			numerator = _numerator;
			denominator = _denominator;
		}
	}
	// Вывод
	friend ostream& operator<<(ostream& c_out, const Fraction& f) {
		c_out << f.numerator << "/" << f.denominator;
		return c_out;
	};

	// Оператор +
	friend Fraction operator+(const Fraction& f1, const Fraction& f2) {
		int _numerator, _denominator;
		if (f1.denominator != f2.denominator) {
			_numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
			_denominator = f1.denominator * f2.denominator;
		}
		else {
			_numerator = f1.numerator + f2.numerator;
			_denominator = f1.denominator;
		}
		return Fraction(_numerator, _denominator);
	}
	friend Fraction operator+(const Fraction& f, int n) {
		return Fraction(f.numerator + n * f.denominator, f.denominator);
	}
	friend Fraction operator+(int n, const Fraction& f) {
		return Fraction(n * f.denominator + f.numerator, f.denominator);
	}

	// Оператор -
	friend Fraction operator-(const Fraction& f1, Fraction& f2) {
		int _numerator, _denominator;
		if (f1.denominator != f2.denominator) {
			_numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
			_denominator = f1.denominator * f2.denominator;
		}
		else {
			_numerator = f1.numerator - f2.numerator;
			_denominator = f1.denominator;
		}
		return Fraction(_numerator, _denominator);
	}
	friend Fraction operator-(const Fraction& f, int n) {
		return Fraction(f.numerator - n * f.denominator, f.denominator);
	}
	friend Fraction operator-(int n, const Fraction& f) {
		return Fraction(n * f.denominator - f.numerator, f.denominator);
	}

	// Оператор *
	friend Fraction operator*(const Fraction& f1, const Fraction& f2) {
		return Fraction(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
	}
	friend Fraction operator*(const Fraction& f, int n) {
		return Fraction(f.numerator * n, f.denominator);
	}
	friend Fraction operator*(int n, const Fraction& f) {
		return Fraction(n * f.numerator, f.denominator);
	}

	// Оператор /
	friend Fraction operator/(const Fraction& f1, const Fraction& f2) {
		return Fraction(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
	}
	friend Fraction operator/(const Fraction& f, int n) {
		return Fraction(f.numerator, f.denominator * n);
	}
	friend Fraction operator/(int n, const Fraction& f) {
		return Fraction(n * f.denominator, f.numerator);
	}

	// Унарный оператор -
	Fraction operator-() const {
		return Fraction(-numerator, denominator);
	}

	// Оператор ==
	friend bool operator==(const Fraction& f1, const Fraction& f2) {
		return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
	}
	friend bool operator==(const Fraction& f, int n) {
		return f.numerator == n * f.denominator;
	}
	friend bool operator==(int n, const Fraction& f) {
		return f.numerator == n * f.denominator;
	}

	// Оператор !=
	friend bool operator!=(const Fraction& f1, const Fraction& f2) {
		return f1.numerator != f2.numerator || f1.denominator != f2.denominator;
	}
	friend bool operator!=(const Fraction& f, int n) {
		return f.numerator != n * f.denominator;
	}
	friend bool operator!=(int n, const Fraction& f) {
		return f.numerator != n * f.denominator;
	}

	// Оператор <
	friend bool operator<(const Fraction& f1, const Fraction& f2) {
		return f1.numerator * f2.denominator < f2.numerator* f1.denominator;
	}
	friend bool operator<(const Fraction& f, int n) {
		return f.numerator < n* f.denominator;
	}
	friend bool operator<(int n, const Fraction& f) {
		return n * f.denominator < f.numerator;
	}

	// Оператор >
	friend bool operator>(const Fraction& f1, const Fraction& f2) {
		return f1.numerator * f2.denominator > f2.numerator * f1.denominator;
	}
	friend bool operator>(const Fraction& f, int n) {
		return f.numerator > n * f.denominator;
	}
	friend bool operator>(int n, const Fraction& f) {
		return n * f.denominator > f.numerator;
	}

	// Оператор <=
	friend bool operator<=(const Fraction& f1, const Fraction& f2) {
		return f1.numerator * f2.denominator <= f2.numerator * f1.denominator;
	}
	friend bool operator<=(const Fraction& f, int n) {
		return f.numerator <= n * f.denominator;
	}
	friend bool operator<=(int n, const Fraction& f) {
		return n * f.denominator <= f.numerator;
	}

	// Оператор >=
	friend bool operator>=(const Fraction& f1, const Fraction& f2) {
		return f1.numerator * f2.denominator >= f2.numerator * f1.denominator;
	}
	friend bool operator>=(const Fraction& f, int n) {
		return f.numerator >= n * f.denominator;
	}
	friend bool operator>=(int n, const Fraction& f) {
		return n * f.denominator >= f.numerator;
	}

private:
	int numerator = 0;
	int denominator = 1;
};

int main() {
	Fraction f1(3, 7), f2(9, 2);
	cout << "f1 = " << f1 << endl;
	cout << "f2 = " << f2 << endl;
	cout << "f1 + f2 = " << f1 + f2 << endl;
	cout << "f1 - f2 = " << f1 - f2 << endl;
	cout << "f1 * f2 = " << f1 * f2 << endl;
	cout << "f1 / f2 = " << f1 / f2 << endl;
	cout << "-f1 = " << -f1 << endl;
	cout << "-f2 = " << -f2 << endl;
	cout << "f1 == f2 : " << (f1 == f2 ? "true" : "false") << endl;
	cout << "f1 != f2 : " << (f1 != f2 ? "true" : "false") << endl;
	cout << "f1 < f2 : " << (f1 < f2 ? "true" : "false") << endl;
	cout << "f1 > f2 : " << (f1 > f2 ? "true" : "false") << endl;
	cout << "f1 <= f2 : " << (f1 <= f2 ? "true" : "false") << endl;
	cout << "f1 >= f2 : " << (f1 >= f2 ? "true" : "false") << endl;
}