#include "pch.h"
#include "GetsAndInputs.h"

bool bBreakHackThreadWhileLoop = false;

void PrintConsole()
{
	system("cls");
	std::cout << "Press" << COLORS::YELLOW << " End " << COLORS::RESET << "To Detach\n";
	std::cout << "Press F1 To Infinite Ammo\n";
	std::cout << "Press F2 To No Recoil\n";
	std::cout << "------------------------------------------------------\n";
	std::cout << "Infinite Ammo: " << (nopAmmo.bActive ? COLORS::GREEN:COLORS::RED) << (nopAmmo.bActive ? "Active" : "Not Active") << COLORS::RESET << "\n";
	std::cout << "Recoil: " << (nopRecoil.bActive ? COLORS::GREEN : COLORS::RED) << (nopRecoil.bActive ? "Active" : "Not Active") << COLORS::RESET << std::endl;
	std::cout << "OHE: " << (OneHitEliminateDetour.bActive ? COLORS::GREEN : COLORS::RED) << (OneHitEliminateDetour.bActive ? "Active" : "Not Active") << COLORS::RESET << std::endl;
}

void GetInput()
{

	if (GetAsyncKeyState(VK_END) & 1)
	{
		mainHackLoopTramp.ToggleTrampSBF();
		BreakHack();
	}

	if (GetAsyncKeyState(VK_F1) & 1)
	{
		nopAmmo.ToggleNop();
		PrintConsole();
	}

	if (GetAsyncKeyState(VK_F2) & 1)
	{
		nopRecoil.ToggleNop();  //Stops Movement When Shooting
		PrintConsole();
	}

	if (GetAsyncKeyState(VK_F3) & 1)
	{
		
		OneHitEliminateDetour.ToogleDetour();
		PrintConsole();
	}

}

void BreakHack()
{
	bBreakHackThreadWhileLoop = true;
	
	if (nopAmmo.bActive) { nopAmmo.ToggleNop(); }
	if (nopRecoil.bActive) { nopRecoil.ToggleNop(); }
}

void ToggleConsole()
{

	//Create Console
	static bool bActive = false;
	static FILE* f;
	bActive = !bActive;

	if (bActive)
	{ 
		AllocConsole();
		freopen_s(&f, "CONOUT$", "w", stdout); //file pointer address, -, write permission, print output
	}

	if (!bActive)
	{
		fclose(f);
		FreeConsole();
	}
}