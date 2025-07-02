#include "pch.h"
#include "Globals.h"

uintptr_t modbase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
uintptr_t* localplayer = (uintptr_t*)(modbase + 0x10F4F4);

int* selector = (int*)(*(uintptr_t*)(*(uintptr_t*)(modbase + 0x110D04) + 0xC4C) + 0x84);

PlayerInfo* player = reinterpret_cast<PlayerInfo*>(*localplayer);

void editPlayer()
{
	player->health = 7002;
	player->mtpReserve = 1000;
	player->Recoil = 0;
	player->shield = 1337;
	player->grenade = 99;

}