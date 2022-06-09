#include <iostream>
using namespace std;

enum Direction { LEFT = 1, UP, RIGHT, DOWN };

class Exception {
public:
	Exception(int _x, int _y, Direction _dir) : x(_x), y(_y), dir(_dir) {}
	void print_info() {
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << "direction: ";
		switch (dir) {
		case LEFT:
			cout << "left";
			break;
		case UP:
			cout << "up";
			break;
		case RIGHT:
			cout << "right";
			break;
		case DOWN:
			cout << "down";
			break;
		}
		cout << endl;
	}
	virtual const char* what() = 0;

private:
	int x, y;
	Direction dir;
};

class OffTheField : public Exception {
public:
	OffTheField(int _x, int _y, Direction _dir) : Exception(_x, _y, _dir) {}
	virtual const char* what() {
		return "OffTheField";
	}
};

class IllegalCommand : public Exception {
public:
	IllegalCommand(int _x, int _y, Direction _dir) : Exception(_x, _y, _dir) {}
	virtual const char* what() {
		return "IllegalCommand";
	}
};

class Robot {
public:
	void move() {
		switch (dir) {
		case LEFT:
			if (x == 1) throw OffTheField(x, y, dir);
			else x--;
			break;

		case UP:
			if (y == 1) throw OffTheField(x, y, dir);
			else y--;
			break;

		case RIGHT:
			if (x == 10) throw OffTheField(x, y, dir);
			else x++;
			break;

		case DOWN:
			if (y == 10) throw OffTheField(x, y, dir);
			else y++;
			break;
		}
	}
	void change_direction(Direction _dir) {
		if (_dir < 1 || _dir > 4) throw IllegalCommand(x, y, dir);
		else dir = _dir;
	}
	void print() {
		for (int i = 0; i < 30; i++) cout << endl;

		for (int j = 1; j <= 10; j++) {
			for (int i = 1; i <= 10; i++) {
				char ch = '.';
				if (i == x && j == y) ch = '#';
				cout << ch << " ";
			}
			cout << endl;
		}
	}

private:
	int x = 5, y = 5;
	Direction dir = DOWN;
};

int main() {
	Robot robot;
	while (true) {
		robot.print();
		cout << "1 - Move" << endl;
		cout << "2 - Change Direction" << endl;
		cout << "3 - Exit" << endl;
		cout << ">> ";
		int opt;
		cin >> opt;
		if (!(opt == 1 || opt == 2 || opt == 3)) {
			cout << "Invalid option";
			continue;
		}
		try {
			switch (opt) {
			case 1:
				robot.move();
				break;
			case 2:
				cout << endl;
				cout << "1 - Left" << endl;
				cout << "2 - Up" << endl;
				cout << "3 - Right" << endl;
				cout << "4 - Down" << endl;
				cout << ">> ";
				int n;
				cin >> n;
				robot.change_direction(Direction(n));
				break;
			case 3:
				return 0;
			}
		}
		catch (Exception& ex) {
			cout << ex.what() << endl;
			ex.print_info();
			system("pause");
		}
	}
}