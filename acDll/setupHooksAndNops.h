#pragma once
#include "Hooks.h"
#include "MainHackLoop.h"

extern Hook mainHackLoopTramp;
extern Hook infAmmoDetour;
extern Nop nopAmmo;

void SetupHooksAndNops();