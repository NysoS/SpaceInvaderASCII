#pragma once
#include <Engine/Gameplay/GameObjects/GameObject.h>

class PlayerShip : public GameObject
{
private:
	bool bShooting;

public:
	PlayerShip();
	PlayerShip(std::string _name);
	~PlayerShip();

	void Start() override;
	void Update(PlayField& world) override;
	bool DecreaseHealth() override;

	void Move(float axisValue, float _dir);
	void Shoot();
};