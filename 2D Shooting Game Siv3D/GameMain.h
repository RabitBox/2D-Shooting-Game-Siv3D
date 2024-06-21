#pragma once

class GameObject;

class GameMain
{
private:
	std::unique_ptr<GameObject> _player;

public:
	GameMain();
	~GameMain();

public:
	void Update();
	void Draw();
};

