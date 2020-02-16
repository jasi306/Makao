#pragma once
#include "Interactions.h"



class BaseAIBuild {
public:
	BaseAIBuild(sDealer*, Rules*);
	~BaseAIBuild();

	Deck deck;
	sDealer* dealer;
	Rules* r;
	bool is_win();
	void play(Deck cards);
	void draw();
	Deck check();
	vector<Deck> find_more();
	Deck find_max_size_cards_set(vector<Deck> temp);
	Deck find_min_size_cards_set(vector<Deck> temp);
};
//---------------------------------------

class AIstandard : public BaseAIBuild {
public:

	void make_move() {
		vector<Deck> temp = find_more();
		if (temp.size() == 0) {
			draw();
		}
		else {
			UseYourStrategy(temp);
		}
	}


	void UseYourStrategy(vector<Deck> &temp) {
		play(find_max_size_cards_set(temp));
	}
};


//----------------------------------------------------------------------------------------------------------


class AIjanek : public BaseAIBuild {
public:

	void make_move() {
		vector<Deck> temp = find_more();

		if (temp.size() == 0) {
			draw();
		}
		else {
			UseYourStrategy(temp);
		}
	}

	void UseYourStrategy(vector<Deck> &temp) {
		play(find_min_size_cards_set(temp));
	}
};