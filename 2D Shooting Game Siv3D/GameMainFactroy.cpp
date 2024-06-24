#include "stdafx.h"
#include "GameMainFactroy.h"
#include "Transform2D.h"
#include "Player.h"
#include "Boss.h"


std::unique_ptr<GameObject> GameMainFactroy::create(Game::Main::ObjectType objType) {
	using namespace Game::Main;

	std::unique_ptr<GameObject> gameObject = std::make_unique<GameObject>();

	switch (objType) {
	case ObjectType::kPlayer: {
		gameObject->addComponent<Transform2D>();
		gameObject->addComponent<Player>();
	} break;

	case ObjectType::kBoss: {
		gameObject->addComponent<Transform2D>();
		gameObject->addComponent<Boss>();
	} break;

	default: {
		return nullptr;
	} break;
	}

	return std::move( gameObject );	// 所有権を呼び出し元に渡す
}
