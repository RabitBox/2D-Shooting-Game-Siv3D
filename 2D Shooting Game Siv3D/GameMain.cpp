#include "stdafx.h"
#include "GameMain.h"
#include "GameObject.h"
#include "IComponent.h"

GameMain::GameMain() {

}

GameMain::~GameMain() {

}

void GameMain::Update() {
	if ( _player ) _player->onUpdate();
}

void GameMain::Draw() {
	if ( _player ) _player->onDraw();
}
