#pragma once

/// @brief パスで使用する文字列のエイリアス
using PathString = std::u32string;

/// @brief テクスチャのロード・アンロード・保持などの全般
class TextureManager final
{
private:
	// テクスチャキャッシュ
	std::unordered_map<PathString, Texture> _textures;

private:
	TextureManager() = default;
	~TextureManager();

public:
	/// @brief ロード済のテクスチャを取得
	///			純粋なGET関数はつくらない
	/// @param filePath ファイルパス
	/// @param outPtr テクスチャへのweak ptr
	/// @return テクスチャがロード済だったか否か
	bool TryGetTexture(const PathString& filePath, Texture& outPtr);

	/// @brief テクスチャのロード
	/// @param filePath テクスチャのファイルパス
	void LoadTexture(const PathString& filePath);

	/// @brief 絵文字のロード
	/// @param emoji 絵文字
	void LoadEmoji(const PathString& emoji);

	/// @brief テクスチャをアンロード
	/// @param filePath テクスチャのファイルパス
	void UnloadTexture(const PathString& filePath);

public:
	static TextureManager& GetInstance();
};

