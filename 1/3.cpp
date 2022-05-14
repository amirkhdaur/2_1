#include <iostream>
using namespace std;

class Stack {
public:
	void reset() {
		size = 0;
		for (int i = 0; i < 10; i++) {
			stack[i] = 0;
		}
	}
	void print() {
		cout << "( ";
		for (int i = 0; i < size; i++) {
			cout << stack[i] << " ";
		}
		cout << ")" << endl;
	}
	bool push(int val) {
		if (size == 10) {
			return false;
		}
		stack[size] = val;
		size++;
		return true;
	}
	void pop() {
		if (size == 0) {
			cout << "Stack empty" << endl;
			return;
		}
		stack[--size] = 0;
	}
private:
	int stack[10];
	size_t size;
};

int main() {
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}