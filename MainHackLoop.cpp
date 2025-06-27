#include "pch.h"
#include "MainHackLoop.h"
#include "InfAmmo.h"

bool bBreakHackThreadWhileLoop = false;

void MainHackLoop()
{
	static uintptr_t modbase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
	static uintptr_t* localplayer = (uintptr_t*)(modbase + 0x10F4F4);

	static PlayerInfo* player;
	player = reinterpret_cast<PlayerInfo*>(*localplayer);

	player->health = 7002;
	player->mtpReserve = 1000;
	player->Recoil = 0;
	player->shield = 1337;
	player->grenade = 99;


	if (GetAsyncKeyState(VK_F1) & 1)
	{
		mainHackLoopTramp.ToggleTrampSBF();
		bBreakHackThreadWhileLoop = true;
	}

	if (GetAsyncKeyState(VK_F2) & 1)
	{
		if (infAmmoDetour.bActive) { infAmmoDetour.ToogleDetour(); Sleep(1);}
		nopAmmo.ToggleNop();
		std::cout << "Nop Status: " << (nopAmmo.bActive ? "Active" : "Not Active") << std::endl;
	}
	
	if (GetAsyncKeyState(VK_F3) & 1)
	{
		if (nopAmmo.bActive) { nopAmmo.ToggleNop(); Sleep(1); }
		infAmmoDetour.ToogleDetour();
		std::cout << "Detour Status: " << (infAmmoDetour.bActive ? "Active" : "Not Active") << std::endl;
	}

	if (GetAsyncKeyState(VK_F4) & 1)
	{
		nopRecoil.ToggleNop();  //Stops Movement When Shooting
		std::cout << "Recoil Status: " << (nopRecoil.bActive ? "Active" : "Not Active") << std::endl;
	}
	
}