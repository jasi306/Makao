#include "sDealer.h"



void sDealer::check_if_drawable_if_needed_shuffle() {
	if (drawCards.size() < 2) {

		Deck temp = usedCards;
		usedCards.clear();
		temp.give_top(usedCards);
		temp.give_all(drawCards);
		drawCards.randomize();
	}
}

void sDealer::add_cards() {
	drawCards.add(usedCards);
	//UsedCards.give_all(cards);
	drawCards.randomize();
	usedCards.clear();
}
void sDealer::add_cards_without_last() {
	drawCards.add_without_last(usedCards);
	drawCards.randomize();
	usedCards.clear_without_last();
}

/*static Singleton* get_instance(){
	if(instance == NULL)
		instance = new Singleton();

	return instance;
}


private:
	Singleton *instance = NULL;*/

sDealer::sDealer(map <int, char> mapedColor, map <int, char> mapedValue) {

	for (int ii = 0; ii < numer_of_deck; ++ii) {
		for (int i = 0; i < 13; ++i) {
			for (int ii = 0; ii < 4; ++ii) {
				drawCards.add(Card(i, ii, mapedColor[i], mapedColor[ii]));
			}
		}
	}
	drawCards.randomize();
}

