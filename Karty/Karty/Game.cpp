#include "Game.h"


Game::Game(Rules* r)
{
	this->r = r;
	map <int, char> mValue;
	map <int, char> mColor;
	CreateCardsNames(mValue, mColor);
	d = new sDealer(mValue, mColor);

}


Game::~Game()
{

}





void Game::CreateCardsNames(map <int, char> mValue, map <int, char> mColor) {
	mValue[0] = '2';
	mValue[1] = '3';
	mValue[2] = '4';
	mValue[3] = '5';
	mValue[4] = '6';
	mValue[5] = '7';
	mValue[6] = '8';
	mValue[7] = '9';
	mValue[8] = '0';
	mValue[9] = 'J';
	mValue[10] = 'Q';
	mValue[11] = 'K';
	mValue[12] = 'A';
	//mValue[13]='Jocker';

	if (!icons) {
		mColor[0] = 'H';
		mColor[1] = 'T';
		mColor[2] = 'C';
		mColor[3] = 'P';
	}
	else {
		mColor[0] = 3;
		mColor[1] = 4;
		mColor[2] = 5;
		mColor[3] = 6;
	}
}