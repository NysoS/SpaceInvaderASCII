#pragma once
#include "PlayerShip.h"
#include <Engine/Gameplay/World/PlayField.h>
#include <Engine/Input/Input.h>
#include <Engine/Input/InputEvent.h>
#include <Game/GameObjects/PlayerLaser.h>
#include <conio.h>
#include "ConsoleRenderer.h"
#include <Engine/Input/InputController.h>
#include <Engine/Input/InputManager.h>

PlayerShip::PlayerShip() : GameObject()
{
}

PlayerShip::PlayerShip(std::string _name) : GameObject(_name)
{
}

PlayerShip::~PlayerShip()
{
}

void PlayerShip::Start()
{
	InputManager::GetInputManagerInstance()->BindAxis(ActionType::Left, this, std::bind(&PlayerShip::Move, this, std::placeholders::_1, -1.0f));
	InputManager::GetInputManagerInstance()->BindAxis(ActionType::Right, this, std::bind(&PlayerShip::Move, this, std::placeholders::_1, 1.0f));
	InputManager::GetInputManagerInstance()->BindAction(ActionType::Fire, this, std::bind(&PlayerShip::Shoot, this));
}

void PlayerShip::Update(PlayField& _world)
{
	if (GetInputController()) {
		GetInputController()->ConsumeInputAxis(1.f);
		GetInputController()->ConsumeInputAction();
	}

	/*char ch;
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
		else 
	}*/
	if (bShooting && _world.PlayerLasers > 0)
	{
		//Spawn laser
		GameObject* newLaser = new PlayerLaser(); //Change reference to pointer
		newLaser->pos = pos;
		newLaser->SetSprite(RaiderSprites::RS_PlayerLaser);
		_world.SpawnLaser(newLaser);
		bShooting = false;
	}
}

void PlayerShip::Move(float axisValue, float _dir) {
	pos.x += axisValue * _dir;
	
}

void PlayerShip::Shoot()
{
	bShooting = true;
}

bool PlayerShip::DecreaseHealth()
{
	return false;
}
