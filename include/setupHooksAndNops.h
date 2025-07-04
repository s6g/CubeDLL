#pragma once
#include "Hooks.h"
#include "MainHackLoop.h"
#include "OHE.h"
#include "stopRecoil.h"

extern Hook mainHackLoopTramp;
extern Hook OneHitEliminateDetour;
extern Hook stopRecoilDetour;

extern Nop nopAmmo;
extern Nop nopRecoil[2];

void SetupHooksAndNops();