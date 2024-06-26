#include "stdafx.h"
#include "BulletGenerator.h"

BulletGenerator::BulletGenerator() {

}

BulletGenerator::~BulletGenerator() {

}

void BulletGenerator::fireBullet( GameObject* owner, BulletType type, Vec2 position, Vec2 velocity ) {

}

BulletGenerator& BulletGenerator::GetInstance() noexcept {
	static BulletGenerator instance;
	return instance;
}
