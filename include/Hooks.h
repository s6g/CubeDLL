#pragma once
#include <iostream>
struct Hook
{

	//hook Head
	BYTE* hookPosition{ nullptr };
	BYTE stolenBytes[20]{ 0 };
	int lengthOfHook;
	bool bActive = false;

	//hook Body
	BYTE* desiredFunction{ nullptr };
	DWORD hookToTrampJump;
	DWORD trampToFuncCall;
	DWORD returnJump;

	BYTE* trampoline{ nullptr };
	BYTE preserveStack[2]{ 0x60, 0x9C };
	BYTE releaseStack[2]{ 0x9D, 0x61 };
	bool bTrampBuilt = false;

	DWORD hookToDetourJump;
	DWORD returnJumpDetour;


	void ToggleTrampSBF();
	void ToggleTrampSBL();
	void ToogleDetour();

	Hook(BYTE* hookPosition, BYTE* desiredFunction, int lengthOfHook);
	Hook();
	~Hook();
	
};

struct Nop
{
	BYTE* nopPosition{ nullptr };
	int length{ 0 };
	BYTE stolenBytes[30]{ 0 };

	bool bActive = false;

	void ToggleNop();

	Nop(BYTE* nopPosition, int length);
	Nop();
};
