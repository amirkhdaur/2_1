#include <iostream>
#include <vector>
using namespace std;

class Card {
public:
	enum rank {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}
	int GetValue() const {
		int value = 0;
		if (m_IsFaceUp) {
			value = m_Rank;
			if (value > 10) {
				value = 10;
			}
		}
		return value;
	}
	void Flip() {
		m_IsFaceUp = !(m_IsFaceUp);
	}
	friend ostream& operator<<(ostream& os, const Card& aCard) {
		const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
		const string SUITS[] = { "c", "d", "h", "s" };
		if (aCard.m_IsFaceUp) {
			os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
		}
		else {
			os << "XX";
		}
		return os;
	}

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};


class Hand {
public:
	Hand() {
		m_Cards.reserve(7);
	}
	virtual ~Hand() {
		Clear();
	}
	void Add(Card* pCard) {
		m_Cards.push_back(pCard);
	}
	void Clear() {
		vector<Card*>::iterator iter = m_Cards.begin();
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
			delete* iter;
			*iter = 0;
		}
		m_Cards.clear();
	}
	int GetTotal() const {
		if (m_Cards.empty()) {
			return 0;
		}
		if (m_Cards[0]->GetValue() == 0) {
			return 0;
		}
		int total = 0;
		vector<Card*>::const_iterator iter;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
			total += (*iter)->GetValue();
		}
		bool containsAce = false;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
			if ((*iter)->GetValue() == Card::ACE) {
				containsAce = true;
			}
		}
		if (containsAce && total <= 11) {
			total += 10;
		}
		return total;
	}
protected:
	vector<Card*> m_Cards;
};

class GenericPlayer : public Hand {
public:
	GenericPlayer(const string& name = "") : m_Name(name) {}
	virtual ~GenericPlayer() {}
	virtual bool IsHitting() const = 0;
	bool IsBusted() const {
		return (GetTotal() > 21);
	}
	void Bust() const {
		cout << m_Name << " busts." << endl;
	}
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer) {
		os << aGenericPlayer.m_Name << ":\t";
		vector<Card*>::const_iterator pCard;
		if (!aGenericPlayer.m_Cards.empty()) {
			for (pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); ++pCard) {
				os << *(*pCard) << "\t";
			}
			if (aGenericPlayer.GetTotal() != 0) {
				os << "(" << aGenericPlayer.GetTotal() << ")";
			}
		}
		else {
			os << "<empty>";
		}
		return os;
	}

protected:
	string m_Name;
};

class Player : public GenericPlayer {
public:
	Player(const string& name = "") {}
	virtual ~Player() {}
	virtual bool IsHitting() const {
		cout << m_Name << ", do you want a hit? (Y/N): ";
		char response;
		cin >> response;
		return (response == 'y' || response == 'Y');
	}
	void Win() const {
		cout << m_Name << " wins." << endl;
	}
	void Lose() const {
		cout << m_Name << " loses." << endl;
	}
	void Push() const {
		cout << m_Name << " pushes." << endl;
	}
};

class House : public GenericPlayer {
public:
	House(const string& name = "House") {}
	virtual ~House() {}
	virtual bool IsHitting() {
		return (GetTotal() <= 16);
	}
	void FlipFirstCard() {
		if (!(m_Cards.empty())) {
			m_Cards[0]->Flip();
		}
		else {
			cout << "No card to flip!" << endl;
		}
	}
};

int main() {

}