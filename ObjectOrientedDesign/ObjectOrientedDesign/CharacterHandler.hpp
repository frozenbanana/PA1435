#ifndef CHARACTERHANDLER_HPP
#define CHARACTERHANDLER_HPP

#include "Tile.hpp"
#include "CharacterStructData.hpp"

#include "Player.hpp"
#include "NPC.hpp"


class SystemHandler; // Forward declaration

class CharacterHandler {
private:

	Player myPlayer;
	//NPC TemporaryTestNPC;

	NPC TestNPC;
	Character YeahWhy;


public:
	CharacterHandler();
	~CharacterHandler();

	void CreateCharacter();

	Player* GetPlayer();

	void UpdateCharacter(characterData newData, SystemHandler* parentPointer);	// Should also update position

	tile* GetTileAhead(tile** *PointerToGrid);

	void CheckTrapType();

	void UpdatePlayerPos(position newPosition);	// Unnecessary if 'UpdateCharacter' also updates position

												//-------------

	Character* GetTestNPC();

};


#endif