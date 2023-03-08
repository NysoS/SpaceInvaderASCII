#include "ConsoleRenderer.h"

#include <random>
#include <thread>
#include <memory>
#include <string>
#include <conio.h>
#include <iostream>
#include <functional>
#include <thread>

#include <Engine/Mathf/Vector.h>
#include "Engine\Gameplay\GameObjects\GameObject.h"
#include <Game/GameObjects/Alien.h>
#include <Game/GameObjects/PlayerShip.h>
#include <Engine/Gameplay/World/PlayField.h>
#include <Engine/Input/Input.h>
#include <Engine/Input/InputEvent.h>

std::default_random_engine rGen;
typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

bool StartGame = false;

class PlayField;

/*class PlayField
{
private:
	std::vector<GameObject*> gameObjectsToSpawn;
	std::vector<GameObject*> gameObjectsToDelete;

public:
	Input* cotrollerInput;
	Vector2D bounds;

	// Number of available active laser slots for aliens and player
	int AlienLasers = 10;
	int PlayerLasers = 4;

	PlayField(Vector2D iBounds) : bounds(iBounds) { cotrollerInput = new RndInput(); }; //Init cotrollerInput
	const std::vector<GameObject*> GameObjects() { return gameObjectsToSpawn; }
	const std::vector<GameObject*> GameObjectsToDelete() { return gameObjectsToDelete; }

	std::vector<InputEvent*> poolEvents;

	bool PollEvent(InputEvent& inputEvent) {

		if (poolEvents.size() > 0) inputEvent = *poolEvents.at(0);
		if (inputEvent.type == InputEvent::None || poolEvents.size() <= 0) {
			inputEvent.type == InputEvent::None;
			return false;
		}

		poolEvents.erase(poolEvents.begin());

		return true;
	}

	void AddEvent(InputEvent* inputEvent) {
		poolEvents.push_back(inputEvent);
	}

	void ClearGame() {
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

	void Update()
	{
		// Update list of active objects in the world
		for (auto it : GameObjects()) //Change gameObjects to GameOject const
		{
			it->Update(*this);
		}
	}

	GameObject* GetPlayerObject()
	{
		//Change playerShip -> PlayerShip
		auto it = std::find_if(gameObjectsToSpawn.begin(), gameObjectsToSpawn.end(), [](GameObject* in) { return (strcmp(in->m_objType, "PlayerShip") == 0); });
		if (it != gameObjectsToSpawn.end())
			return (*it);
		else
			return nullptr;
	}

	

	void SpawnLaser(GameObject* newObj)
	{
		if (!newObj) return; //Check if nullptr

		//Change alienLaser -> AlienLaser
		if (strcmp(newObj->m_objType, "AlienLaser") == 0)
			AlienLasers--;

		else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
			PlayerLasers--;

		AddObject(newObj);
	}

	void DespawnLaser(GameObject* newObj)
	{
		if (!newObj) return; //Check if nullptr

		if (strcmp(newObj->m_objType, "AlienLaser") == 0)
			AlienLasers++;

		else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
			PlayerLasers++;

		RemoveObject(newObj);
	}

	void AddObject(GameObject* newObj)
	{
		gameObjectsToSpawn.push_back(newObj);
	}

	void RemoveObject(GameObject* newObj)
	{
		//check if newObj est pas nullprt
		if (!newObj) return;

		//Change find_if -> find
		auto it = std::find(gameObjectsToSpawn.begin(), gameObjectsToSpawn.end(), newObj);
		gameObjectsToDelete.push_back(newObj);
	}
};*/

/*
class PlayerLaser : public GameObject
{
public:
	PlayerLaser() { m_objType = new char[64]; strcpy(m_objType, "PlayerLaser"); sprite = RS_PlayerLaser; IDGameObject = std::rand(); }
	~PlayerLaser() { delete[] m_objType; }

	void Update(PlayField& world)
	{
		bool deleted = false;
		pos.y -= 1.f;
		if (pos.y < 0)
		{
			deleted = true;
		}

		//Ajoute le laser toucher dans la liste des objets a supprimer
		std::vector<GameObject*> laserGameObjects = GetAnyObjects(world.GameObjects(), "AlienLaser", *this);
		for (GameObject* otherLaser : laserGameObjects) {
			if (pos.IntCmp(otherLaser->pos)) {
				world.RemoveObject(otherLaser);
				deleted = true;
			}
		}

		std::vector<GameObject*> alienGameObjects = GetAnyObjects(world.GameObjects(), "AlienShip", *this);
		for (GameObject* otherLaser : alienGameObjects) {
			if (pos.IntCmp(otherLaser->pos)) {
				world.RemoveObject(otherLaser);
				deleted = true;
			}
		}

		if (deleted)
		{
			world.DespawnLaser(this);
			//Remove delete this car le fait au dessus
		}
	}
};*/


/*class PlayerShip : public GameObject
{
public:
	PlayerShip() { m_objType = new char[64]; strcpy(m_objType, "PlayerShip"); sprite = RS_Player; IDGameObject = std::rand(); }
	~PlayerShip() { delete[] m_objType; } //delete array

	void Update(PlayField& world)
	{
		char ch;

		if (_kbhit()) {
			//program pauses here until key is pressed
			ch = _getch();

			if (ch == 'q') {
				if (pos.x > 0) {
					InputEvent* inputEvent = new InputEvent();
					inputEvent->type = InputEvent::KeyPressed;
					inputEvent->BindInput(this, &PlayerShip::Move, -1);
					world.AddEvent(inputEvent);
				}
			}
			else if(ch == 'd') {
				if (pos.x < world.bounds.x -1 ) {
					InputEvent* inputEvent = new InputEvent();
					inputEvent->type = InputEvent::KeyPressed;
					inputEvent->BindInput(this, &PlayerShip::Move, 1);
					world.AddEvent(inputEvent);
				}
			}
			else if (ch == 'w') {
				InputEvent* inputEvent = new InputEvent();
				inputEvent->type = InputEvent::Close;
				world.AddEvent(inputEvent);
			}
		}

		if (world.cotrollerInput->Fire() && world.PlayerLasers > 0)
		{
			//Spawn laser
			GameObject* newLaser = new PlayerLaser; //Change reference to pointer
			newLaser->pos = pos;
			world.SpawnLaser(newLaser);
		}
	}

	void Move(float axisValue) {
		pos.x += axisValue;
	}
};*/

int main()
{
	rGen.seed(1);

	Vector2D size(80, 28);
	Renderer consoleRenderer(size);
	PlayField world(size);

	intRand xCoord(0, (int)size.x- 2);
	intRand yCoord(0, 10);

	// Populate aliens
	for (int k = 0; k < 20; k++)
	{
		Alien* a = new Alien("AlienShip"); //Change reference to pointer
		a->SetPos((float)xCoord(rGen), (float)yCoord(rGen));
		a->SetSprite(RaiderSprites::RS_Alien);
		world.AddObject(a);
	}

	// Add player
	PlayerShip* p = new PlayerShip("PlayerShip");
	p->SetPos(40, 27);
	p->SetSprite(RaiderSprites::RS_Player);
	world.AddObject(p);

	StartGame = true; //Add variable pour lancer la boucle de jeu

	while (StartGame) //Le jeu tourne tant que la variable est egal a true
	{
		world.Update();

		InputEvent Event;
		while (world.PollEvent(Event))
		{
			if (Event.Type == InputEvent::Close)
				StartGame = false;

			if (Event.Type == InputEvent::KeyPressed) {
				std::cout << " Key pressed" << "\n";
			}
		}

		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(Vector2D(it->GetPos()), it->GetSprite());
			rl.push_back(a);
		}

		consoleRenderer.Update(rl);
		world.RemoveAllGameObject();

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::nanoseconds(1));
	}

	world.ClearGame();
}