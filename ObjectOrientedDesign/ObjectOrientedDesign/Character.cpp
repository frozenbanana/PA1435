#include "Character.hpp"

Character::Character()
{
	this->Direction = Right;
	this->Position = position{ 1, 1 };

	this->Health = 50;
	this->Damage = 50;
}
Character::~Character()
{

}

void Character::ModifyHealth(int Damage)
{
	this->Health -= Damage;
}



void Character::SetDamage(int Damage)
{
	this->Damage = Damage;
}

void Character::SetHealth(int Health)
{
	this->Health = Health;
}

void Character::SetPosition(position newPosition)
{
	this->Position = newPosition;
}

void Character::SetDirection(direction newDirection)
{
	this->Direction = newDirection;
}

int Character::GetDamage()
{
	return this->Damage;
}

int Character::GetHealth()
{
	return this->Health;
}

position Character::GetPosition()
{
	return this->Position;
}

direction Character::GetDirection()
{
	return this->Direction;
}

