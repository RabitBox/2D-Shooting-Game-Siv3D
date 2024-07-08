#include "stdafx.h"
#include "SpiralBullet.h"
#include "TextureManager.h"

namespace {
	constexpr float ROTATE_SPEED = Math::ToRadians( 80.f / 60.f );
	constexpr float LEAVE_SPEED = 100.f / 60.f;
}

SpiralBullet::SpiralBullet(GameObject* owner)
	: IComponent(owner) {
	_transform = owner->getComponent<Transform2D>();

	if ( _transform ) {
		_startPos = _transform->getPosition();
	}

	TextureManager& manager = TextureManager::GetInstance();
	manager.LoadEmoji(U"⚽");
	manager.TryGetTexture(U"⚽", _mainTexture);
}

SpiralBullet::~SpiralBullet() {

}

void SpiralBullet::update() {
	if (!_owner->getActive()) {
		return;
	}

	// 画面外判定
	if ( _length > Scene::Width() ) {
		_owner->setActive(false);
		return;
	}

	// 座標更新
	auto newPosition = Vec2{
		_length * Math::Cos( _angle ),
		_length * Math::Sin( _angle ),
	};
	_transform->setPosition(_startPos + newPosition );

	_angle += ROTATE_SPEED * _scale;
	_length += LEAVE_SPEED;
}

void SpiralBullet::draw() {
	if (!_owner || !_owner->getActive()) {
		return;
	}

	if (!_transform) {
		return;
	}

	_mainTexture->resized(50).drawAt(_transform->getPosition());
}
