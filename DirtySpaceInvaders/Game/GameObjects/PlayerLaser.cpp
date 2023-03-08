#pragma once
#include "PlayerLaser.h"
#include <Engine/Gameplay/World/PlayField.h>

PlayerLaser::PlayerLaser() : GameObject()
{
}

PlayerLaser::PlayerLaser(std::string _name) : GameObject(_name)
{
}

PlayerLaser::~PlayerLaser()
{
}

void PlayerLaser::Update(PlayField& _world)
{
	bool deleted = false;
	pos.y -= 1.f;
	if (pos.y < 0)
	{
		deleted = true;
	}

	//Ajoute le laser toucher dans la liste des objets a supprimer
	std::vector<GameObject*> laserGameObjects = GetAnyObjects(_world.GameObjects(), "AlienLaser", *this);
	for (GameObject* otherLaser : laserGameObjects) {
		if (pos.IntCmp(otherLaser->GetPos())) {
			_world.RemoveObject(otherLaser);
			deleted = true;
		}
	}

	std::vector<GameObject*> alienGameObjects = GetAnyObjects(_world.GameObjects(), "AlienShip", *this);
	for (GameObject* otherLaser : alienGameObjects) {
		if (pos.IntCmp(otherLaser->GetPos())) {
			_world.RemoveObject(otherLaser);
			deleted = true;
		}
	}

	if (deleted)
	{
		_world.DespawnLaser(this);
		//Remove delete this car le fait au dessus
	}
}

bool PlayerLaser::DecreaseHealth()
{
	return false;
}
