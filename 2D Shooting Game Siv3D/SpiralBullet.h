#pragma once
#include "IComponent.h"

class Transform2D;

class SpiralBullet : public IComponent
{
private:
	Transform2D* _transform = nullptr;
	Texture* _mainTexture = nullptr;

	Vec2	_startPos = Vec2::Zero();
	float	_angle = 0.0f;
	float	_length = 0.0f;
	float	_scale = 1.0f;

public:
	SpiralBullet() = delete;
	SpiralBullet(GameObject* owner);
	virtual ~SpiralBullet();

public:
	/// @brief 更新
	void update() override;

	/// @brief 描画
	void draw() override;

public:
	void setStartAngle(float angle) { _angle = Math::ToRadians(angle); }
	void setSpeedScale(float scale) { _scale = scale; }
};

