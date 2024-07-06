#include "stdafx.h"
#include "InvoluteBullet.h"
#include "TextureManager.h"

namespace {
	constexpr float BASE_RADIUS = 20.f;

};

InvoluteBullet::InvoluteBullet(GameObject* owner)
	: IComponent(owner) {
	_transform = owner->getComponent<Transform2D>();

	_startPos = _transform->getPosition();
	_time = 3.0f;
	_scale = 1.0f;

	TextureManager& manager = TextureManager::GetInstance();
	manager.LoadEmoji(U"🍘");
	manager.TryGetTexture(U"🍘", _mainTexture);
}

InvoluteBullet::~InvoluteBullet() {

}

void InvoluteBullet::update() {
	if ( !_owner->getActive() ) {
		return;
	}

	// 画面外判定
	if ( _time > 40.f ) {
		_owner->setActive( false );
		return;
	}

	// 座標更新
	auto pos = calculatePosition( _time );
	pos.x *= _scale;
	_transform->setPosition( _startPos + pos );
	_time += 0.05f;
}

void InvoluteBullet::draw() {
	if ( !_owner || !_owner->getActive() ) {
		return;
	}

	if ( !_transform ) {
		return;
	}

	_mainTexture->resized(50).drawAt( _transform->getPosition() );
}

Vec2 InvoluteBullet::calculatePosition(float t) const {
	float x = BASE_RADIUS * (cos(t) + t * sin(t));
	float y = BASE_RADIUS * (sin(t) - t * cos(t));
	return Vec2{ x, y };
}
