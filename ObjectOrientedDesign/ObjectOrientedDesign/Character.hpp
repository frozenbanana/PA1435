#ifndef CHARACTER_HPP
#define CHARACTER_HPP


struct position
{
	int x;
	int y;
};

enum direction { Up, Left, Right, Down };

class Character {
private:

	int Health;
	int Damage;
	position Position;
	direction Direction;


public:
	Character();
	~Character();

	void ModifyHealth(int HealthImpact);

	void SetDamage(int Damage);
	void SetHealth(int Health);
	void SetPosition(position newPosition);
	void SetDirection(direction newDirection);

	int GetDamage();
	int GetHealth();
	position GetPosition();
	direction GetDirection();

};


#endif