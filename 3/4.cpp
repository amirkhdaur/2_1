#include <iostream>
using namespace std;

enum Suit { SPADE, CLUB, HEART, DIAMOND };
enum Value { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card {
public:
	Card(Suit _suit, Value _value, bool _pos) : suit(_suit), value(_value), pos(_pos) {}
	void Flip() { pos = pos ? false : true; }
	Value GetValue() { return value; }
private:
	Suit suit;
	Value value;
	bool pos;
};

int main() {
	Card card(CLUB, NINE, false);
	cout << card.GetValue();
}