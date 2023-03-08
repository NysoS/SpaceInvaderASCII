#pragma once
#include <vector>
#include <Engine/Gameplay/GameObjects/GameObject.h>
#include <Engine/Mathf/Vector.h>

class Input;
class InputEvent;

class PlayField {

private:
	std::vector<GameObject*> gameObjectsToSpawn;
	std::vector<GameObject*> gameObjectsToDelete;
	std::vector<InputEvent*> poolEvents;

public:
	Input* cotrollerInput;
	Vector2D Bounds;

	// Number of available active laser slots for aliens and player
	int AlienLasers = 10;
	int PlayerLasers = 4;

	PlayField(Vector2D _iBounds);
	~PlayField();

	const std::vector<GameObject*> GameObjects();
	const std::vector<GameObject*> GameObjectsToDelete();

	void Start();
	void Update();
	
	GameObject* GetPlayerObject();
	void SpawnLaser(GameObject* _newObj);
	void DespawnLaser(GameObject* _newObj);
	void AddObject(GameObject* _newObj);
	void RemoveObject(GameObject* _newObj);

	bool PollEvent(InputEvent& _inputEvent);
	void AddEvent(InputEvent* _inputEvent);

	//Remove all pointer in memorie 
	void RemoveAllGameObject();
	void ClearGame();
};