#include "CharacterHandler.hpp"
#include "SystemHandler.hpp"	// Granting functions to parentPointer
// #include "WorldHandler.hpp"		// Granting functions to worldPointer


CharacterHandler::CharacterHandler()
{
	int test = 3;

}
CharacterHandler::~CharacterHandler()
{

}


void CharacterHandler::CreateCharacter()
{

}

Player* CharacterHandler::GetPlayer()
{
	return &this->myPlayer;
}


void CharacterHandler::UpdateCharacter(characterData newData, SystemHandler* parentPointer)
{
	if (newData.Health != nullptr) {
		this->myPlayer.ModifyHealth(*newData.Health);

		if (this->myPlayer.GetHealth() < 0)
			parentPointer->PlayerDied();
	}


	if (newData.Position != nullptr)
		this->myPlayer.SetPosition(*newData.Position);

	if (newData.Direction != nullptr)
		this->myPlayer.SetDirection(*newData.Direction);

}

tile* CharacterHandler::GetTileAhead(tile** *PointerToGrid)
{
	//this->Player.GetPosition();
	//this->Player.GetDirection();
	//position coordinates; // = Move position up,left,right,down based on direction.

	position PlayersPosition = this->myPlayer.GetPosition();
	direction PlayersDirection = this->myPlayer.GetDirection();
	position TileAheadsPos;

	tile* returnTile = nullptr;
	
	if (PlayersDirection == Up) {

		// Check if player is looking outside of the grid
		if (PlayersPosition.y != 4) {
			TileAheadsPos.x = PlayersPosition.x;
			TileAheadsPos.y = PlayersPosition.y + 1;

			returnTile = &(*PointerToGrid)[TileAheadsPos.x][TileAheadsPos.y];
		}
		
		
	}
	else if (PlayersDirection == Left) {

		// Check if player is looking outside of the grid
		if (PlayersPosition.x != 0) {
			TileAheadsPos.x = PlayersPosition.x - 1;
			TileAheadsPos.y = PlayersPosition.y;

			returnTile = &(*PointerToGrid)[TileAheadsPos.x][TileAheadsPos.y];
		}

		
	}
	else if (PlayersDirection == Right) {

		// Check if player is looking outside of the grid
		if (PlayersPosition.x != 4) {
			TileAheadsPos.x = PlayersPosition.x + 1;
			TileAheadsPos.y = PlayersPosition.y;

			returnTile = &(*PointerToGrid)[TileAheadsPos.x][TileAheadsPos.y];
		}

		
	}
	else if (PlayersDirection == Down) {

		// Check if player is looking outside of the grid
		if (PlayersPosition.y != 0) {
			TileAheadsPos.x = PlayersPosition.x;
			TileAheadsPos.y = PlayersPosition.y - 1;

			returnTile = &(*PointerToGrid)[TileAheadsPos.x][TileAheadsPos.y];
		}

	}	

	return returnTile;
}

void CharacterHandler::CheckTrapType()
{

}

void CharacterHandler::UpdatePlayerPos(position newPosition)
{
	this->myPlayer.SetPosition(newPosition);
}


//-------------

Character* CharacterHandler::GetTestNPC()
{
	return &this->TestNPC;
}