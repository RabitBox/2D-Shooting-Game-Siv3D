#pragma once

/// @brief テクスチャのロード・アンロード・保持などの全般
class TextureManager final
{
private:
	// テクスチャキャッシュ
	std::unordered_map<FilePath, Texture> _textures;

private:
	TextureManager() = default;
	~TextureManager();

public:
	/// @brief ロード済のテクスチャを取得
	///			純粋なGET関数はつくらない
	/// @param filePath ファイルパス
	/// @param outPtr テクスチャへのweak ptr
	/// @return テクスチャがロード済だったか否か
	bool TryGetTexture(const FilePath& filePath, Texture*& outPtr);

	/// @brief テクスチャのロード
	/// @param filePath テクスチャのファイルパス
	void LoadTexture(const FilePath& filePath);

	/// @brief 絵文字のロード
	/// @param emoji 絵文字
	void LoadEmoji(const FilePath& emoji);

	/// @brief テクスチャをアンロード
	/// @param filePath テクスチャのファイルパス
	void UnloadTexture(const FilePath& filePath);

public:
	static TextureManager& GetInstance();
};

