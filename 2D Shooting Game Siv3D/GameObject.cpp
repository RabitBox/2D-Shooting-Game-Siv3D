#include "stdafx.h"
#include "GameObject.h"
#include "IComponent.h"

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
