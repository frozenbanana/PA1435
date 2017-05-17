#include "InputHandler.hpp"
#include "SystemHandler.hpp"	// Allows Accessing of parentPointer functions

InputHandler::InputHandler()
{

}
InputHandler::~InputHandler()
{

}





void InputHandler::EventHappend(fakeMSG msg, SystemHandler* parentPointer)
{
	this->InterpretMSG(msg, parentPointer);

	// F�ljer vi 'Note-to-self' i InterpretMSG s� �r det h�r ute if-satser ligger ist.
}

clearMSG InputHandler::InterpretMSG(fakeMSG msg, SystemHandler* parentPointer)
{
	// Recieves msg in some language and protocol,
	// Translates to internal clearMSG language and protocol.

	clearMSG TranslatedMSG;
	bool PlayerMoved = false;

	// Check direction
	if (msg.Direction != nullptr) {
		direction TempDirection;

		if (*msg.Direction == Up)	// When real input is given, these lines will be modified.
		{
			TempDirection = Up;
			TranslatedMSG.Direction = &TempDirection;

			PlayerMoved = true;
		}
		else if (*msg.Direction == Left) {
			TempDirection = Left;
			TranslatedMSG.Direction = &TempDirection;

			PlayerMoved = true;
		}
		else if (*msg.Direction == Right) {
			TempDirection = Right;
			TranslatedMSG.Direction = &TempDirection;


			PlayerMoved = true;
		}
		else if (*msg.Direction == Down) {
			TempDirection = Down;
			TranslatedMSG.Direction = &TempDirection;


			PlayerMoved = true;
		}


		parentPointer->RelayAction(TranslatedMSG, parentPointer);
	}

	// Check use
	else if (msg.UsedUse != nullptr)
	{

		if (*msg.UsedUse == true) {

			bool Temp = true;
			TranslatedMSG.UsedUse = &Temp;

			parentPointer->RelayAction(TranslatedMSG, parentPointer);

		}



	}

	// Check Atk
	else if (msg.UsedAttack != nullptr)
	{

		if (*msg.UsedAttack == true) {

			bool Temp = true;
			TranslatedMSG.UsedAttack = &Temp;

			parentPointer->RelayAction(TranslatedMSG, parentPointer);
		}

	}

	// Check move
	if (msg.UsedMove != nullptr) {

		bool Temp = true;
		TranslatedMSG.UsedMove = &Temp;

		parentPointer->RelayAction(TranslatedMSG, parentPointer);
	}
		

	/* NoteToSelf - Daniel.

	Vi beh�ver inte ha parentpointer h�r, utan det r�cker att EventHappend()
	som vandrar till InputHandler har den, s� kan vi enkelt bara kolla det
	utreturnerade MSG v�rdet och ha en if-sats.

	*/
	return TranslatedMSG;
}
