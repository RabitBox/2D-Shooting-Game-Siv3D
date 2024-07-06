/**
* ゲームオブジェクトの基本クラス
* コンポーネントを追加することで、機能を増やしていく
*/
#pragma once

class IComponent;

/// @brief 基本オブジェクト
class GameObject final
{
protected:
	/// @brief 状態
	bool _isActive;

	/// @brief 所有コンポーネント
	std::vector<std::unique_ptr<IComponent>> _componentList;

public:
	GameObject();
	virtual ~GameObject() = default;

	// コピーコンストラクタとコピー代入演算子を削除
	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;

	// ムーブコンストラクタ
	GameObject(GameObject&& other) noexcept;

	// ムーブ代入演算子
	GameObject& operator=(GameObject&& other) noexcept;

public:
	/// @brief 更新
	void onUpdate() const;

	/// @brief 描画
	void onDraw() const;

public:
	bool getActive() const noexcept { return _isActive; }
	void setActive(bool active) noexcept { _isActive = active; };

public:
	/// @brief コンポーネント追加
	/// @tparam T 追加したいコンポーネント型
	/// @return 追加したコンポーネント
	template<class T>
	T* addComponent() {
		_componentList.emplace_back(std::make_unique<T>(this));
		auto& ptr = _componentList.back();
		return  dynamic_cast<T*>( ptr.get() );
	}

	/// @brief コンポーネント取得
	/// @tparam T 取得したいコンポーネント型
	/// @return 取得したコンポーネント
	template<class T>
	T* getComponent() {
		for (auto& component : _componentList) {
			auto ptr = dynamic_cast<T*>(component.get());
			if (ptr != nullptr) {
				return ptr;
			}
		}
		return nullptr;
	}

	/// @brief コンポーネント取得　なければ追加する
	/// @tparam T 取得したいコンポーネント型
	/// @return 取得したコンポーネント
	template<class T>
	T* requireComponent() {
		T* tmp = getComponent<T>();
		return (tmp != nullptr)
			? tmp
			: addComponent<T>();
	}

	/// @brief コンポーネントの全放棄
	void clearComponent() { _componentList.clear(); }
};

