#pragma once

class BulletGenerator final
{
public:
	BulletGenerator();
	virtual ~BulletGenerator();

public:
	void fire( Vec2 position, double angle );
};

