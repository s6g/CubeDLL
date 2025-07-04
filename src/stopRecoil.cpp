#include "pch.h"
#include "stopRecoil.h"

float tempX, tempY, tempZ;

void __declspec(naked)stopRecoilX()
{
	__asm
	{
		fadd dword ptr [tempX]
		fstp dword ptr [tempX]
		fadd dword ptr [tempY]
		fstp dword ptr [tempY]
		fadd dword ptr [tempZ]
		fstp dword ptr [tempZ]
		jmp stopRecoilDetour.returnJumpDetour
	}
}

