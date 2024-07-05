#pragma once

class GameObject;

class BulletGenerator final
{
public:
	using BulletType = Game::Main::BulletType;

private:
	std::vector<GameObject> _bulletList;

public:
	BulletGenerator();
	virtual ~BulletGenerator();

public:
	/// @brief 弾を打つ
	/// @param owner 弾を発射したオーナーオブジェクト
	/// @param type 発射する弾の種類
	/// @param position 発射位置
	/// @param direction 発射方向
	GameObject* fireBullet( GameObject* owner, BulletType type, Vec2 position, Vec2 direction );

	/// @brief 非アクティブの弾をすべて削除する
	void eraseInactives();

public:
	void update();
	void draw();

public:
	static BulletGenerator& GetInstance() noexcept;
};

