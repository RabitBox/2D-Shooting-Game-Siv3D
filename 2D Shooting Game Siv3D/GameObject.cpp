#include "stdafx.h"
#include "GameObject.h"

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
