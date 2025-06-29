#include "pch.h"
#include "setupHooksAndNops.h"

Hook mainHackLoopTramp;
Hook OneHitEliminateDetour;
Nop nopAmmo;
Nop nopRecoil;

void SetupHooksAndNops()
{
	BYTE* moduleBaseAssaultCube = (BYTE*)GetModuleHandle(L"ac_client.exe");
	BYTE* moduleBaseOpenGl = (BYTE*)GetModuleHandle(L"opengl32.dll");

	BYTE* mainHackLoopHookDst = moduleBaseOpenGl + 0x48510;
	Hook MainHackLoopTrampTemp(mainHackLoopHookDst, (BYTE*)MainHackLoop, 5);
	mainHackLoopTramp = MainHackLoopTrampTemp;

	BYTE* OneHitEliminateDst = (moduleBaseAssaultCube + 0x29D1F);
	Hook OneHitEliminateDetourTemp(OneHitEliminateDst, (BYTE*)OneHitEliminate, 5);
	OneHitEliminateDetour = OneHitEliminateDetourTemp;

	BYTE* nopAmmoDst = moduleBaseAssaultCube + 0x637E9;
	Nop nopAmmoTemp(nopAmmoDst, 2);
	nopAmmo = nopAmmoTemp;

	//ac_client.exe+62223E 18 BYTE
	BYTE* nopRecoilDst = moduleBaseAssaultCube + 0x6223E; //Good
	Nop nopRecoilTemp(nopRecoilDst, 18);
	nopRecoil = nopRecoilTemp;
	
}