#include "stdafx.h"
#include "GameMain.h"
#include "GameObject.h"
#include "IComponent.h"
#include "GameMainFactroy.h"
#include "Transform2D.h"
#include "Player.h"

GameMain::GameMain() {
	_factory = std::make_unique<GameMainFactroy>();

	_player = std::make_unique<GameObject>();/*_factory->create( Game::Main::ObjectType::kPlayer );*/
	_player->addComponent<Transform2D>();
	_player->addComponent<Player>();
}

GameMain::~GameMain() {

}

void GameMain::Update() {
	if ( _player ) _player->onUpdate();
}

void GameMain::Draw() {
	if ( _player ) _player->onDraw();
}
