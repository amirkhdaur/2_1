#include <iostream>
#include <vector>
using namespace std;

enum Suit { SPADE, CLUB, HEART, DIAMOND };
enum Value { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10, ACE = 11 };

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

class Hand {
public:
	void Add(Card* card) {
		cards.push_back(card);
	}
	void Clear() {
		cards.clear();
	}
	int GetValue() {
		int value = 0;
		bool ace = false;
		for (int i = 0; i < cards.size(); i++) {
			if (cards[i]->GetValue() == ACE) ace = true;
			value += cards[i]->GetValue();
		}
		if (value > 21 && ace) value -= 10;
		return value;
	}

private:
	vector<Card*> cards;
};

int main() {
	Card c1(CLUB, NINE, false);
	Card c2(SPADE, TWO, false);
	Card c3(HEART, ACE, false);

	Hand hand;

	hand.Add(&c1);
	hand.Add(&c2);
	hand.Add(&c3);

	cout << "Value: " << hand.GetValue() << endl;
	cout << "Clear()" << endl;
	hand.Clear();
	cout << hand.GetValue();
}