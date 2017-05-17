#ifndef NPC_HPP
#define NPC_HPP

#include "Character.hpp"

class NPC : public Character {
private:

	// Root of the Dialogue-Tree.
	// bool hostile;

	int NPCValue;


public:

	//NPC();
	//~NPC();

	//void IamHERE();

	NPC::NPC()
	{
		this->NPCValue = 1;
		this->SetPosition(position{ 2,1 });
	}
	NPC::~NPC()
	{
		this->NPCValue = 0;
	}


	//void NPC::IamHERE()
	//{
	//	int Seriously = 1;
	//}

};




#endif