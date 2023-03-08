#pragma once
#include "Alien.h"
#include <Engine/Gameplay/World/PlayField.h>
#include <Game/GameObjects/AlienLaser.h>
#include <random>
#include "ConsoleRenderer.h"

std::default_random_engine rGen2;
typedef std::uniform_real_distribution<float> floatRandAlien;

Alien::Alien() : GameObject(){

}

Alien::Alien(std::string _name) : GameObject(_name) {

}

Alien::~Alien()
{
}

void Alien::Update(PlayField& _world) 
{
	pos.x += direction * velocity;
	// Border check
	if (pos.x < 0 || pos.x >= _world.Bounds.x - 1)
	{
		direction = -direction;
		pos.y += 1;
	}

	// Border check vertical:
	if (pos.y >= _world.Bounds.y)
	{
		// kill player
		GameObject* player = _world.GetPlayerObject();
		if (!player) return; //Check si on récupère le personnage
		if (pos.IntCmp(player->GetPos()))
		{
			_world.RemoveObject(player);
		}
	}

	floatRandAlien fireRate(0, 1);
	if (fireRate(rGen2) < 1 && _world.AlienLasers > 0)
	{
		//Spawn laser
		GameObject* newLaser = new AlienLaser("AlienLaser"); //Change reference to pointer
		newLaser->pos = pos;
		newLaser->SetSprite(RaiderSprites::RS_AlienLaser);
		_world.SpawnLaser(newLaser);
	}
}

bool Alien::DecreaseHealth() {
	health -= 1.f; 
	return health <= 0;
}