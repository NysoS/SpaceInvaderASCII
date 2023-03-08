#pragma once
#include <Engine/Mathf/Vector.h>
#include <vector>
#include <string>

class PlayField;

class GameObject {

private:
	unsigned IDGameObject;
	std::string NameGameObject;
	unsigned char sprite;

public:
	GameObject();
	GameObject(std::string _name);
	virtual ~GameObject() = 0;

	Vector2D pos;

	unsigned GetID() const;
	std::string GetName() const;
	Vector2D GetPos() const;
	unsigned char GetSprite() const;

	void SetPos(float _posX, float _posY);
	void SetSprite(unsigned char _sprite);

	virtual void Update(PlayField& _world) = 0;
	virtual bool DecreaseHealth();
	
	std::vector<GameObject*> GetAnyObjects(const std::vector<GameObject*> gameObjects, std::string tag, GameObject& checkObject);
};