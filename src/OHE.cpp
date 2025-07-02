#include "pch.h"
#include "OHE.h"

#define TeamOffset 0x238
#define playerNumberOffset 0xF0
#define healthOffset 0x4

int32_t myTeam = 5;

void __declspec(naked)OneHitEliminate()
{
	myTeam = player->varTeam;

	if (*selector != 1)
	{
		__asm
		{
			code:
				mov eax, edi //Stolen Bytes
				push ecx
				mov ecx, [myTeam]
				cmp[ebx + TeamOffset], ecx
				je returnJump
				mov ecx, [ebx + healthOffset]
				sub[ebx + healthOffset], ecx
				pop ecx
				jmp returnJump


			returnJump:
				jmp OneHitEliminateDetour.returnJumpDetour
		}
	}

	if (*selector == 1)
	{
		__asm
		{
			cod:
				mov eax, edi //Stolen Bytes

				push ecx
				cmp [ebx + playerNumberOffset], 0x0
				je returnJum
				mov ecx, [ebx + healthOffset]
				sub [ebx + healthOffset], ecx
				pop ecx
				jmp returnJum
				
			returnJum:
				jmp OneHitEliminateDetour.returnJumpDetour
		}
	}
}