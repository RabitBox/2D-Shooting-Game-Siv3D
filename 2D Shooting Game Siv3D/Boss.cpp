#include "stdafx.h"
#include "Boss.h"
#include "TextureManager.h"
#include "BulletGenerator.h"

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
	auto pos = _transform->getPosition();
	BulletGenerator::GetInstance().fireBullet(
		_owner,
		Game::Main::BulletType::Linear,
		pos,
		Vec2::Down()
	);
}

void Boss::draw() {
	if (_mainTexture && _transform) {
		auto pos = _transform->getPosition();
		_mainTexture->drawAt(pos);
	}
}
