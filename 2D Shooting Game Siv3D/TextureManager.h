#pragma once

/// @brief パスで使用する文字列のエイリアス
using PathString = std::u32string;

/// @brief テクスチャのロード・アンロード・保持などの全般
class TextureManager final
{
private:
	// テクスチャキャッシュ
	std::unordered_map<std::u32string, std::shared_ptr<Texture>> _textures;

public:
	TextureManager();
	~TextureManager() {}

	/// @brief ロード済のテクスチャを取得
	///			純粋なGET関数はつくらない
	/// @param filePath ファイルパス
	/// @param outPtr テクスチャへのweak ptr
	/// @return テクスチャがロード済だったか否か
	bool TryGetTexture(const PathString& filePath, std::weak_ptr<Texture> outPtr);

	/// @brief テクスチャのロード
	/// @param filePath テクスチャのファイルパス
	void LoadTexture(const PathString& filePath);

	/// @brief テクスチャをアンロード
	/// @param filePath テクスチャのファイルパス
	void UnloadTexture(const PathString& filePath);
};

