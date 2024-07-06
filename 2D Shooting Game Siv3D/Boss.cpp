#include "stdafx.h"
#include "Boss.h"
#include "TextureManager.h"
#include "BulletGenerator.h"

namespace {
	int count = 0;

	constexpr int INTERVAL_LINEAR = 20;
	constexpr int INTERVAL_LINEAR_R = 30;
	constexpr int INTERVAL_INVOLUTE = 20;

	const Vec2 LINEAR_BULLET_DIRS[] = {
		Vec2::Down(),
		Vec2( 0.5, 1).normalized(),
		Vec2(-0.5, 1).normalized(),
	};

	const float ROT_SCALE[] = {
		1.0f,
		-1.0f
	};
};

Boss::Boss(GameObject* owner)
	: IComponent(owner) {
	// 初期化子リストで初期化

	TextureManager& manager = TextureManager::GetInstance();
	manager.LoadEmoji(U"😈");
	manager.TryGetTexture(U"😈", _mainTexture);
	_transform = owner->getComponent<Transform2D>();

	if (_transform) {
		auto firstPos = Scene::CenterF();
		firstPos.y -= 150;
		_transform->setPosition( firstPos );
	}
}

Boss::~Boss() {

}

void Boss::update() {
	++count;

	auto pos = _transform->getPosition();

	// 3way
	if ( count % INTERVAL_LINEAR == 0 ) {
		for (int i = 0; i < 3; ++i) {
			auto firePos = pos + LINEAR_BULLET_DIRS[i] * 50.0f;
			BulletGenerator::GetInstance().fireBullet(
				_owner,
				Game::Main::BulletType::Linear,
				firePos,
				LINEAR_BULLET_DIRS[i]
			);
		}
	}

	// 回転発射弾
	if ( count % INTERVAL_LINEAR_R == 0 ) {
		
	}

	// インボリュート
	if ( count % INTERVAL_INVOLUTE == 0 ) {
		for (int i = 0; i < 2; ++i) {
			auto bullet = BulletGenerator::GetInstance().fireBullet(
				_owner,
				Game::Main::BulletType::Involute,
				pos,
				Vec2::Up()
			);
			if( !bullet ) continue;

			auto inv = bullet->getComponent<InvoluteBullet>();
			if ( !inv ) continue;

			inv->setScale(ROT_SCALE[i]);
		}
	}
}

void Boss::draw() {
	if (_mainTexture && _transform) {
		auto pos = _transform->getPosition();
		_mainTexture->drawAt(pos);
	}
}
