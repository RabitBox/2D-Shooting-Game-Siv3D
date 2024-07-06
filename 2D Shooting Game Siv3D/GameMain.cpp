﻿#include "stdafx.h"
#include "GameMain.h"
#include "GameObject.h"
#include "IComponent.h"
#include "GameMainFactroy.h"
#include "Transform2D.h"
#include "Player.h"
#include "BulletGenerator.h"

GameMain::GameMain() {
	_factory = std::make_unique<GameMainFactroy>();

	_player = _factory->create( Game::Main::ObjectType::kPlayer );
	_boss = _factory->create( Game::Main::ObjectType::kBoss );
}

GameMain::~GameMain() {

}

void GameMain::Update() {
	BulletGenerator::GetInstance().eraseInactives();

	if ( _player ) _player->onUpdate();
	if ( _boss ) _boss->onUpdate();
	BulletGenerator::GetInstance().update();
}

void GameMain::Draw() {
	if ( _player ) _player->onDraw();
	if ( _boss ) _boss->onDraw();
	BulletGenerator::GetInstance().draw();
}
