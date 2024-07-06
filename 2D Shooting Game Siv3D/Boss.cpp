#include "stdafx.h"
#include "Boss.h"
#include "TextureManager.h"
#include "BulletGenerator.h"

namespace {
	int count = 0;

	constexpr int INTERVAL_LINEAR = 20;

	const Vec2 LINEAR_BULLET_DIRS[] = {
		Vec2::Down(),
		Vec2( 0.5, 1).normalized(),
		Vec2(-0.5, 1).normalized(),
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

	if ( count % INTERVAL_LINEAR ) {
		return;
	}

	auto pos = _transform->getPosition();

	for ( int i = 0; i < 3; ++i ) {
		auto firePos = pos + LINEAR_BULLET_DIRS[i] * 50.0f;
		BulletGenerator::GetInstance().fireBullet(
			_owner,
			Game::Main::BulletType::Linear,
			firePos,
			LINEAR_BULLET_DIRS[i]
		);
	}
	/*BulletGenerator::GetInstance().fireBullet(
		_owner,
		Game::Main::BulletType::Linear,
		pos,
		Vec2::Down()
	);*/
}

void Boss::draw() {
	if (_mainTexture && _transform) {
		auto pos = _transform->getPosition();
		_mainTexture->drawAt(pos);
	}
}
