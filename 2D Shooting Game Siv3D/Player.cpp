#include "stdafx.h"
#include "Player.h"
#include "GameObject.h"
#include "Transform2D.h"
#include "TextureManager.h"

Player::Player(GameObject* owner)
	: IComponent(owner) {
	// 初期化子リストで初期化

	TextureManager& manager = TextureManager::GetInstance();
	manager.LoadEmoji( U"🦖" );
	manager.TryGetTexture(U"🦖", _mainTexture);
	_transform = owner->getComponent<Transform2D>();
}

Player::~Player() {

}

void Player::update() {

}

void Player::draw() {
	if ( _mainTexture && _transform ) {
		auto pos = _transform->getPosition();
		_mainTexture->draw( pos );
	}
}
