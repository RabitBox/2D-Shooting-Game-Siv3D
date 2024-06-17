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
	/// @brief 更新処理
	virtual void update() {}
};

