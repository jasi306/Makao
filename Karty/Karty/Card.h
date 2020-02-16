#pragma once
#include <iostream>

using namespace std;
class Card
{
public:

	
	int mColor;
	int mValue;
	char color;
	char value;

	~Card();

	Card(int,int,char,char);
	int getValue();
	int getColor();

	bool operator>(const Card& c);
	bool operator<(const Card& c);
	bool operator>=(const Card& c);
	bool operator<=(const Card& c);
	bool operator==(const Card& c);

	friend ostream& operator<<(ostream&, const Card&);
	friend istream& operator>>(istream&, Card&);

	bool sameColor(const Card& c);
	bool sameValue(const Card& c);
	bool sameColorOrValue(const Card& c);
};







