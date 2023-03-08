#pragma once
#include "PlayerShip.h"
#include <Engine/Gameplay/World/PlayField.h>
#include <Engine/Input/Input.h>
#include <Engine/Input/InputEvent.h>
#include <Game/GameObjects/PlayerLaser.h>
#include <conio.h>
#include "ConsoleRenderer.h"

PlayerShip::PlayerShip() : GameObject()
{
}

PlayerShip::PlayerShip(std::string _name) : GameObject(_name)
{
}

PlayerShip::~PlayerShip()
{
}

void PlayerShip::Update(PlayField& _world)
{
	char ch;
	if (_kbhit()) {
		//program pauses here until key is pressed
		ch = _getch();

		if (ch == 'q') {
			if (pos.x > 0) {
				InputEvent* inputEvent = new InputEvent();
				inputEvent->Type = InputEvent::KeyPressed;
				inputEvent->BindInput(this, &PlayerShip::Move, -1);
				_world.AddEvent(inputEvent);
			}
		}
		else if (ch == 'd') {
			if (pos.x < _world.Bounds.x - 1) {
				InputEvent* inputEvent = new InputEvent();
				inputEvent->Type = InputEvent::KeyPressed;
				inputEvent->BindInput(this, &PlayerShip::Move, 1);
				_world.AddEvent(inputEvent);
			}
		}
		else if (ch == 'w') {
			InputEvent* inputEvent = new InputEvent();
			inputEvent->Type = InputEvent::Close;
			_world.AddEvent(inputEvent);
		}
		else if (ch == 'z' && _world.PlayerLasers > 0)
		{
			//Spawn laser
			GameObject* newLaser = new PlayerLaser(); //Change reference to pointer
			newLaser->pos = pos;
			newLaser->SetSprite(RaiderSprites::RS_PlayerLaser);
			_world.SpawnLaser(newLaser);
		}
	}
}

void PlayerShip::Move(float axisValue) {
	pos.x += axisValue;
}

bool PlayerShip::DecreaseHealth()
{
	return false;
}
