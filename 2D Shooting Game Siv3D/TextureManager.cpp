#include "stdafx.h"
#include "TextureManager.h"

TextureManager::~TextureManager() {
	// 中身をすべて放棄し、デストラクタを呼ばせる
	_textures.clear();
}

bool TextureManager::TryGetTexture(const PathString& filePath, Texture*& outPtr) {
	auto it = _textures.find(filePath);
	if (it != _textures.end()) {
		outPtr = &it->second;
		return true;
	}
	return false;
}

void TextureManager::LoadTexture(const PathString& filePath) {
	auto it = _textures.find(filePath);
	if (it != _textures.end()) {
		return;
	}

	_textures[filePath] = Texture{ filePath };
}

void TextureManager::LoadEmoji(const PathString& emoji) {
	auto it = _textures.find(emoji);
	if (it != _textures.end()) {
		return;
	}

	_textures[emoji] = Texture{ Emoji(emoji.c_str()) };
}

void TextureManager::UnloadTexture(const PathString& filePath) {
	auto it = _textures.find(filePath);
	if (it != _textures.end()) {
		_textures.erase(it);
	}
}

TextureManager& TextureManager::GetInstance() {
	static TextureManager instance;
	return instance;
}
