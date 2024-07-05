#pragma once
#include "IComponent.h"

class Bullet final : public IComponent
{
public:
	using TypeID = Game::Main::TypeID;

private:
	TypeID _type;
	GameObject* _bulletOwner;

public:
	Bullet() = delete;
	Bullet(GameObject* owner);
	virtual ~Bullet() = default;

public:
	/// @brief 更新
	void update() override {}

	/// @brief 描画
	void draw() override {}

public:
	TypeID getTypeID() const noexcept { return _type; }
	void setTypeID(TypeID type) noexcept { _type = type; }

	GameObject* getBulletOwner() const noexcept { return _bulletOwner; }
	void setBulletOwner(GameObject* owner) noexcept { _bulletOwner = owner; }
};

