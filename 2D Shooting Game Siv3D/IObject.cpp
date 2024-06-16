#include "stdafx.h"
#include "IObject.h"

template<class T>
T* IObject::addComponent() {
	_componentList.emplace_back( std::make_unique<T>( this ) );
	auto ptr = _componentList.back();
	return ptr.get();
}

template<class T>
T* IObject::getComponent() {
	for ( auto component : _componentList ) {
		auto ptr = dynamic_cast<T*>( component.get() );
		if ( ptr != nullptr ) {
			return ptr;
		}
	}
	return nullptr;
}
