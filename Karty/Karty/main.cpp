#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <vector>
#include <time.h> /*time*/
#include <stdlib.h> /* srand, rand */
#include <cstdio>

#include "Deck.h"
#include "sDealer.h"

 //= *Singleton.get_instance();
#define numer_of_games 2
#define num_of_players 2
#define numer_of_games 2

#define display 4
// 0 podsumowanie
// 1 wyniki pojedyñczych meczy
// 2 talie graczy + gorna karta na stole bez podpisow
// 3 poprzednia + podpisy, co jest czym
// 4 pelny wglad w wszystkie karty po kazdym ruchu
//ToDo  5 animowane akcje  ToDo (poki co, domysl sie co kto robi)

#define to_file 0  // 0 -konsola 1 -plik


using namespace std;


//----------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------




//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------

void start_up(BaseAIBuild* &players, sDealer &dealer) {
	for (int i = 0; i < 5; ++i) {
		dealer.cards.give_top(players[i].deck);
		dealer.cards.give_top(players[i].deck);

	}
	dealer.cards.give_top(dealer.UsedCards);
}

//----------------------------------------------------------------------------------------------------------




int main() {

	
	Rules();





	BaseAIBuild** players = new BaseAIBuild[num_of_players];
	for(int i=0;i<)

	
	system("pause");
	if (to_file == 1) freopen("output.txt", "w", stdout);
	srand(time(NULL));

	AIstandard standard;
	AIjanek janek;
	int player1wins = 0;
	int player2wins = 0;


	start_up(dealer, players);

	for (int i = 0; i < numer_of_games; ++i) {
		/*if(display>4){
			cout<<"deck:"<<endl;
			dealer.cards.cards_sort().print();
			cout<<endl<<endl<<endl<<"table"<<endl;
			dealer.UsedCards.print();
		}*/
		while (!janek.is_win() && !standard.is_win()) {


			if (display > 1) {
				cout << endl << endl;


				if (display == 2 || display == 3) {
					if (display > 2) cout << "top:" << endl;
					cout << mValue[dealer.UsedCards.top().value] << mColor[dealer.UsedCards.top().color] << endl;
				}

				if (display > 3) {
					cout << "stack of used:" << endl;
					dealer.UsedCards.print();
					cout << endl << endl;
					cout << "in deck, not used:" << endl;
					dealer.cards.print();
					cout << endl;
				}
			}


			if (display > 1) {
				cout << endl;
				if (display > 2) cout << "player 1" << endl;

				janek.deck.print();
				cout << endl;
			}

			janek.make_move();

			if (display > 1) {
				cout << endl;
				if (display > 2) cout << "player 2" << endl;


				standard.deck.print();
				cout << endl << endl;
			}

			standard.make_move();



		}
		if (janek.is_win()) {
			player1wins++;
			if (display > 0) cout << "player 1 wins" << endl;

		}
		if (standard.is_win()) {
			player2wins++;
			if (display > 0) cout << "player 2 wins" << endl;

		}
		standard.deck.give_all(dealer.cards);
		//standard.deck.print();
		janek.deck.give_all(dealer.cards);
		//janek.deck.print();
		dealer.add_cards();

		//cout<<dealer.cards.size()<<endl;
		//cout<<endl;
		//dealer.cards.cards_sort().print();
		start_up(standard, janek);


	}
	cout << "player 1 wins " << player1wins << " times" << endl;
	cout << "player 2 wins " << player2wins << " times" << endl;

	return 0;
}
