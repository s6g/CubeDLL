#include "pch.h"
#include "setupHooksAndNops.h"

Hook mainHackLoopTramp;
Hook OneHitEliminateDetour;
Hook stopRecoilDetour;
Nop nopAmmo;
Nop nopRecoil[2];


void SetupHooksAndNops()
{
	BYTE* moduleBaseAssaultCube = (BYTE*)GetModuleHandle(L"ac_client.exe");
	BYTE* moduleBaseOpenGl = (BYTE*)GetModuleHandle(L"opengl32.dll");

	BYTE* mainHackLoopHookDst = moduleBaseOpenGl + 0x48510;
	Hook MainHackLoopTrampTemp(mainHackLoopHookDst, (BYTE*)MainHackLoop, 5);
	mainHackLoopTramp = MainHackLoopTrampTemp;

	BYTE* OneHitEliminateDst = moduleBaseAssaultCube + 0x29D1F;
	Hook OneHitEliminateDetourTemp(OneHitEliminateDst, (BYTE*)OneHitEliminate, 5);
	OneHitEliminateDetour = OneHitEliminateDetourTemp;

	BYTE* stopRecoilDst = moduleBaseAssaultCube + 0x6223E;
	Hook stopRecoilTempX(stopRecoilDst, (BYTE*)stopRecoilX, 18);
	stopRecoilDetour = stopRecoilTempX;

	BYTE* nopAmmoDst = moduleBaseAssaultCube + 0x637E9;
	Nop nopAmmoTemp(nopAmmoDst, 2);
	nopAmmo = nopAmmoTemp;

	BYTE* nopRecoilDst = moduleBaseAssaultCube + 0x6370D; 
	Nop nopRecoilTemp(nopRecoilDst, 3);
	nopRecoil[0] = nopRecoilTemp;
		
	BYTE* noprecoilDst = moduleBaseAssaultCube + 0x5BAB6; 
	Nop noprecoilTemp(noprecoilDst, 2);
	nopRecoil[1] = noprecoilTemp;

}