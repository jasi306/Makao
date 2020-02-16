#pragma once
#include "Interactions.h";
#include "Rules.h";
#include "PlayerStatus.h";
class Game
{
public:
	sDealer *d;
	Rules *r;
	bool icons = true;

	Game(Rules *r);
	~Game();


	void CreateCardsNames(map <int, char>, map <int, char>);
};