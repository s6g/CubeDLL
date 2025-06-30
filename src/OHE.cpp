#include "pch.h"
#include "OHE.h"

#define Team 0x238
#define playerNumber 0xF0

int myTeam = 5;
int harvestDone = 0;

/*
This function changes the in-game damage function to force one-hit eliminations on enemies
while ignoring teammates by hooking the original damage calculation
and modifying the health subtraction logic conditionally

The damaged player’s pointer is passed in through the EBX register
detailed explaination below
*/

void __declspec(naked)OneHitEliminate()
{
	__asm
	{
	code:
		mov eax,edi //stolen Bytes

		cmp [ebx + playerNumber], 0x0 //am i me?
		je teamcheck //if yes, check whats my team
		jne cont //if not continue the function as is

	teamcheck:
		push ecx //using this register cuz itts nott ussed anywheree
		mov ecx, [ebx + Team] //take  my team, 
		cmp ecx, [myTeam] //and compare it with the global variable
		pop ecx //thank you
		jne harvest //if it doesnt equal, meaning we didnt check your team before

	cont:
		cmp [harvestDone], 0x1 //did we confirm whats MY team?
		je oneHit //if yes, ONESHOT the enemies
		jne normal //if not, continue the function as is

	oneHit:
		push ecx  //using this register cuz itts nott ussed anywheree
		mov ecx, [myTeam] //Take my team (it'll be either 0 or 1... we initialized to 5 cuz it doesnt exist)
		cmp [ebx + Team], ecx  //compare the player team with mine
		pop ecx //thank you
		je returnJump //if he IS in my team, Jump Back (dont subtract)
		push ecx //appparently he's not
		mov ecx, [ebx + 0x4] //take his health
		sub [ebx + 0x4], ecx //subtract his health by his health -> 0
		pop ecx//thank you
		jmp returnJump //Jump Back

	normal:
		sub [ebx + 0x4], edi  //stolen byte (normal function)
		jmp returnJump //JumpBack

	harvest:
		push ecx //yk why
		mov ecx, [ebx + Team] //take my team
		mov [myTeam], ecx //and put it in the global variable :D we're checked now
		mov [harvestDone], 0x1 //further confirming we're checked, not necessary can be removed
		pop ecx //thank you
		jmp cont //now go back

	returnJump:	
		jmp OneHitEliminateDetour.returnJumpDetour // A JUMP to the normal flow of execution
	}
}