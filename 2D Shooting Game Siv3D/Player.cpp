#include "stdafx.h"
#include "Player.h"
#include "TextureManager.h"

Player::Player(GameObject* owner)
	: IComponent(owner) {
	// 初期化子リストで初期化

	TextureManager& manager = TextureManager::GetInstance();
	manager.LoadEmoji( U"🦖" );
	manager.TryGetTexture(U"🦖", _mainTexture);
	_transform = owner->getComponent<Transform2D>();

	if ( _transform ) {
		auto firstPos = Scene::CenterF();
		firstPos.y += 100;
		_transform->setPosition( firstPos );
	}
}

Player::~Player() {

}

void Player::update() {
	int x = 0, y = 0;
	if ( KeyRight.pressed() ) {
		x += 1;
	}
	if( KeyLeft.pressed() ){
		x -= 1;
	}

	if ( KeyDown.pressed() ) {
		y += 1;
	}
	if( KeyUp.pressed() ){
		y -= 1;
	}

	if ( _transform ) {
		if ( x || y ) {
			auto vec = Vec2{ x, y }.normalized();
			_transform->addPosition( vec );
		}
	}
}

void Player::draw() {
	if ( _mainTexture && _transform ) {
		auto pos = _transform->getPosition();
		_mainTexture->resized(90).drawAt( pos );
	}
}
