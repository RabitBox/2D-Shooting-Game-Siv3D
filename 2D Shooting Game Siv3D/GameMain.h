#pragma once

class GameObject;
class GameMainFactroy;

class GameMain
{
private:
	std::unique_ptr<GameMainFactroy> _factory;
	std::unique_ptr<GameObject> _player;

public:
	GameMain();
	~GameMain();

public:
	void Update();
	void Draw();
};

