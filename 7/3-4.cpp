#include <iostream>
#include <vector>
#include <random>
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
	virtual bool IsHitting() const {
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

class Deck : public Hand {
public:
	Deck() {
		m_Cards.reserve(52);
		Populate();
	}
	void Populate() {
		Clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 13; i++) {
				Add(new Card(Card::rank(j), Card::suit(i), false));
			}
		}
	}
	void Shuffle() {
		random_shuffle(m_Cards.begin(), m_Cards.end());
	}
	void Deal(Hand& aHand) {
		if (!m_Cards.empty()) {
			aHand.Add(m_Cards.back());
			m_Cards.pop_back();
		}
		else {
			cout << "Out of cards. Unable to deal.";
		}
	}
	void AdditionalCards(GenericPlayer& aGenericPlayer) {
		cout << endl;
		while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting()) {
			Deal(aGenericPlayer);
			cout << aGenericPlayer << endl;
			if (aGenericPlayer.IsBusted()) {
				aGenericPlayer.Bust();
			}
		}
	}
};

class Game {
public:
	Game(const vector<string>& names) {
		cout << 0;
		vector<string>::const_iterator pName;
		cout << "1";
		for (pName = names.begin(); pName != names.end(); pName++) {
			m_Players.push_back(Player(*pName));
		}
		cout << "2";
		srand(static_cast<unsigned int>(time(0)));
		cout << "3";
		m_Deck.Populate();
		cout << "4";
		m_Deck.Shuffle();
		cout << "5";
	}
	Game(vector<string>& names) { cout << "zxc" << endl; }
	~Game() {}
	void Play() {
		vector<Player>::iterator pPlayer;
		for (int i = 0; i < 2; i++) {
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
				m_Deck.Deal(*pPlayer);
			}
			m_Deck.Deal(m_House);
		}
		m_House.FlipFirstCard();
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
			cout << *pPlayer << endl;
		}
		cout << m_House << endl;
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
			m_Deck.AdditionalCards(*pPlayer);
		}
		m_House.FlipFirstCard();
		cout << endl << m_House;
		m_Deck.AdditionalCards(m_House);
		if (m_House.IsBusted()) {
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
				if (!(pPlayer->IsBusted())) {
					pPlayer->Win();
				}
			}
		}
		else {
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
				if (!(pPlayer->IsBusted())) {
					if (pPlayer->GetTotal() > m_House.GetTotal()) {
						pPlayer->Win();
					}
					else if (pPlayer->GetTotal() < m_House.GetTotal()) {
						pPlayer->Lose();
					}
					else {
						pPlayer->Push();
					}
				}
			}
		}
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
			pPlayer->Clear();
		}
		m_House.Clear();
	}

private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};

int main() {

}