#pragma once
#include <map>
#include <functional>
#include <utility>
#include "InputAction.h"

class InputController final
{
private:
	std::map<InputAction*, std::function<void(float)>> InputsAxis;
	std::map<InputAction*, std::function<void()>> InputsAction;

public:

	InputController();
	~InputController();

	void AddInputsAxis(InputAction* _inputAction, std::function<void(float)> _callback);
	void AddInputsAction(InputAction* _inputAction, std::function<void()> _callback);

	void ConsumeInputAxis(float _value);
	void ConsumeInputAction();
};