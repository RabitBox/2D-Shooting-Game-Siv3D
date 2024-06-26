#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(GameObject* owner)
	: IComponent(owner),
	_type(TypeID::None){
	// 初期化子リストで初期化
}
