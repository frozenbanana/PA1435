#include "SystemHandler.hpp"

SystemHandler::SystemHandler()
{

}
SystemHandler::~SystemHandler()
{
	this->ShutDown();
}
void SystemHandler::ShutDown()
{
	this->myWorldHandler.DestroyGrid();
}





void SystemHandler::EventHappend(fakeMSG msg, SystemHandler* parentPointer)
{
	this->myInputHandler.EventHappend(msg, parentPointer);
}


void SystemHandler::RelayAction(clearMSG msg, SystemHandler* parentPointer)
{
	this->myWorldHandler.RelayAction(msg, parentPointer);
}

void SystemHandler::InitiateNextLevel()
{

}


void SystemHandler::PlayerDied()
{

}



void SystemHandler::PrintWorld()
{
	using namespace std;

	tile** *GridPointer = this->myWorldHandler.FetchGrid();
	int GridLength = this->myWorldHandler.GetGridLength();

	tile* LineToBePrinted = new tile[GridLength];

	// Prints 'roof'
	for (int i = 0; i < GridLength; i++) {
		cout << "____";
	}
	cout << endl;

	// Loops Y-wise
	for (int i = GridLength-1; -1 < i; i--) {

		// Reconstruct data so that printing is easier.
		for (int j = 0; j < GridLength; j++) 
			LineToBePrinted[j] = (*GridPointer)[j][i];
		
		PrintLine(&LineToBePrinted, GridLength, i);

	}

	delete[] LineToBePrinted;

}

void SystemHandler::PrintTile(tile TileToBePrinted)
{
	using namespace std;
	char content;

	if (TileToBePrinted.tileData == Nothing)
		content = ' ';
	else if (TileToBePrinted.tileData == Wall)
		content = 'X';
	else if (TileToBePrinted.tileData == Ladder)
		content = 'L';
	else if (TileToBePrinted.tileData == Hostile)
		content = 'M';
	else if (TileToBePrinted.tileData == Trap1)
		content = '1';
	else if (TileToBePrinted.tileData == Trap2)
		content = '2';

	cout << "| " << content;
}

void SystemHandler::PrintLine(tile* *LineToBePrinted, int GridLength, int currentLine)
{
	using namespace std;
	char content;

	tile* NonHeadache = *LineToBePrinted;


	position PlayersPosition = this->myWorldHandler.GetPlayersPosition();


	for (int i = 0; i < GridLength; i++)
		cout << "   |";
	cout << endl;


	for (int i = 0; i < GridLength; i++) {

		if (PlayersPosition.x == i
			&&	PlayersPosition.y == currentLine) {

			direction PlayersDirection = this->myWorldHandler.GetPlayersDirection();

			if (PlayersDirection == Up) {
				content = '^';
			}
			else if (PlayersDirection == Left) {
				content = '<';
			}
			else if (PlayersDirection == Right) {
				content = '>';
			}
			else if (PlayersDirection == Down) {
				content = 'v';
			}
		}

		else if (NonHeadache[i].tileData == Nothing)
			content = ' ';
		else if (NonHeadache[i].tileData == Wall)
			content = '+';
		else if (NonHeadache[i].tileData == Ladder)
			content = 'L';
		else if (NonHeadache[i].tileData == Hostile)
			content = 'X';
		else if (NonHeadache[i].tileData == Trap1)
			content = ' ';
		else if (NonHeadache[i].tileData == Trap2)
			content = ' ';

		cout << " " << content << " |";

	}

	cout << endl;

	for (int i = 0; i < GridLength; i++) {

		cout << "___|";

	}

	cout << endl;
}