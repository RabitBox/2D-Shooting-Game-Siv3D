#include "stdafx.h"
#include "Boss.h"
#include "TextureManager.h"
#include "BulletGenerator.h"

namespace {
	constexpr int INTERVAL_LINEAR = 25;
	constexpr int INTERVAL_LINEAR_R = 20;
	constexpr int INTERVAL_INVOLUTE = 20;
	constexpr int INTERVAL_SPIRAL = 80;

	const Vec2 LINEAR_BULLET_DIRS[] = {
		Vec2::Down(),
		Vec2( 0.5, 1).normalized(),
		Vec2(-0.5, 1).normalized(),
	};

	const float ROT_SCALE[] = {
		1.0f,
		-1.0f
	};

	enum Phase {
		PHASE_1,
		PHASE_2,
		PHASE_3,
		PHASE_4,
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

	_count = 0;
	_phase = 0;
}

Boss::~Boss() {

}

void Boss::update() {
	static int fireCount = 0;
	auto pos = _transform->getPosition();
	++_count;

	switch (_phase)
	{
	case Phase::PHASE_1: {
		// 3way
		if (_count % INTERVAL_LINEAR == 0) {
			++fireCount;
			attack3WayBullet( pos );
			if ( fireCount > 8 ) {
				_phase++;
				fireCount = 0;
			}
		}
	} break;

	case Phase::PHASE_2: {
		// 回転発射弾
		if (_count % INTERVAL_LINEAR_R == 0) {
			++fireCount;
			attackCircle4Bullet(pos);
			if (fireCount > 8) {
				_phase++;
				fireCount = 0;
			}
		}
	} break;

	case Phase::PHASE_3: {
		// インボリュート
		if (_count % INTERVAL_INVOLUTE == 0) {
			++fireCount;
			attackInvoluteBullet( pos );
			if (fireCount > 8) {
				_phase++;
				fireCount = 0;
			}
		}
	} break;

	case Phase::PHASE_4: {
		// 渦巻き弾
		if (_count % INTERVAL_SPIRAL == 0) {
			++fireCount;
			attackSpiralBullet(pos);
			if (fireCount > 8) {
				_phase++;
				fireCount = 0;
			}
		}
	} break;
	default:
		_phase = 0;
		break;
	}
}

void Boss::draw() {
	if (_mainTexture && _transform) {
		auto pos = _transform->getPosition();
		_mainTexture->drawAt(pos);
	}
}

void Boss::attack3WayBullet( Vec2 position ) {
	for (int i = 0; i < 3; ++i) {
		auto firePos = position + LINEAR_BULLET_DIRS[i] * 50.0f;
		BulletGenerator::GetInstance().fireBullet(
			_owner,
			Game::Main::BulletType::Linear,
			firePos,
			LINEAR_BULLET_DIRS[i]
		);
	}
}

void Boss::attackCircle4Bullet( Vec2 position ){
	auto baseAngle = 1.4f * _count;
	float ANGLES[] = {
		baseAngle, baseAngle + 180.f,
		-baseAngle, -(baseAngle + 180.f),
	};

	for ( int i = 0; i < 4; ++i ) {
		auto rad = Math::ToRadians(ANGLES[i]);
		Vec2 dir = Vec2{ Math::Sin(rad), Math::Cos(rad)};
		auto firePos = position + dir * 50.0f;
		BulletGenerator::GetInstance().fireBullet(
			_owner,
			Game::Main::BulletType::Linear,
			firePos,
			dir
		);
	}
}

void Boss::attackInvoluteBullet(Vec2 position) {
	for (int i = 0; i < 2; ++i) {
		auto bullet = BulletGenerator::GetInstance().fireBullet(
			_owner,
			Game::Main::BulletType::Involute,
			position,
			Vec2::Up()
		);
		if( !bullet ) continue;

		auto inv = bullet->getComponent<InvoluteBullet>();
		if ( !inv ) continue;

		inv->setScale(ROT_SCALE[i]);
	}
}

void Boss::attackSpiralBullet( Vec2 position ){
	const int COUNT = 8;
	const float ANGLE = 360.f / COUNT;
	for (int i = 0; i < COUNT; ++i ) {
		auto bullet = BulletGenerator::GetInstance().fireBullet(
			_owner,
			Game::Main::BulletType::Spiral,
			position,
			Vec2::Up()
		);
		if ( bullet ) {
			bullet->getComponent<SpiralBullet>()->setStartAngle( i * ANGLE );
		}
	}

	for (int i = 0; i < COUNT; ++i) {
		auto bullet = BulletGenerator::GetInstance().fireBullet(
			_owner,
			Game::Main::BulletType::Spiral,
			position,
			Vec2::Up()
		);
		if (bullet) {
			auto spiral = bullet->getComponent<SpiralBullet>();
			spiral->setStartAngle(i * ANGLE);
			spiral->setSpeedScale( -1.0f );
		}
	}
}
