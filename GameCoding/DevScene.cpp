#include "pch.h"
#include "DevScene.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Sprite.h"
#include "Actor.h"
#include "SpriteActor.h"
#include "Player.h"
#include "Flipbook.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "CollisionManager.h"
#include "UI.h"
#include "TilemapActor.h"
#include "Tilemap.h"





DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	
	
	GET_SINGLE(ResourceManager)->LoadTexture(L"Stage01", L"Sprite\\Map\\Stage01.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Tile", L"Sprite\\Map\\tile.bmp", RGB(128, 128, 128));

	GET_SINGLE(ResourceManager)->LoadTexture(L"Sword", L"Sprite\\Item\\Sword.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Potion", L"Sprite\\UI\\Mp.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerDown", L"Sprite\\Player\\PlayerDown.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerUp", L"Sprite\\Player\\PlayerUp.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerLeft", L"Sprite\\Player\\PlayerLeft.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"PlayerRight", L"Sprite\\Player\\PlayerRight.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceManager)->LoadTexture(L"Start", L"Sprite\\UI\\Start.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Edit", L"Sprite\\UI\\Edit.bmp");
	GET_SINGLE(ResourceManager)->LoadTexture(L"Exit", L"Sprite\\UI\\Exit.bmp");

	GET_SINGLE(ResourceManager)->CreateSprite(L"Stage01", GET_SINGLE(ResourceManager)->GetTexture(L"Stage01"));
	GET_SINGLE(ResourceManager)->CreateSprite(L"TileO", GET_SINGLE(ResourceManager)->GetTexture(L"Tile"), 0, 0, 48, 48);
	GET_SINGLE(ResourceManager)->CreateSprite(L"TileX", GET_SINGLE(ResourceManager)->GetTexture(L"Tile"), 48, 0, 48, 48);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Start_Off", GET_SINGLE(ResourceManager)->GetTexture(L"Start"), 0, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Start_On", GET_SINGLE(ResourceManager)->GetTexture(L"Start"), 150, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Edit_Off", GET_SINGLE(ResourceManager)->GetTexture(L"Edit"), 0, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Edit_On", GET_SINGLE(ResourceManager)->GetTexture(L"Edit"), 150, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Exit_Off", GET_SINGLE(ResourceManager)->GetTexture(L"Exit"), 0, 0, 150, 150);
	GET_SINGLE(ResourceManager)->CreateSprite(L"Exit_On", GET_SINGLE(ResourceManager)->GetTexture(L"Exit"), 150, 0, 150, 150);

	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerUp");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveUp");
		fb->SetInfo({ texture, L"FB_MoveUp", {200, 200}, 0, 9, 1, 0.5f });
	}
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerDown");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveDown");
		fb->SetInfo({ texture, L"FB_MoveDown", {200, 200}, 0, 9, 1, 0.5f });
	}
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerLeft");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveLeft");
		fb->SetInfo({ texture, L"FB_MoveLeft", {200, 200}, 0, 9, 1, 0.5f });
	}
	{
		Texture* texture = GET_SINGLE(ResourceManager)->GetTexture(L"PlayerRight");
		Flipbook* fb = GET_SINGLE(ResourceManager)->CreateFlipbook(L"FB_MoveRight");
		fb->SetInfo({ texture, L"FB_MoveRight", {200, 200}, 0, 9, 1, 0.5f });
	}



	{
		Sprite* sprite = GET_SINGLE(ResourceManager)->GetSprite(L"Stage01");

		SpriteActor* background = new SpriteActor();	
		background->SetSprite(sprite);
		//background->SetLayer(LAYER_BACKGROUND);
		const Vec2Int size = sprite->GetSize();
		background->SetPos(Vec2(size.x / 2, size.y / 2));
		
		AddActor(background);
	}

	{
		Player* player = new Player();
		player->SetPos({ 100, 100 });

		//BoxCollider* collider = new BoxCollider();
		//collider->SetSize({ 100, 100 });
		//GET_SINGLE(CollisionManager)->AddCollider(collider);
		//player->AddComponent(collider);

		AddActor(player);
	}

	/*
	{
		Player* player = new Player();
		{
			SphereCollider* collider = new SphereCollider();
			collider->SetRadius(100);
			player->AddComponent(collider);
			GET_SINGLE(CollisionManager)->AddCollider(collider);
		}
		AddActor(player);
	}
	
	{
		Actor* player = new Actor();
		{
			SphereCollider* collider = new SphereCollider();
			collider->SetRadius(50);
			player->AddComponent(collider);
			GET_SINGLE(CollisionManager)->AddCollider(collider);
			player->SetPos({ 400, 200 });
		}
		AddActor(player);
	}
	*/

	{
		TilemapActor* actor = new TilemapActor();
		AddActor(actor);
		_tilemapActor = actor;

		{
			auto* tm = GET_SINGLE(ResourceManager)->CreateTilemap(L"Tilemap_01");
			tm->SetMapSize({ 63, 43 });
			tm->SetTileSize(48);

			_tilemapActor->SetTilemap(tm);
			_tilemapActor->SetShowDebug(true);
		}


	}





	Super::Init();


}

void DevScene::Update()
{
	Super::Update();
	

}

void DevScene::Render(HDC hdc)
{
	Super::Render(hdc);
	

}

void DevScene::Clear()
{
}

