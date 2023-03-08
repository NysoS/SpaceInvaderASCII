#pragma once
#include <map>
#include <functional>
#include <Engine/Input/InputAction.h>
#include <Engine/Input/InputController.h>

class InputManager final
{

private:
	std::map<sf::Keyboard::Key, ActionType> InputsBinds;

public:

	static InputManager * GetInputManagerInstance();

	bool Init();
	bool Update();
	//bool Reset();

	void BindInputs();

	void BindAxis(ActionType _actionType,  void* _ctx, std::function<void(float)> _func);
	void BindAction(ActionType _actionType, void* _ctx, std::function<void()> _func);

};