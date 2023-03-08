#pragma once
#include <SFML/Window/Keyboard.hpp>

enum class ActionType
{
	Left,
	Right,
	Fire
};

struct InputAction
{
	InputAction(sf::Keyboard::Key _key, ActionType _actionType) {
		Key = _key;
		Action = _actionType;
	}

	sf::Keyboard::Key Key;
	ActionType Action;
};