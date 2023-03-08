#pragma once
#include <Engine/Gameplay/GameObjects/GameObject.h>

class AlienLaser : public GameObject
{

public:
	AlienLaser();
	AlienLaser(std::string _name);
	~AlienLaser();

	void Update(PlayField& _world) override;
	bool DecreaseHealth() override;
};