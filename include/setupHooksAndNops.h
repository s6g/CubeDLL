#pragma once
#include "Hooks.h"
#include "MainHackLoop.h"

extern Hook mainHackLoopTramp;
extern Nop nopAmmo;

extern Nop nopRecoil;

void SetupHooksAndNops();