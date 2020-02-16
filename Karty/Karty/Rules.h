#pragma once
#include "Deck.h"

#include "PlayerStatus.h"

using namespace std;

//typedef bool* func(void);
class Rules
{
private:
	sDealer* d;
	int numberOfDecks;
	const int numberOfValues = 13;
	const int numberOfColors = 4;

	int numberOfPlayers;
	
	

public:
	/*bool (Rules::*ifMoveAllowed)(Deck, Deck);
	Rules(int playersCount, string GameName, int numberOfDecks);
	*/
	Rules(sDealer*, int Decks);
	~Rules();
	bool ifCardIsGood(Card);
	bool ifAnyCardIsGood(Deck);
};

