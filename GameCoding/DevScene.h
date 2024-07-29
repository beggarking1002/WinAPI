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

	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);


public:


	vector<Actor*> _actors[LAYER_MAXCOUNT];
};

