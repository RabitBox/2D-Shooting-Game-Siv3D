#include "stdafx.h"
#include "SimpleBullet.h"

SimpleBullet::SimpleBullet(GameObject* owner)
	: _speed( 1.0f ), IComponent(owner) {
	_transform = owner->getComponent<Transform2D>();
}

SimpleBullet::~SimpleBullet() {

}

void SimpleBullet::update() {
	if ( !_owner->getActive() ) {
		return;
	}

	// 画面外判定
	if ( _transform->isOutOfScreen() ) {
		_owner->setActive( false );
		return;
	}

	// 座標更新
	auto dir = _transform->getDirection();
	_transform->addPosition( dir * _speed );
}

void SimpleBullet::draw() {
	if ( !_owner || !_owner->getActive() ) {
		return;
	}

	if ( !_transform ) {
		return;
	}

	emoji.resized(50).drawAt( _transform->getPosition() );
}
