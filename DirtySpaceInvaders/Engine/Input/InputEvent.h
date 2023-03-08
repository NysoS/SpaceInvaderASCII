#pragma once
#include <functional>

class InputEvent {

public:
	InputEvent();
	~InputEvent();

	enum EventType
	{
		None,
		Close,
		KeyPressed
	};

	EventType Type;
	char Key;

	template<typename T>
	void BindInput(T* ctx, void(T::* callback)(float), float value);
};

template<typename T>
inline void InputEvent::BindInput(T* ctx, void(T::* callback)(float), float value)
{
	auto call = std::bind(callback, ctx, std::placeholders::_1);
	call(value);
}
