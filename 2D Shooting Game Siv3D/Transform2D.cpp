﻿#include "stdafx.h"
#include "Transform2D.h"

Transform2D::Transform2D(GameObject* owner) :
	IComponent(owner),
	_position(Vec2::Zero()),
	_velocity(Vec2::Zero()),
	_angle(0) {
	// 初期化子リストで初期化
}
