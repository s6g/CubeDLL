#include "pch.h"
#include "setupHooksAndNops.h"
#include "InfAmmo.h"

Hook mainHackLoopTramp;
Hook infAmmoDetour;
Nop nopAmmo;

void SetupHooksAndNops()
{
	BYTE* moduleBaseAssaultCube = (BYTE*)GetModuleHandle(L"ac_client.exe");
	BYTE* moduleBaseOpenGl = (BYTE*)GetModuleHandle(L"opengl32.dll");

	BYTE* mainHackLoopHookDst = moduleBaseOpenGl + 0x48510;
	Hook MainHackLoopTrampTemp(mainHackLoopHookDst, (BYTE*)MainHackLoop, 5);
	mainHackLoopTramp = MainHackLoopTrampTemp;

	/*BYTE* infAmmoDetourDst = moduleBaseAssaultCube + 0x637E6;
	Hook infAmmoDetourTemp(infAmmoDetourDst, (BYTE*)InfAmmo, 5);
	infAmmoDetour = infAmmoDetourTemp;*/

	BYTE* nopAmmoDst = moduleBaseAssaultCube + 0x637E9;
	Nop nopAmmoTemp(nopAmmoDst, 2);
	nopAmmo = nopAmmoTemp;
}