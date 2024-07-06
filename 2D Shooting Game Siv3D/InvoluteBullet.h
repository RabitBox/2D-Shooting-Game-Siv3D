#pragma once
#include "IComponent.h"

class Transform2D;

class InvoluteBullet : public IComponent
{
private:
	Transform2D* _transform = nullptr;
	Texture* _mainTexture = nullptr;
	Vec2 _startPos;
	float _time;
	float _scale;

public:
	InvoluteBullet() = delete;
	InvoluteBullet(GameObject* owner);
	virtual ~InvoluteBullet();

public:
	/// @brief 更新
	void update() override;

	/// @brief 描画
	void draw() override;

	void setScale(float scale) { _scale = scale; }

private:
	Vec2 calculatePosition(float t) const;
};

