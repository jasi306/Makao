#pragma once
#include "Card.h"

#include <vector>
#include <time.h> /*time*/
#include <stdlib.h> /* srand, rand */
#include <cstdio>

using namespace std;
class Deck
{


private:
	
public:
	
	vector<Card> CARDS;
	//public:
	void add(Card);

	void add(Deck );
	void add_without_last(Deck );



	void randomize();
	Deck cards_sort();
	void print();
	Card top();
	Card adress(int);
	void erase_top();
	void Erase(int );
	void give_top(Deck &);
	void give(Deck &, int );
	void give_all(Deck &);
	int size();
	void clear();
	void clear_without_last();
	Card& operator[](const int i);
	const Card& operator[](const int i) const;
	friend ostream& operator<<(ostream&, const Deck&);
	
};