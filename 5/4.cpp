#include <iostream>
#include <vector>
using namespace std;

class Card
{
public:
	enum rank {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	int GetValue() const;
	void Flip();
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};
Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}
int Card::GetValue() const
{
	int value = 0;
	if (m_IsFaceUp)
	{
		value = m_Rank;
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}
void Card::Flip()
{
	m_IsFaceUp = !(m_IsFaceUp);
}

class Hand
{
public:
	Hand();
	// ����������� ����������
	virtual ~Hand();
	// ��������� ����� � ����
	void Add(Card* pCard);
	// ������� ���� �� ����
	void Clear();
	//�������� ����� ����� ���� � ����, ���������� ����
	// �������� 1 ��� 11 � ����������� �� ��������
	int GetTotal() const;
protected:
	vector<Card*> m_Cards;
};
Hand::Hand()
{
	m_Cards.reserve(7);
}
// ���������� ��-�������� �����������
// ��� ��� ����� �� ����������
Hand::~Hand()
{
	Clear();
}
void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}
void Hand::Clear()
{
	// �������� �� �������, ���������� ��� ������ � ����
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}
	// ������� ������ ����������
	m_Cards.clear();
}
int Hand::GetTotal() const
{
	// ���� ���� � ���� ���, ���������� �������� 0
	if (m_Cards.empty())
	{
		return 0;
	}
	//���� ������ ����� ����� �������� 0, �� ��� ����� �������� �����:
	// ������� �������� 0
	if (m_Cards[0]->GetValue() == 0)
	{
		return 0;
	}
	// ������� ����� ����� ���� ����, ������ ��� ���� 1 ����
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += (*iter)->GetValue();
	}
	// ����������, ������ �� ���� ���
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}
	// ���� ���� ������ ��� � ����� �������� ���������, ��� ���� 11 �����
	if (containsAce && total <= 11)
	{
		// ��������� ������ 10 �����, ��������� �� ��� ��������
		// �� ������ ��� �� ������ ����
		total += 10;
	}
	return total;
}

class GenericPlayer : public Hand {
private:
	string name;

public:
	bool IsHitting() {
		if (GetTotal() <= 19) return true;
		return false;
	}
	bool IsBusted() {
		if (GetTotal() > 21) return true;
		return false;
	}
	bool Bust() {
		cout << name << ": " << "busted" << endl;
	}
};

int main() {

}