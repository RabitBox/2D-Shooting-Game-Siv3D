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
	void fireBullet( GameObject* owner, BulletType type, Vec2 position, Vec2 velocity );

public:
	static BulletGenerator& GetInstance() noexcept;
};

