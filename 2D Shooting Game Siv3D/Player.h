/**
* プレイヤーキャラの根幹コンポーネント
* プレイヤーキャラの根幹制御
*/
#pragma once
#include "IComponent.h"

class Transform2D;

/// @brief プレイヤーコンポーネント
class Player final : public IComponent
{
private:
	Texture* _mainTexture = nullptr;
	Transform2D* _transform = nullptr;

public:
	Player() = delete;
	Player(GameObject* owner);
	virtual ~Player();

public:
	/// @brief 更新
	void update() override;

	/// @brief 描画
	void draw() override;
};

