#include "PlayerStatus.h"



PlayerStatus::PlayerStatus()
{
	waiting = 0;
}

bool PlayerStatus::isWaiting() {
	if (waiting > 0) return 1;
	else return 0;
}
bool PlayerStatus::wait() {
	if (waiting > 0) {
		waiting--;
		return 1;
	}
	else return 0;
}

void PlayerStatus::setWaiting(int waiting) {
	this->waiting = waiting;
}
