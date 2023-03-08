#pragma once
#include <string>

class GameObject;

class ComponentInterface {

public:
	ComponentInterface() = delete;
	ComponentInterface(GameObject& _gameObject);

	virtual ~ComponentInterface();

	virtual void Start() = 0;
	virtual void Update(float _deltaTime) = 0;
	virtual void Destroy() = 0;

	virtual std::string GetComponentName() const = 0;

protected:
	GameObject& GetGameObject() const;

private:
	GameObject& ParentGameObject;
};