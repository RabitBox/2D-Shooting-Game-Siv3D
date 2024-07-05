#include "stdafx.h"
#include "Transform2D.h"

Transform2D::Transform2D(GameObject* owner) :
	IComponent(owner),
	_position(Vec2::Zero()),
	_angle(0) {
	// 初期化子リストで初期化
}

bool Transform2D::isOutOfScreen() {
	// 横座標が画面外か
	if ( _position.x < 0 || _position.x > Scene::Width() ) {
		return true;
	}
	// 縦座標が画面外か
	if ( _position.y < 0 || _position.y > Scene::Height() ) {
		return true;
	}
	return false;
}
