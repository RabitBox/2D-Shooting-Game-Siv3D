﻿/**
* 2D トランスフォームコンポーネント
* ２次元上の座標と角度を取り扱う
*/
#pragma once
#include "IComponent.h"

/// @brief 2Dトランスフォームコンポーネント
class Transform2D final : public IComponent
{
private:
	/// @brief 座標
	Vec2 _position;

	/// @brief ベクトル
	Vec2 _direction;

	/// @brief 角度
	double _angle;

public:
	Transform2D() = delete;
	Transform2D(GameObject* owner);
	virtual ~Transform2D() = default;

public:
	/// @brief 更新
	void update() override {}

	/// @brief 描画
	void draw() override {}

public:
	Vec2	getPosition() const noexcept { return _position; }
	void	setPosition(const Vec2& position) noexcept { _position = position; }
	void	addPosition(const Vec2& position) noexcept { _position += position; }

	Vec2	getDirection() const noexcept { return _direction; }
	void	setDirection(const Vec2& direction) noexcept { _direction = direction; }

	double	getAngle() const noexcept { return _angle; }
	void	setAngle(const double angle) noexcept { _angle = angle; }
	void	addAngle(const double angle) noexcept { _angle += angle; }

public:
	/// @brief 座標が画面外か
	/// @return 画面外ならtrue
	bool isOutOfScreen();
};

