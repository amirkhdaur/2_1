#include <iostream>
using namespace std;

class Person {
public:
	void set_name(string _name) { name = _name; }
	void set_age(size_t _age) { age = _age; }
	void set_sex(char _sex) { sex = _sex; }
	void set_weight(size_t _weight) { weight = _weight; }
	string get_name() { return name; }
	size_t get_age() { return age; }
	char get_sex() { return sex; }
	size_t get_weight() { return weight; }
	void print_info() {
		cout << "Name: " << get_name() << endl;
		cout << "Age: " << get_age() << endl;
		cout << "Sex: " << get_sex() << endl;
		cout << "Weight: " << get_weight() << endl;
	}
private:
	string name = "Name";
	size_t age = 0;
	char sex;
	size_t weight;
};

class Student : public Person {
public:
	Student() {
		year = 1;
		count++;
	}
	void set_year(size_t _year) { year = _year; }
	size_t get_year() { return year; }
	size_t get_count() { return count; }
	void print_info() {
		Person::print_info();
		cout << "Year: " << year << endl;
	}

private:
	size_t year;
	static size_t count;
};
size_t Student::count = 0;

int main() {
	Student s1, s2;
	s1.set_name("Dmitry");
	s1.set_age(20);
	s1.set_sex('M');
	s1.set_weight(70);
	s1.set_year(3);
	s1.print_info();
	cout << "Count: " << s1.get_count() << endl << endl;

	s2.set_name("Alexander");
	s2.set_age(18);
	s2.set_sex('M');
	s2.set_weight(64);
	s2.set_year(1);
	s2.print_info();
	cout << "Count: " << s2.get_count() << endl << endl;

	Student s3;
	s3.set_name("Eugeniya");
	s3.set_age(21);
	s3.set_sex('F');
	s3.set_weight(50);
	s3.set_year(4);
	s3.print_info();
	cout << "Count: " << s3.get_count();
}