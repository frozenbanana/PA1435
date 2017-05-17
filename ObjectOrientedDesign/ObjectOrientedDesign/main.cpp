
// #include <twitcurl.h>		// For twitter
// #include <oauthlib.h>		//

#include <crtdbg.h>			// For memoryleaks

#include "FakeMSG.hpp"		// For Console-Menu.
#include <iostream>			// 
using namespace std;		//


#include "SystemHandler.hpp"

#include "NPC.hpp"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SystemHandler Game;


	// How grid is currently spaced.
	// Player is faced north.
	//
	// [0,2]	Ladder		[2,2]
	// Wall		Player		Hostile	
	// [0,0]	Nothing		[2,0]	...

	cout << "Release Sprint: Implementation and Testing" << endl;
	cout << "Oliver Glandberger, Henry Bergstr'o'm, Daniel Fredriksson" << endl;
	cout << "PA1435 Objektorienterad Design." << endl << endl;

	char option = -1;
	while (option != '0') {

		cout << "What do you want to do?" << endl;
		cout << "1: " << "Test Game. :>" << endl;
		cout << "0: " << "Exit application. :<" << endl;
		cin >> option;
		cin.ignore();
		cout << endl << endl << endl;

		switch (option) {
		case '1': {	// ------------------- PLAYER MOVEMENT -------------------

			fakeMSG msg;
			direction Direction;
			bool UsedUse = false;
			bool UsedAttack = false;
			bool UsedMove = false;



			char option2 = -1;

			while (option2 != '0') {

				Game.PrintWorld();

				cout << "What do you want to do?" << endl;
				cout << "WASD to change direction." << endl;
				cout << "J to move in the direction you are facing." << endl;
				cout << "E to interact with the tile you are facing." << endl;
				cout << "K to attack the tile you are facing." << endl;
				cout << "0 to exit to main menu." << endl;
				cin >> option2;
				cin.ignore();

				msg.Direction = nullptr;
				msg.UsedUse = nullptr;
				msg.UsedAttack = nullptr;
				msg.UsedMove = nullptr;

				switch (option2) {
				case 'w': {
					Direction = Up;
					msg.Direction = &Direction;

					break;
				}
				case 'a': {
					Direction = Left;
					msg.Direction = &Direction;

					break;
				}
				case 's': {
					Direction = Down;
					msg.Direction = &Direction;

					break;
				}
				case 'd': {
					Direction = Right;
					msg.Direction = &Direction;

					break;
				}
				case 'e': {
					UsedUse = true;
					msg.UsedUse = &UsedUse;

					break;
				}
				case 'k': {
					UsedAttack = true;
					msg.UsedAttack = &UsedAttack;

					break;
				}
				case 'j': {
					UsedMove = true;
					msg.UsedMove = &UsedMove;

					break;
				}
				default: {


					break;
				}

				}

				Game.EventHappend(msg, &Game);

			}


			break;
		}

		default:
			cout << "Not a valid key." << endl;
		}

		cout << endl << endl << endl;
	}


	return 0;
}