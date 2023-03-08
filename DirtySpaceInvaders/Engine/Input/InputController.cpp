#pragma once
#include "InputController.h"

InputController::InputController()
{
}

InputController::~InputController()
{
}

void InputController::AddInputsAxis(InputAction* _inputAction, std::function<void(float)> _callback)
{
	InputsAxis.insert(std::pair<InputAction*, std::function<void(float)>>(_inputAction, _callback));
}

void InputController::AddInputsAction(InputAction* _inputAction, std::function<void()> _callback)
{
	InputsAction.insert(std::pair<InputAction*, std::function<void()>>(_inputAction, _callback));
}

void InputController::ConsumeInputAxis(float _value)
{
	if (InputsAxis.size() <= 0) return;

	for (auto inputAxis : InputsAxis) {
		if (sf::Keyboard::isKeyPressed(inputAxis.first->Key)) {
			inputAxis.second(_value);
		}
	}
	
}

void InputController::ConsumeInputAction()
{
	if (InputsAction.size() <= 0) return;

	for (auto inputAction : InputsAction) {
		if (sf::Keyboard::isKeyPressed(inputAction.first->Key)) {
			inputAction.second();
		}
	}
}
