#pragma once
#include "Hooks.h"
#include "MainHackLoop.h"
#include "OHE.h"

extern Hook mainHackLoopTramp;
extern Hook OneHitEliminateDetour;
extern Nop nopAmmo;
extern Nop nopRecoil[2];

void SetupHooksAndNops();