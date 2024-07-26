#pragma once
#include "Scene.h"

class Actor;
class GameObject;

class DevScene : public Scene
{
public:
	DevScene();
	virtual ~DevScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;


public:
	Actor* _background;
	Actor* _player;

	vector<Actor*> _actors;
};

