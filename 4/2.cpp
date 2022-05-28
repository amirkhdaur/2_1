#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr{ 0, 1, 1, 2, 2, 3, 4 };
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < (arr.size() - i - 1); j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	int count = 1;
	int tmp = arr[0];
	bool flag = true;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] != tmp) {
			count++;
			flag = true;
		}
		else {
			if (flag) {
				flag = false;
				count--;
			}
		}
		tmp = arr[i];
	}
	cout << count;
}