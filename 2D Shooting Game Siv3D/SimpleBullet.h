#pragma once
#include "IComponent.h"

class Transform2D;

class SimpleBullet : public IComponent
{
private:
	Transform2D* _transform = nullptr;
	float _speed;

	//const Texture emoji{ U"🍥"_emoji };
	Texture* _mainTexture = nullptr;

public:
	SimpleBullet() = delete;
	SimpleBullet(GameObject* owner);
	virtual ~SimpleBullet();

public:
	/// @brief 更新
	void update() override;

	/// @brief 描画
	void draw() override;
};

