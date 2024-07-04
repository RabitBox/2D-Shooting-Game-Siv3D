#include "stdafx.h"
#include "BulletGenerator.h"
#include "Bullet.h"

namespace {
	constexpr int MAX = 256;
}

BulletGenerator::BulletGenerator() {
	_bulletList.reserve( MAX );	// 弾の最大数を予め定義
}

BulletGenerator::~BulletGenerator() {

}

void BulletGenerator::fireBullet( GameObject* owner, BulletType type, Vec2 position, Vec2 velocity ) {
	// 容量を超えるかどうかをチェック
	if (_bulletList.size() >= _bulletList.capacity()) {
		// 容量を超える場合は追加しない
		return;
	}

	// 基本オブジェクト
	GameObject bulletObj;

#pragma region 基本コンポーネントのセットアップ
	// トランスフォーム
	auto transform = bulletObj.addComponent<Transform2D>();
	if (transform) {
		transform->setPosition( position );
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

	} break;
	default:
		break;
	}

	// moveでデータを移動し、弾初期化を完了
	_bulletList.push_back( std::move(bulletObj) );
}

BulletGenerator& BulletGenerator::GetInstance() noexcept {
	static BulletGenerator instance;
	return instance;
}
