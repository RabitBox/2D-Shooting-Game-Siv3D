#pragma once
#include "IComponent.h"

class Player final: public IComponent
{
public:
	Player() = delete;
	Player(GameObject* owner);
	virtual ~Player();

public:
	/// @brief 更新処理
	void update() override;
};

