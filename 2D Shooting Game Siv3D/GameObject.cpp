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

template<class T>
T* GameObject::addComponent() {
	_componentList.emplace_back( std::make_unique<T>( this ) );
	auto ptr = _componentList.back();
	return ptr.get();
}

template<class T>
T* GameObject::getComponent() {
	for ( auto component : _componentList ) {
		auto ptr = dynamic_cast<T*>( component.get() );
		if ( ptr != nullptr ) {
			return ptr;
		}
	}
	return nullptr;
}
