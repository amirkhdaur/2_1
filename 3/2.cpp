#include <iostream>
using namespace std;

class Car {
public:
	Car(string _company, string _model) : company(_company), model(_model) {
		cout << "Car:" << endl;
		cout << "\tCompany: " << company << endl;
		cout << "\tModel: " << model << endl << endl;
	}
protected:
	string company, model;
};

class PassengerCar : virtual public Car {
public:
	PassengerCar(string _company, string _model) : Car(_company, _model) {
		cout << "PassengerCar:" << endl;
		cout << "\tCompany: " << company << endl;
		cout << "\tModel: " << model << endl << endl;
	}
};

class Bus : virtual public Car {
public:
	Bus(string _company, string _model) : Car(_company, _model) {
		cout << "Bus:" << endl;
		cout << "\tCompany: " << company << endl;
		cout << "\tModel: " << model << endl << endl;
	}
};

class Minivan : public Bus, public PassengerCar {
public:
	Minivan(string _company, string _model) : Bus(_company, _model), PassengerCar(_company, _model), Car(_company, _model) {
		cout << "Minivan:" << endl;
		cout << "\tCompany: " << company << endl;
		cout << "\tModel: " << model << endl << endl;
	}
};

int main() {
	Minivan mv("CoMpAnY", "MoDeL");
}