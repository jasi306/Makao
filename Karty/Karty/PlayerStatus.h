#pragma once
#include "sDealer.h"
class PlayerStatus
{
private:
	int waiting;
public:
	PlayerStatus();
	
	bool isWaiting();  //cheack if player needs to wait;
	bool wait();       //waiting-- , returning bool to unlock if(wait()){} structure
	void setWaiting(int); 

	bool CardDealt;
	Card last_card;
	//~PlayerStatus();
};

