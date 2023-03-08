#pragma once
#include <Engine/Gameplay/GameObjects/GameObject.h>

class Alien : public GameObject
{
private:
	float health = 1.f;
	float energy = 0.f;
	float direction = 1.f;
	float velocity = 0.5f;

public:
	Alien();
	Alien(std::string _name);
	~Alien();

	void Update(PlayField& world) override;
	bool DecreaseHealth() override;
};