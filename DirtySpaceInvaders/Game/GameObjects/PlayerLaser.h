#pragma once
#include <Engine/Gameplay/GameObjects/GameObject.h>

class PlayerLaser : public GameObject
{

public:
	PlayerLaser();
	PlayerLaser(std::string _name);
	~PlayerLaser();

	void Update(PlayField& _world) override;
	bool DecreaseHealth() override;
};