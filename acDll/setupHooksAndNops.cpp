#include "pch.h"
#include "setupHooksAndNops.h"
#include "InfAmmo.h"

Hook mainHackLoopTramp;
Hook infAmmoDetour;
Nop nopAmmo;
Nop nopRecoil;
Nop nopHardCoil;
Nop nopReCoil;

void SetupHooksAndNops()
{
	BYTE* moduleBaseAssaultCube = (BYTE*)GetModuleHandle(L"ac_client.exe");
	BYTE* moduleBaseOpenGl = (BYTE*)GetModuleHandle(L"opengl32.dll");

	BYTE* mainHackLoopHookDst = moduleBaseOpenGl + 0x48510;
	Hook MainHackLoopTrampTemp(mainHackLoopHookDst, (BYTE*)MainHackLoop, 5);
	mainHackLoopTramp = MainHackLoopTrampTemp;

	BYTE* infAmmoDetourDst = moduleBaseAssaultCube + 0x637E6;
	Hook infAmmoDetourTemp(infAmmoDetourDst, (BYTE*)InfAmmo, 5);
	infAmmoDetour = infAmmoDetourTemp;

	BYTE* nopAmmoDst = moduleBaseAssaultCube + 0x637E9;
	Nop nopAmmoTemp(nopAmmoDst, 2);
	nopAmmo = nopAmmoTemp;

	//ac_client.exe+62223E 18 BYTE
	BYTE* nopRecoilDst = moduleBaseAssaultCube + 0x6223E;
	Nop nopRecoilTemp(nopRecoilDst, 18);
	nopRecoil = nopRecoilTemp;

	//ac_client.exe+621E4 3 BYTE
	BYTE* nopHardCoilDst = moduleBaseAssaultCube + 0x621E4;
	Nop nopHardCoilTemp(nopHardCoilDst, 3);
	nopHardCoil = nopHardCoilTemp;

	//ac_client.exe+622AC 3 BYTE
	BYTE* nopReCoilDst = moduleBaseAssaultCube + 0x622AC;
	Nop nopReCoilTemp(nopReCoilDst, 3);
	nopReCoil = nopReCoilTemp;
	//ac_client.exe+29D1F GODMODE
}