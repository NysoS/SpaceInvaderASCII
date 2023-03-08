#pragma once
#include <Engine/Gameplay/GameObjects/GameObject.h>

class PlayerShip : public GameObject
{

public:
	PlayerShip();
	PlayerShip(std::string _name);
	~PlayerShip();

	void Update(PlayField& world) override;
	bool DecreaseHealth() override;

	void Move(float axisValue);
};