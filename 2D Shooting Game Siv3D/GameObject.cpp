#include "stdafx.h"
#include "GameObject.h"
#include "IComponent.h"

GameObject::GameObject() : _isActive( true ) {

}

GameObject::GameObject(GameObject&& other) noexcept
	: _isActive(other._isActive)
	, _componentList(std::move(other._componentList)) {
	for (auto& component : _componentList) {
		component.get()->setOwner( this );
	}
}

GameObject& GameObject::operator=(GameObject&& other) noexcept {
	if (this != &other) {
		_isActive = other._isActive;
		_componentList = std::move(other._componentList);
	}
	for (auto& component : _componentList) {
		component.get()->setOwner( this );
	}

	return *this;
}

void GameObject::onUpdate() const {
	if ( _isActive == false ) {
		return;
	}

	for ( auto& component: _componentList ) {
		component.get()->update();
	}
}

void GameObject::onDraw() const {
	if ( _isActive == false ) {
		return;
	}

	for (auto& component : _componentList) {
		component.get()->draw();
	}
}
