#ifndef WORLDHANDLER_HPP
#define WORLDHANDLER_HPP

#include "Tile.hpp"
#include "Character.hpp"		// For Position
#include "InputHandler.hpp"		// For clearMSG
#include "CharacterHandler.hpp"


class SystemHandler;			// Forward declaration

class WorldHandler {
private:
	tile** Grid; // [x][y] based tile-grid.
	int GridLength;

	CharacterHandler myCharacterHandler;



public:
	WorldHandler();
	~WorldHandler();
	void DestroyGrid();

	void GenerateMap();
	void GenerateEnvironment();
	void GenerateNPC();

	position CalcedPos(clearMSG msg, position OldPos);

	void RelayAction(clearMSG ClearMSG, SystemHandler* parentPointer);

	void InitiateNextLevel();

	void UpdateTile(position tileCoordinates);

	// Requires an additional 'character->DealDmg()' function in order to
	// function properly
	void UpdateMonster(tile tileWhoseOccupantIsAMonster);

	void UpdateNPC(/*players response*/);

	//------------

	int GetGridLength();
	tile** *const FetchGrid();

	direction GetPlayersDirection();
	position GetPlayersPosition();


};


#endif