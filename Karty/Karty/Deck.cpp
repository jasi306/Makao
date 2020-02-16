#include "Deck.h"

#include <algorithm>

Card& Deck::operator[](const int i)
{
	return CARDS[i];
}

const Card& Deck::operator[](const int i) const
{
	return CARDS[i];
}


ostream& operator<<(ostream& out, const Deck& deck)
{
	int size = deck.CARDS.size();
	for (int i = 0; i < size; ++i) {
		out << deck.CARDS[i] << " ";
	}
	return out;
}


void Deck::add(Card card) {
	CARDS.push_back(card);
}


void Deck::add(Deck IDeck) {
	for (int i = 0; i < IDeck.CARDS.size(); ++i)
		add(IDeck.CARDS[i]);
}
void Deck::add_without_last(Deck IDeck) {
	for (int i = 0; i < IDeck.CARDS.size() - 1; ++i)
		add(IDeck.CARDS[i]);
}

void Deck::randomize() {
	vector<Card> New;
	int Random;
	for (int i = 0; CARDS.size() > 0; ++i) {
		Random = rand() % (CARDS.size());
		New.push_back(CARDS[Random]);
		CARDS.erase(CARDS.begin() + Random);
	}
	CARDS = New;
}

Deck Deck::cards_sort() {
	sort(CARDS.begin(),CARDS.end());
	return *this;
	/*Deck New;
	vector<Card> Temp = CARDS;

	for (int i = 0; Temp.size(); ++i) { 
		int localmin_position = 0;
		Card localmin = Temp[0];
		for (unsigned int ii = 1; ii < Temp.size(); ++ii) {
			if (Temp[localmin_position].value < Temp[ii].value) {
				localmin_position = ii;
	
			}
			else if (Temp[localmin_position].value == Temp[ii].value) {
				if (Temp[localmin_position].color < Temp[ii].color) {
					localmin_position = ii;
				}
			}

		}
		New.CARDS.push_back(Temp[localmin_position]);
		Temp.erase(Temp.begin() + localmin_position);
	}
	return New;*/
}





void Deck::print() {
	for (int i = 0; i < CARDS.size(); ++i) {
		cout << CARDS[i] << " ";
	}
	cout<<endl<<" s="<<CARDS.size()<<endl;
}

Card Deck::top() {
	return CARDS.back();
}


void Deck::erase_top() {
	CARDS.pop_back();
}


void Deck::Erase(int possition) {
	CARDS.erase(CARDS.begin() + possition);
}

void Deck::give_top(Deck &addressee) {
	addressee.add(top());
	erase_top();
}

void Deck::give(Deck &addressee, int possition) {
	addressee.add(adress(possition));
	Erase(possition);
}

void Deck::give_all(Deck &addressee) {
	while (!CARDS.empty()) {
		give_top(addressee);
	}
}

int Deck::size() {
	return CARDS.size();
}

void Deck::clear() {
	CARDS.clear();
}


void Deck::clear_without_last() {
	while (size() > 1) {
		Erase(0);
	}
}