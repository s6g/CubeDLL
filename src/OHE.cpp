#include "pch.h"
#include "OHE.h"

#define Team 0x238
#define playerNumber 0xF0
#define health 0x3E8

int myTeam = 5;
int harvestDone = 0;

void __declspec(naked)OneHitEliminate()
{
	__asm
	{
	code:
		mov eax,edi //stolen Bytes

		cmp [ebx + playerNumber], 0x0 //am i me?
		je teamcheck //yes, check whats my team
		jne cont //if not continue the function as is

	teamcheck:
		push ecx //using this register cuz itts nott ussed anywheree
		mov ecx, [ebx + Team] //take  my team, 
		cmp ecx, [myTeam] //and compare it with the global variable
		pop ecx //thank you
		jne harvest //if it doesnt equal, meaning we didnt check your team before

	cont:
		cmp [harvestDone], 0x1
		je oneHit
		jne normal

	oneHit:
		push ecx
		mov ecx, [myTeam]
		cmp [ebx + Team], ecx
		pop ecx
		je returnJump
		push ecx
		mov ecx, [ebx + 0x4]
		sub [ebx + 0x4], ecx
		pop ecx
		jmp returnJump //Jump Back

	normal:
		sub [ebx + 0x4], edi
		jmp returnJump //JumpBack

	harvest:
		push ecx //yk why
		mov ecx, [ebx + Team] //take my team
		mov [myTeam], ecx //and put it in the global variable :D we're check now
		mov [harvestDone], 0x1 //further confirming we're checked, not necessary can be removed
		pop ecx //thank you
		jmp cont //now go back

	returnJump:	
		jmp OneHitEliminateDetour.returnJumpDetour
	}
}