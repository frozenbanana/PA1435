#ifndef SYSTEMHANDLER_HPP
#define SYSTMEHANDLER_HPP

#include "InputHandler.hpp"
#include "TwitterHandler.hpp"
#include "UIHandler.hpp"
#include "WorldHandler.hpp"

#include "FakeMSG.hpp"

#include <iostream>		// for PrintWorld()


class SystemHandler {
private:

	InputHandler	myInputHandler;
	TwitterHandler	myTwitterHandler;
	UIHandler		myUIHandler;
	WorldHandler	myWorldHandler;

	// PlayerTime




public:
	SystemHandler();
	~SystemHandler();
	void ShutDown();

	// Goes to InputHandler
	void EventHappend(fakeMSG msg, SystemHandler* parentPointer);

	// Goes to WorldHandler
	void RelayAction(clearMSG msg, SystemHandler* parentPointer);

	void InitiateNextLevel();

	void PlayerDied();


	// ------------

	void PrintWorld();
	void PrintTile(tile TileToBePrinted);
	void PrintLine(tile* *LineToBePrinted, int GridLength, int currentLine);

};


#endif