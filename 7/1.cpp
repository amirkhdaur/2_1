#include <iostream>
#include <memory>
using namespace std;

class Date {
public:
	Date(size_t _day = 0, size_t _month = 0, size_t _year = 0) : day(_day), month(_month), year(_year) {}
	void set_day(size_t _day);
	void set_month(size_t _month);
	void set_year(size_t _year);
	friend ostream& operator<<(ostream& c_out, Date& date);

private:
	size_t day, month, year;
};

void Date::set_day(size_t _day) {
	day = _day;
}

void Date::set_month(size_t _month) {
	month = _month;
}

void Date::set_year(size_t _year) {
	year = _year;
}

ostream& operator<<(ostream& c_out, Date& date) {
	c_out << (date.day < 10 ? "0" : "") << date.day << "/" << (date.month < 10 ? "0" : "") << date.month << "/" << date.year;
	return c_out;
}

int main() {
	auto today = make_unique<Date>();
	auto date = make_unique<Date>();

	today->set_day(6);
	today->set_month(6);
	today->set_year(2022);

	cout << *today << endl;

	date = move(today);

	if (today == nullptr) cout << "today: nullptr" << endl;
	else cout << "today: ptr" << endl;

	if (date == nullptr) cout << "date: nullptr" << endl;
	else cout << "date: ptr" << endl;
}