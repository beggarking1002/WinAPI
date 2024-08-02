#pragma once

#include "FlipbookActor.h"


class BoxCollider;

enum class PlayerState
{
	MoveGround,
	JumpFall,
};


class Player : public FlipbookActor
{
	using Super = FlipbookActor;
public:
	Player();
	virtual ~Player() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other) override;

	void SetState(PlayerState state);
	PlayerState GetState() { return _state; }

private:
	void TickInput();
	
	virtual void TickMoveGround();
	virtual void TickJumpFall();

private:
	void Jump();
	void TickGravity();
	void AdjustCollisionPos(BoxCollider* b1, BoxCollider* b2);


private:
	Flipbook* _flipbookUp = nullptr;
	Flipbook* _flipbookDown = nullptr;
	Flipbook* _flipbookLeft = nullptr;
	Flipbook* _flipbookRight = nullptr;


private:
	Vec2 _speed = {};
	int32 _gravity = 1000;

	PlayerState _state = PlayerState::JumpFall;
};

