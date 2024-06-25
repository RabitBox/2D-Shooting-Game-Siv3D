#pragma once
#include "IComponent.h"

class Transform2D;

class SimpleBullet : public IComponent
{
private:
	//Texture* _mainTexture = nullptr;
	Transform2D* _transform = nullptr;
	float _speed = 0.0f;

public:
	SimpleBullet() = delete;
	SimpleBullet(GameObject* owner, float speed);
	virtual ~SimpleBullet();

public:
	/// @brief 更新
	void update() override;

	/// @brief 描画
	void draw() override;
};

