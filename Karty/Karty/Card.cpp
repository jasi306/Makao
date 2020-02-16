#include "Card.h"

Card::Card(int value, int color, char mapedValue,char mapedColor) {
	this->value = value;
	this->color = color;
	this->mValue = mapedValue;
	this->mColor = mapedColor;
	
}


Card::~Card()
{
}

int Card::getValue() {
	return value;
};
int Card::getColor() {
	return color;
};


istream& operator>>(istream& in, Card& card)
{
	return in >> card.value >> card.color;
}

ostream& operator<<(ostream& out, const Card& card)
{
	return out << card.mValue << card.mColor;
}


bool Card::operator>(const Card& c) {
	if (value > c.value) return 1;
	if (value == c.value && color > c.color) return 1;
	return 0;
}
bool Card::operator<(const Card& c) {
	if (value < c.value) return 1;
	if (value == c.value && color < c.color) return 1;
	return 0;
}

bool Card::operator==(const Card& c) {
	return value == c.value && color == c.color;
}

bool Card::operator>=(const Card& c) {
	if (value > c.value) return 1;
	if (value == c.value && color >= c.color) return 1;
	return 0;
}

bool Card::operator<=(const Card& c) {
	if (value < c.value) return 1;
	if (value == c.value && color <= c.color) return 1;
	return 0;
}

bool Card::sameColor(const Card& c) {
	return color == c.color;
}
bool Card::sameValue(const Card& c) {
	return value == c.value;
}
bool Card::sameColorOrValue(const Card& c) {
	return sameColor(c) || sameValue(c);
}