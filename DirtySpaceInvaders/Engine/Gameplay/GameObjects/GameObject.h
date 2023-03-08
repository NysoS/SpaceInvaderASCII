#pragma once
#include <Engine/Mathf/Vector.h>
#include <vector>
#include <string>

class PlayField;
class InputController;

class GameObject {

private:
	unsigned IDGameObject;
	std::string NameGameObject;
	unsigned char sprite;
	InputController* PlayerInputController;

public:
	GameObject();
	GameObject(std::string _name);
	virtual ~GameObject();

	Vector2D pos;

	unsigned GetID() const;
	std::string GetName() const;
	Vector2D GetPos() const;
	unsigned char GetSprite() const;

	void SetPos(float _posX, float _posY);
	void SetSprite(unsigned char _sprite);

	virtual void Start();
	virtual void Update(PlayField& _world);
	virtual bool DecreaseHealth();
	
	void SetInputController();
	InputController* GetInputController();

	std::vector<GameObject*> GetAnyObjects(const std::vector<GameObject*> gameObjects, std::string tag, GameObject& checkObject);
};