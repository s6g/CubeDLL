#include "pch.h"
#include "MainHackLoop.h"

void MainHackLoop()
{
	static uintptr_t modbase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
	static uintptr_t* localplayer = (uintptr_t*)(modbase + 0x10F4F4);

	static PlayerInfo* player;
	player = reinterpret_cast<PlayerInfo*>(*localplayer);

	//player->health = 7002;
	//player->mtpReserve = 1000;
	//player->Recoil = 0;
	//player->shield = 1337;
	//player->grenade = 99;

	GetInput();
}