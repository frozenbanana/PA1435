#include "WorldHandler.hpp"
#include "SystemHandler.hpp"


WorldHandler::WorldHandler()
{
	// Allocates a grid according to gridlength
	this->GridLength = 5;
	this->Grid = new tile*[this->GridLength];
	for (int i = 0; i < this->GridLength; i++) {
		this->Grid[i] = new tile[this->GridLength];
	}

	// Fills the grid with empty tiles
	for (int i = 0; i < this->GridLength; i++) {
		for (int j = 0; j < this->GridLength; j++) {
			this->Grid[i][j].position.x = i;
			this->Grid[i][j].position.y = j;
			this->Grid[i][j].tileData = Nothing;
			this->Grid[i][j].occupant = nullptr;
		}
	}


	// Modifies 4 tiles around the player for testing purposes.
	//
	//
	// [0,2]	Ladder		[2,2]
	// Wall		Player		Hostile	
	// [0,0]	Nothing		[2,0]	...

	this->Grid[0][1].tileData = Wall;
	this->Grid[1][2].tileData = Ladder;

	this->Grid[2][1].tileData = Hostile;
	this->Grid[2][1].occupant = this->myCharacterHandler.GetTestNPC();

	this->Grid[1][0].tileData = Nothing;



}
WorldHandler::~WorldHandler()
{

}

void WorldHandler::DestroyGrid()
{
	for (int i = 0; i < this->GridLength; i++)
		delete[] this->Grid[i];
	delete[] this->Grid;
}



void WorldHandler::GenerateMap()
{

}

void WorldHandler::GenerateEnvironment()
{

}

void WorldHandler::GenerateNPC()
{

}

position WorldHandler::CalcedPos(clearMSG msg, position OldPos)
{
	position newPos;
	if (*msg.Direction == Up) {
		newPos.x = OldPos.x;
		newPos.y = OldPos.y + 1;
	}
	else if (*msg.Direction == Left) {
		newPos.x = OldPos.x - 1;
		newPos.y = OldPos.y;
	}
	else if (*msg.Direction == Right) {
		newPos.x = OldPos.x + 1;
		newPos.y = OldPos.y;
	}
	else if (*msg.Direction == Down) {
		newPos.x = OldPos.x;
		newPos.y = OldPos.y - 1;
	}

	return newPos;
}

void WorldHandler::InitiateNextLevel()
{
	std::cout << "baloons!" << std::endl << std::endl;
}

void WorldHandler::RelayAction(clearMSG clearMSG, SystemHandler* parentPointer)
{
	// Check if Direction is updated
	if (clearMSG.Direction != nullptr) {
		characterData container;
		container.Direction = clearMSG.Direction;
		this->myCharacterHandler.UpdateCharacter(container, parentPointer);


	}

	// Check if Interaction is updated
	if (clearMSG.UsedUse != nullptr) {

		if (*clearMSG.UsedUse == true) {

			tile* FrontTile = this->myCharacterHandler.GetTileAhead(&this->Grid);

			tileData data = FrontTile->tileData;

			if (data == Ladder) {
				FrontTile->occupant;
				FrontTile->tileData = Nothing;
				
				parentPointer->InitiateNextLevel();
			}

		}

	}


	// Check if player attacked
	if (clearMSG.UsedAttack != nullptr) {

		if (*clearMSG.UsedAttack == true) {

			tile* FrontTile = this->myCharacterHandler.GetTileAhead(&this->Grid);
			tileData data = FrontTile->tileData;

			if (data == Hostile) {

				int PlayersDmg = this->myCharacterHandler.GetPlayer()->GetDamage();
				FrontTile->occupant->ModifyHealth(PlayersDmg);

				// Simple death-testing, to implement this better, do one of the comments below
				if (FrontTile->occupant->GetHealth() <= 0) {
					FrontTile->occupant = nullptr;
					FrontTile->tileData = Nothing;
				}
					

				// Either ModifyHealth should check if that character died.
				// Or we check here.
				// Or some observer looking at that character notices the change and checks if character dies.

			}


		}


	}

	// Check if player moved
	if (clearMSG.UsedMove != nullptr) {

		if (*clearMSG.UsedMove == true) {

			tile* TileInFront = this->myCharacterHandler.GetTileAhead(&this->Grid);

			// If player is not trying to move outside the grid
			if (TileInFront != nullptr) {

				// Check if that tile is available.
				if ((TileInFront->tileData == Nothing) && (this->Grid[TileInFront->position.x][TileInFront->position.y].occupant == nullptr)) {

					// Move the character to that tile.
					characterData container;
					container.Position = &TileInFront->position;
					this->myCharacterHandler.UpdateCharacter(container, parentPointer);

				}
			}
				



		}

	}

}


void WorldHandler::UpdateTile(position tileCoordinates)
{
	// There used to be a monster here, there isn't anymore.
	this->Grid[tileCoordinates.x][tileCoordinates.y].tileData = Nothing;
	// Possibly do something to the occupant, like 'destroy()' or something similar.
	this->Grid[tileCoordinates.x][tileCoordinates.y].occupant = nullptr;
}

void WorldHandler::UpdateMonster(tile tileWhoseOccupantIsAMonster)
{
	// tileWhoseOccupantIsAMonster.occupant->DealDmg(maybeplayerweapon, or maybe function knows player inside of itself)
}



int WorldHandler::GetGridLength()
{
	return this->GridLength;
}

tile** *const WorldHandler::FetchGrid()
{
	return &this->Grid;
}



direction WorldHandler::GetPlayersDirection()
{
	return this->myCharacterHandler.GetPlayer()->GetDirection();
}
position WorldHandler::GetPlayersPosition()
{
	return this->myCharacterHandler.GetPlayer()->GetPosition();
}

