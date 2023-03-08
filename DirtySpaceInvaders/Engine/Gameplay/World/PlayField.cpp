#pragma once
#include <Engine/Gameplay/World/PlayField.h>
#include <Engine/Mathf/Vector.h>
#include <Engine/Input/InputEvent.h>

PlayField::PlayField(Vector2D _iBounds) : Bounds(_iBounds) {
	cotrollerInput = nullptr;
}

PlayField::~PlayField() {

}

const std::vector<GameObject*> PlayField::GameObjects() {
	return gameObjectsToSpawn;
}

const std::vector<GameObject*> PlayField::GameObjectsToDelete()
{
	return gameObjectsToDelete;
}

void PlayField::Update()
{
	// Update list of active objects in the world
	for (auto it : GameObjects()) //Change gameObjects to GameOject const
	{
		it->Update(*this);
	}
}

GameObject* PlayField::GetPlayerObject()
{
	//Change playerShip -> PlayerShip
	auto it = std::find_if(gameObjectsToSpawn.begin(), gameObjectsToSpawn.end(), [](GameObject* in) { return (strcmp(in->GetName().c_str(), "PlayerShip") == 0); });
	if (it != gameObjectsToSpawn.end())
		return (*it);
	else
		return nullptr;
}

void PlayField::SpawnLaser(GameObject* _newObj)
{
	if (!_newObj) return; //Check if nullptr

		//Change alienLaser -> AlienLaser
	if (strcmp(_newObj->GetName().c_str(), "AlienLaser") == 0)
		AlienLasers--;

	else if (strcmp(_newObj->GetName().c_str(), "PlayerLaser") == 0)
		PlayerLasers--;

	AddObject(_newObj);
}

void PlayField::DespawnLaser(GameObject* _newObj)
{
	if (!_newObj) return; //Check if nullptr

	if (strcmp(_newObj->GetName().c_str(), "AlienLaser") == 0)
		AlienLasers++;

	else if (strcmp(_newObj->GetName().c_str(), "PlayerLaser") == 0)
		PlayerLasers++;

	RemoveObject(_newObj);
}

void PlayField::AddObject(GameObject* _newObj)
{
	gameObjectsToSpawn.push_back(_newObj);
}

void PlayField::RemoveObject(GameObject* _newObj)
{
	//check if newObj est pas nullprt
	if (!_newObj) return;

	//Change find_if -> find
	auto it = std::find(gameObjectsToSpawn.begin(), gameObjectsToSpawn.end(), _newObj);
	if (!*it) return;

	gameObjectsToDelete.push_back(_newObj);
}

bool PlayField::PollEvent(InputEvent& _inputEvent)
{
	if (poolEvents.size() > 0) _inputEvent = *poolEvents.at(0);
	if (_inputEvent.Type == InputEvent::None || poolEvents.size() <= 0) {
		_inputEvent.Type == InputEvent::None;
		return false;
	}

	poolEvents.erase(poolEvents.begin());

	return true;
}

void PlayField::AddEvent(InputEvent* _inputEvent)
{
	poolEvents.push_back(_inputEvent);
}

//Remove all pointer in memorie 
void PlayField::RemoveAllGameObject() {
	for (GameObject* objectToDelete : GameObjectsToDelete()) {
		if (objectToDelete) {
			gameObjectsToSpawn.erase(std::find(gameObjectsToSpawn.begin(), gameObjectsToSpawn.end(), objectToDelete)); //Retire l'objet a supprimer
			delete objectToDelete; //delete le pointer 
			objectToDelete = nullptr;
		}
	}
	gameObjectsToDelete.clear();
}

void PlayField::ClearGame() {
	RemoveAllGameObject();
	for (GameObject* clearObject : gameObjectsToSpawn) {
		if (clearObject) {
			delete clearObject;
		}
	}
	gameObjectsToSpawn.clear();

	for (InputEvent* inputs : poolEvents) {
		if (inputs) {
			delete inputs;
		}
	}
	poolEvents.clear();
}