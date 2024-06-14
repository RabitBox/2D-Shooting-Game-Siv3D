#include "stdafx.h"
#include "TextureManager.h"
#include "defines.h"

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {
	_textures.clear();
}

bool TextureManager::TryGetTexture(const PathString& filePath, std::weak_ptr<Texture> outPtr) {
	auto it = _textures.find(filePath);
	if (it != _textures.end()) {
		outPtr = it->second;
		return true;
	}
	return false;
}

void TextureManager::LoadTexture(const PathString& filePath) {
	auto it = _textures.find(filePath);
	if (it != _textures.end()) {
		return;
	}

	_textures[filePath] = std::make_shared<Texture>(Texture{ filePath });
}

void TextureManager::UnloadTexture(const PathString& filePath) {
	auto it = _textures.find(filePath);
	if (it != _textures.end()) {
		_textures.erase(it);
	}
}
