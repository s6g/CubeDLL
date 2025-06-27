#include "pch.h"
#include "InfAmmo.h"
#include "setupHooksAndNops.h"

void __declspec(naked)InfAmmo()
{
	__asm
	{
		mov esi, [esi + 0x14]
		inc[esi]
		jmp infAmmoDetour.returnJumpDetour
	}
}
