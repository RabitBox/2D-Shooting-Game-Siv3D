/**
* ゲームオブジェクトの基本クラス
* コンポーネントを追加することで、機能を増やしていく。
*/
#pragma once

/// @brief 基本オブジェクトインターフェース
class IObject
{
public:
	class IComponent;

protected:
	/// @brief 状態
	bool _isActive;

	/// @brief 座標
	Vec2 _position;

	/// @brief 角度
	double _angle;

	/// @brief 所有コンポーネント
	std::vector<std::unique_ptr<IComponent>> _componentList;

public:
	IObject() = default;
	virtual ~IObject() = default;

public:
	/// @brief 更新
	virtual void onUpdate() = 0;

	/// @brief 描画
	virtual void onDraw() = 0;

public:
	/// @brief コンポーネント追加
	/// @tparam T 追加したいコンポーネント
	/// @return 追加したコンポーネント
	template<class T>
	T* addComponent();

	/// @brief コンポーネント取得
	/// @tparam T 取得したいコンポーネント
	/// @return 取得したコンポーネント
	template<class T>
	T* getComponent();
};

