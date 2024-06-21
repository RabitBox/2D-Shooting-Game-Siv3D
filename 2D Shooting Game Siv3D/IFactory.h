#pragma once

class GameObject;

template<typename T>
class IFactory
{
public:
	IFactory() = default;
	virtual ~IFactory() = default;

public:
	virtual std::unique_ptr<GameObject> create(T objType) = 0;
};

