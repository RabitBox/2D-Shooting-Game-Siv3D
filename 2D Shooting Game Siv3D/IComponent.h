/**
* コンポーネントの基本クラス
* このクラスを継承して作られたクラスをコンポーネントとして扱う。
*/
#pragma once

// 前方宣言
class GameObject;

class IComponent
{
protected:
	/// @brief 所有者
	GameObject* _owner;

public:
	IComponent() = delete;
	IComponent(GameObject* owner) : _owner(owner) {}
	virtual ~IComponent() = default;

public:
	/// @brief 更新
	virtual void update() {}

	/// @brief 描画
	virtual void draw() {}

public:
	/// @brief 所有者のメモリを再セットする
	/// @param owner 新しい所有者へのポインタ
	void setOwner(GameObject* const owner) noexcept { _owner = owner; }
};

