// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include  <stdio.h>
#include "PlayerInfo.h"
#include "SetupHooksAndNops.h"
#include "MainHackLoop.h"


DWORD WINAPI HackThread(HMODULE hModule)
{
    //Create Console
    FILE* f;
    AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout); //file pointer address, -, write permission, print output

    SetupHooksAndNops();

    mainHackLoopTramp.ToggleTrampSBF();
    // infAmmoDetour.ToogleDetour();
    nopAmmo.ToggleNop();

    while (!bBreakHackThreadWhileLoop)
    {

    }

    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HackThread, hModule, NULL, NULL));
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

