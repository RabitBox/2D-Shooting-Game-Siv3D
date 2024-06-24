#include "stdafx.h"
#include "Boss.h"
#include "Transform2D.h"
#include "TextureManager.h"

Boss::Boss(GameObject* owner)
	: IComponent(owner) {
	// 初期化子リストで初期化

	TextureManager& manager = TextureManager::GetInstance();
	manager.LoadEmoji(U"🦖");
	manager.TryGetTexture(U"🦖", _mainTexture);
	_transform = owner->getComponent<Transform2D>();

	if (_transform) {
		auto firstPos = Scene::CenterF();
		firstPos.y -= 100;
		_transform->setPosition( firstPos );
	}
}

Boss::~Boss() {

}

void Boss::update() {
	
}

void Boss::draw() {
	if (_mainTexture && _transform) {
		auto pos = _transform->getPosition();
		_mainTexture->drawAt(pos);
	}
}
