#pragma once
#include <Engine/Gameplay/Components/ComponentInterface.h>

class Transform : public ComponentInterface {

public:
	Transform() = delete;
	Transform(GameObject& _gameObject);

	~Transform();
};