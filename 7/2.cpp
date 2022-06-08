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
	friend weak_ptr<Date> comparison(weak_ptr<Date>, weak_ptr<Date>);

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

weak_ptr<Date> comparison(weak_ptr<Date> date1, weak_ptr<Date> date2) {
	if (date1.lock()->year == date2.lock()->year) {
		if (date1.lock()->month == date2.lock()->month) {
			if (date1.lock()->day >= date2.lock()->day) return date1;
			else return date2;
		}
		else if (date1.lock()->month > date2.lock()->month) return date1;
		else return date2;
	}
	else if (date1.lock()->year > date2.lock()->year) return date1;
	else return date2;
}

void swap(weak_ptr<Date> date1, weak_ptr<Date> date2) {
	Date tmp = *date1.lock();
	*date1.lock() = *date2.lock();
	*date2.lock() = tmp;
}

int main() {
	shared_ptr<Date> date1 = make_shared<Date>();
	shared_ptr<Date> date2 = make_shared<Date>();

	date1->set_day(6);
	date1->set_month(6);
	date1->set_year(2022);

	date2->set_day(6);
	date2->set_month(7);
	date2->set_year(2022);

	cout << *comparison(date1, date2).lock() << endl;
	cout << "date1: " << *date1 << endl;
	cout << "date2: " << *date2 << endl;
	swap(date1, date2);
	cout << "date1: " << *date1 << endl;
	cout << "date2: " << *date2 << endl;
}