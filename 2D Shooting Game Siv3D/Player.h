#pragma once
#include "IComponent.h"

class Player final: public IComponent
{
public:
	Player() = delete;
	Player(GameObject* owner);
	virtual ~Player();
};

