#include <iostream>
#include <cstdint>
using namespace std;

class RGBA {
public:
	RGBA(uint8_t _m_red, uint8_t _m_green = 0, uint8_t _m_blue = 0, uint8_t _m_alpha = 255) {
		m_red = _m_red, m_green = _m_green, m_blue = _m_blue, m_alpha = _m_alpha;
	}
	void print() {
		cout << "R: " << int(m_red) << endl;
		cout << "G: " << int(m_green) << endl;
		cout << "B: " << int(m_blue) << endl;
		cout << "A: " << int(m_alpha);
	}

private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
};


int main() {
	RGBA color(12, 54, 123, 63);
	color.print();
}