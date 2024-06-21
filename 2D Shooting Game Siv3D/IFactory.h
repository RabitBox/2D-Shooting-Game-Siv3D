#pragma once

template<typename T>
class IFactory
{
public:
	IFactory() = default;
	virtual ~IFactory() = default;

public:
	virtual std::unique_ptr<T> create() = 0;
};

