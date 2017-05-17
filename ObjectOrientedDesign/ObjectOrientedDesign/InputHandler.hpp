#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "FakeMSG.hpp"

class SystemHandler; // Forward declaration for 'EventHappend()'

struct clearMSG
{
	direction*	Direction = nullptr;
	bool*		UsedUse = nullptr;
	bool*		UsedAttack = nullptr;
	bool*		UsedMove = nullptr;
};

class InputHandler {
private:






public:
	InputHandler();
	~InputHandler();

	void EventHappend(fakeMSG msg, SystemHandler* parentPointer);
	clearMSG InterpretMSG(fakeMSG msg, SystemHandler* parentPointer);

	/*PlayerResponse*/void GetMessage();
};


#endif