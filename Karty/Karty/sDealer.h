#pragma once
#include "Deck.h"
#include <map>
#define numer_of_deck 2

class sDealer
{
public:
	Deck drawCards;
	Deck usedCards;

	void check_if_drawable_if_needed_shuffle();
	
	void add_cards();
	void add_cards_without_last();
	
		/*static Singleton* get_instance(){
			if(instance == NULL)
				instance = new Singleton();

			return instance;
		}


	private:
		Singleton *instance = NULL;*/

	sDealer(map <int, char> mapedColor, map <int, char> mapedValue);



};

	

