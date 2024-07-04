#include "stdafx.h"
#include "GameObject.h"
#include "IComponent.h"

GameObject::GameObject(GameObject&& other) noexcept
	: _isActive(other._isActive)
	, _componentList(std::move(other._componentList)) {
}

void GameObject::onUpdate() {
	for ( auto& component: _componentList ) {
		component.get()->update();
	}
}

void GameObject::onDraw() {
	for (auto& component : _componentList) {
		component.get()->draw();
	}
}
