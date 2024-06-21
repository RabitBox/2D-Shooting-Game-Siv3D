#pragma once
#include "IFactory.h"

class GameObject;

class GameMainFactroy final : public IFactory<Game::Main::ObjectType>
{
public:
	GameMainFactroy() = default;
	~GameMainFactroy() override = default;

public:
	std::unique_ptr<GameObject> create(Game::Main::ObjectType objType) override;
};

