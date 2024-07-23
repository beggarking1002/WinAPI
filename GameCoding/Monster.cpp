#include "pch.h"
#include "Monster.h"
#include "InputManager.h"




Monster::Monster() : Object(ObjectType::Monster)
{
}

Monster::~Monster()
{
}

void Monster::Init()
{
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 10;

	_pos = Pos{ 400, 300 };

	_lookPos = Pos{ 550, 70 };
	_lookDir = _lookPos - _pos;
	_lookDir.Normalize();
}

void Monster::Update()
{

}

void Monster::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 100);
	

	// FrontDir
	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)::SelectObject(hdc, pen);
	{
		Utils::DrawLine(hdc, _pos, _lookPos);
	}
	::SelectObject(hdc, oldPen);
	::DeleteObject(pen);

	Vector mousePos = GET_SINGLE(InputManager)->GetMousePos();
	Vector monsterToMouseDir = mousePos - _pos;
	monsterToMouseDir.Normalize();

	Vector dir = _lookDir;
	dir.Normalize();

	float dot = monsterToMouseDir.Dot(dir);
	float radian = ::acos(dot);
	float angle = radian * 180 / 3.14f;


	// 1)
	float cross = _lookDir.Cross(monsterToMouseDir);
	if (cross < 0)
		angle = 360 - angle;

	{
		wstring str = std::format(L"angle({0})", angle);
		Utils::DrawTextW(hdc, { 20, 50 }, str);

	}


}
