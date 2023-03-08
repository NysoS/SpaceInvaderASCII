#pragma once
#include "GameObject.h"
#include <random>

GameObject::GameObject() : IDGameObject(std::rand()), pos(Vector2D(0,0)), sprite(' ')
{
}

GameObject::GameObject(std::string _name) : IDGameObject(std::rand()), NameGameObject(_name), pos(Vector2D(0, 0)), sprite(' ')
{
}

GameObject::~GameObject(){}

unsigned GameObject::GetID() const{
	return IDGameObject;
}

void GameObject::Update(PlayField& _world)
{}


std::string GameObject::GetName() const
{
	return NameGameObject;
}

bool GameObject::DecreaseHealth() {
	return true;
}

std::vector<GameObject*> GameObject::GetAnyObjects(const std::vector<GameObject*> gameObjects, std::string tag, GameObject& checkObject) {
	std::vector<GameObject*> allMatchBytag;
	for (GameObject* go : gameObjects) {
		if (go != &checkObject) {
			if (strcmp(go->GetName().c_str(), tag.c_str()) == 0) {
				allMatchBytag.push_back(go);
			}
		}
	}
	return allMatchBytag;
}

Vector2D GameObject::GetPos() const
{
	return pos;
}

unsigned char GameObject::GetSprite() const
{
	return sprite;
}

void GameObject::SetSprite(unsigned char _sprite)
{
	sprite = _sprite;
}

void GameObject::SetPos(float _posX, float _posY)
{
	pos.x = _posX;
	pos.y = _posY;
}
