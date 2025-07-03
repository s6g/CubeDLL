#include "pch.h"
#include "GetsAndInputs.h"

bool bBreakHackThreadWhileLoop = false;

void PrintConsole()
{
	system("cls");
	std::cout << "Press" << COLORS::YELLOW << " End " << COLORS::RESET << "To Detach\n";
	std::cout << "Press F1 To Infinite Ammo\n";
	std::cout << "Press F2 To No Recoil\n";
	std::cout << "Press F3 To OneHit Enemies\n";
	std::cout << "Press F4 To FULL Everything\n";
	std::cout << "------------------------------------------------------\n";
	std::cout << "Infinite Ammo: " << (nopAmmo.bActive ? COLORS::GREEN:COLORS::RED) << (nopAmmo.bActive ? "Active" : "Not Active") << COLORS::RESET << "\n";
	std::cout << "Recoil: " << (nopRecoil.bActive ? COLORS::GREEN : COLORS::RED) << (nopRecoil.bActive ? "Active" : "Not Active") << COLORS::RESET << std::endl;
	std::cout << "OHE: " << (OneHitEliminateDetour.bActive ? COLORS::GREEN : COLORS::RED) << (OneHitEliminateDetour.bActive ? "Active" : "Not Active") << COLORS::RESET << std::endl;
	std::cout << "selector: " << *selector;
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
		noprecoil.ToggleNop();
		PrintConsole();
	}

	if (GetAsyncKeyState(VK_F3) & 1)
	{
		OneHitEliminateDetour.ToogleDetour();
		PrintConsole();
	}

	if (GetAsyncKeyState(VK_F4) & 1)
	{
		editPlayer();
		PrintConsole();
	}
	
}

void BreakHack()
{
	bBreakHackThreadWhileLoop = true;
	
	if (nopAmmo.bActive) { nopAmmo.ToggleNop(); }
	if (nopRecoil.bActive) { nopRecoil.ToggleNop(); }
	if (OneHitEliminateDetour.bActive) { OneHitEliminateDetour.ToogleDetour(); }
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
		SetConsoleTitleA("yolk");
	}

	if (!bActive)
	{
		fclose(f);
		FreeConsole();
	}
}