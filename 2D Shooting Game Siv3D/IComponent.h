/**
* コンポーネントの基本クラス
* このクラスを継承して作られたクラスをコンポーネントとして扱う。
*/
#pragma once

class IComponent
{
public:
	// 前方宣言
	class IObject;

protected:
	/// @brief 所有者
	IObject* _owner;

public:
	IComponent() = delete;
	IComponent(IObject* owner) : _owner(owner) {}
	virtual ~IComponent() = default;

public:
	/// @brief 更新処理
	virtual void update() {}
};

