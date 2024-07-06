#include "stdafx.h"
#include "BulletGenerator.h"
#include "Bullet.h"
#include "SimpleBullet.h"

namespace {
	constexpr int MAX = 100;
}

BulletGenerator::BulletGenerator() {
	// 弾の最大数を予め定義
	_bulletList.reserve( MAX );
}

BulletGenerator::~BulletGenerator() {
	// 要素を全て削除
	_bulletList.clear();
}

GameObject* BulletGenerator::fireBullet(
	GameObject* owner,
	BulletType type,
	Vec2 position,
	Vec2 direction ) {
	// 容量を超えるかどうかをチェック
	if (_bulletList.size() >= _bulletList.capacity()) {
		// 容量を超える場合は追加しない
		return nullptr;
	}

	// 基本オブジェクト
	
	_bulletList.emplace_back();
	auto& bulletObj = _bulletList.back();

#pragma region 基本コンポーネントのセットアップ
	// トランスフォーム
	auto transform = bulletObj.addComponent<Transform2D>();
	if (transform) {
		transform->setPosition( position );
		transform->setDirection( direction );
	}
	// 弾
	auto bullet = bulletObj.addComponent<Bullet>();
	if (bullet) {
		bullet->setBulletOwner( owner );
	}
#pragma endregion

	// 追加のコンポーネントセットアップ
	switch ( type )
	{
	case BulletType::Linear: {
		bulletObj.addComponent<SimpleBullet>();
	} break;
	default:
		break;
	}

	// 作成したデータを呼び出し元に渡す
	return &bulletObj;
}

void BulletGenerator::eraseInactives() {
	for (auto itr = _bulletList.begin(); itr != _bulletList.end(); ) {
		if ( itr->getActive() == false ) {
			itr = _bulletList.erase( itr );
		}
		else {
			++itr;
		}
	}
}

void BulletGenerator::update() {
	for ( auto& obj : _bulletList ) {
		obj.onUpdate();
	}
}

void BulletGenerator::draw() {
	for ( auto& obj : _bulletList ) {
		obj.onDraw();
	}
}

BulletGenerator& BulletGenerator::GetInstance() noexcept {
	static BulletGenerator instance;
	return instance;
}
