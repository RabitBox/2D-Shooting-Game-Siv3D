﻿/**
* ボスの根幹コンポーネント
*/
#pragma once
#include "IComponent.h"

class Transform2D;

class Boss : public IComponent
{
private:
	Texture* _mainTexture = nullptr;
	Transform2D* _transform = nullptr;
	int _count;

public:
	Boss() = delete;
	Boss(GameObject* owner);
	virtual ~Boss();

public:
	/// @brief 更新
	void update() override;

	/// @brief 描画
	void draw() override;
};

