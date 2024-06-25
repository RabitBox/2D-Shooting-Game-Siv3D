#include "stdafx.h"
#include "SimpleBullet.h"

SimpleBullet::SimpleBullet(GameObject* owner, float speed)
	: _speed( speed ), IComponent(owner) {
	_transform = owner->getComponent<Transform2D>();
}

SimpleBullet::~SimpleBullet() {

}

void SimpleBullet::update() {

}

void SimpleBullet::draw() {
	
}
