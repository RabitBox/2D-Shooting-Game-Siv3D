#pragma once

/// @brief 基本オブジェクトインターフェース
class IObject
{
protected:
	/// @brief 座標
	Vec2 _position;

	/// @brief 角度
	double _angle;

public:
	IObject() = default;
	virtual ~IObject() {}

public:
	/// @brief 更新
	virtual void Update() = 0;

	/// @brief 描画
	virtual void Draw() = 0;
};

