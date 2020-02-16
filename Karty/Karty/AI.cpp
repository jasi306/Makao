#include "AI.h"




BaseAIBuild::BaseAIBuild(sDealer* dealer,Rules* r) {
	this->dealer = dealer; //znaj swojego dilera
	this->r = r;
}

bool BaseAIBuild::is_win() {
	if (deck.size() == 0) {
		return true;
	}
	else return false;

}
void BaseAIBuild::play(Deck cards) {

	for (int i = 0; i < cards.size(); ++i) {
		for (int i = 0; i < deck.size(); ++i) {
			if (deck.adress(i).color == cards.top().color  && deck.adress(i).value == cards.top().value) {
				deck.Erase(i);
			}
		}
		cards.give_top(dealer->usedCards);
	}
}
void BaseAIBuild::draw() {
	dealer->check_if_drawable_if_needed_shuffle();
	dealer->drawCards.give_top(deck);
}

Deck BaseAIBuild::check() {
	Deck matching;
	for (int i = 0; i < deck.size(); ++i) {
		if (dealer->usedCards.top().value == deck.CARDS[i].value ||
			dealer->usedCards.top().color == deck.CARDS[i].color) {
			matching.add(deck.CARDS[i]);
		}
	}
	return matching;
}

vector<Deck> BaseAIBuild::find_more() {
	Deck temp = check();
	vector<Deck> decks;
	for (int i = 0; i < temp.size(); ++i) {
		Deck a;
		decks.push_back(a);
		for (int ii = 0; ii < deck.size(); ++ii) {
			if (deck.CARDS[ii].value == temp.CARDS[i].value) {
				decks.back().add(deck.CARDS[ii]);
			}
		}
	}
	return decks;
}


Deck BaseAIBuild::find_min_size_cards_set(vector<Deck> temp) {
	int Min = 100, position = -1;
	for (int i = 0; i < temp.size(); ++i) {
		if (temp[i].CARDS.size() < Min) {
			Min = temp[i].CARDS.size();
			position = i;
		}
	}
	return temp[position];
}

Deck BaseAIBuild::find_max_size_cards_set(vector<Deck> temp) {
	int Max = 0, position = -1;
	for (int i = 0; i < temp.size(); ++i) {
		if (temp[i].CARDS.size() + 1 > Max) {
			Max = temp[i].CARDS.size() + 1;
			position = i;
		}
	}
	return temp[position];
}