#pragma once
#include "AlienLaser.h"
#include <Engine/Gameplay/World/PlayField.h>

AlienLaser::AlienLaser() : GameObject()
{
}

AlienLaser::AlienLaser(std::string _name) : GameObject(_name)
{
}

AlienLaser::~AlienLaser()
{
}

void AlienLaser::Update(PlayField& _world)
{
	bool deleted = false;
	pos.y += 1.f;
	if (pos.y >= _world.Bounds.y)
	{
		deleted = true;
	}

	GameObject* player = _world.GetPlayerObject();
	if (!player) return; //Check si on récupère le personnage
	if (pos.IntCmp(player->pos))
	{
		_world.RemoveObject(player);
		_world.DespawnLaser(this); //Remove lorsque le laser a toucher le joueur
	}

	if (deleted)
	{
		_world.DespawnLaser(this);
	}
}

bool AlienLaser::DecreaseHealth()
{
	return false;
}
