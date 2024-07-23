#pragma once
#include "Scene.h"
class FortressScene : public Scene
{
public:
	FortressScene();
	virtual ~FortressScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};

