#pragma once
#include "iostream"
class PlayerInfo
{
public:
	char pad_0000[4]; //0x0000
	float HeadPosX; //0x0004
	float HeadPosY; //0x0008
	float HeadPosZ; //0x000C
	float VelocityX; //0x0010
	float VelocityY; //0x0014
	float VelocityZ; //0x0018
	int32_t MultiplierX; //0x001C
	int32_t MultiiplierY; //0x0020
	int32_t MultiplierZ; //0x0024
	float idkX; //0x0028
	float idkY; //0x002C
	float idkZ; //0x0030
	float PosX; //0x0034
	float PosY; //0x0038
	float PosZ; //0x003C
	float CamPosX; //0x0040
	float CamPosY; //0x0044
	float CamPosZ; //0x0048
	float Recoil; //0x004C
	char pad_0050[32]; //0x0050
	uint32_t isStill; //0x0070
	char pad_0074[12]; //0x0074
	uint32_t isFlying; //0x0080
	char pad_0084[8]; //0x0084
	uint32_t MovementKey; //0x008C
	char pad_0090[104]; //0x0090
	int32_t health; //0x00F8
	int32_t shield; //0x00FC
	char pad_0100[12]; //0x0100
	int32_t isAkimbo; //0x010C
	char pad_0110[4]; //0x0110
	int32_t pistolReserve; //0x0114
	char pad_0118[12]; //0x0118
	int32_t ADReserve; //0x0124
	int32_t mtpReserve; //0x0128
	char pad_012C[16]; //0x012C
	int32_t pistolAmmo; //0x013C
	char pad_0140[12]; //0x0140
	int32_t ADAmmo; //0x014C
	int32_t mtpAmmo; //0x0150
	char pad_0154[4]; //0x0154
	int32_t grenade; //0x0158
	int32_t akimboAmmo; //0x015C
	char pad_0160[20]; //0x0160
	int32_t SniperFireRate; //0x0174
	int32_t mtpFireRate; //0x0178
	char pad_017C[4]; //0x017C
	int32_t nadeFireRate; //0x0180
	int32_t akimboFireRate; //0x0184
	char pad_0188[4]; //0x0188
	int32_t mkFireRate; //0x018C
	char pad_0190[72]; //0x0190
	int32_t N000000C5; //0x01D8
	char pad_01DC[336]; //0x01DC
	int32_t varTeam; //0x032C
	char pad_0330[4532]; //0x0330
}; //Size: 0x14E4

