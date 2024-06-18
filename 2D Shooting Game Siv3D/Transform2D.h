/**
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

	/// @brief 角度
	double _angle;

public:
	Transform2D() = delete;
	Transform2D(GameObject* owner);
	virtual ~Transform2D() = default;

public:
	Vec2	getPosition() { return _position; }
	void	setPosition(Vec2 position) { _position = position; }

	double	getAngle() { return _angle; }
	void	setAngle(double angle) { _angle = angle; }
};

