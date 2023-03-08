#pragma once
#include "InputManager.h"
#include <assert.h>
#include <utility>
#include <Engine/Gameplay/GameObjects/GameObject.h>

InputManager* Instance = nullptr;

InputManager* InputManager::GetInputManagerInstance()
{
	if (!Instance) {
		Instance = new InputManager();
	}
	return Instance;
}

bool InputManager::Init()
{
#define INIT_DEFAULT_BIND(key, bind) InputsBinds.insert(std::make_pair(key, bind));
#include "KeyboardDefaultBinding.h"
#undef INIT_DEFAULT_BIND

	return false;
}

bool InputManager::Update()
{
	return false;
}

void InputManager::BindInputs()
{
}

void InputManager::BindAxis(ActionType _actionType, void* _ctx, std::function<void(float)> _func)
{
	for (auto& binds : InputsBinds) {
		if (binds.second == _actionType) {
			if (GameObject* gameObject = static_cast<GameObject*>(_ctx)) {
				if (gameObject) {

					gameObject->GetInputController()->AddInputsAxis(
						new InputAction(binds.first, binds.second), 
						_func
					);

				}
			}
		}
	}
}

void InputManager::BindAction(ActionType _actionType, void* _ctx, std::function<void()> _func)
{
	for (auto& binds : InputsBinds) {
		if (binds.second == _actionType) {
			if (GameObject* gameObject = static_cast<GameObject*>(_ctx)) {
				if (gameObject) {

					gameObject->GetInputController()->AddInputsAction(
						new InputAction(binds.first, binds.second),
						_func
					);

				}
			}
		}
	}
}
