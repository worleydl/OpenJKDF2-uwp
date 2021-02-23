#ifndef _SITHSOUNDSYS_H
#define _SITHSOUNDSYS_H

#include "types.h"

#define sithSoundSys_Startup_ADDR (0x004DAE00)
#define sithSoundSys_Shutdown_ADDR (0x004DAE40)
#define sithSoundSys_PlaySong_ADDR (0x004DAE60)
#define sithSoundSys_StopSong_ADDR (0x004DAF20)
#define sithSoundSys_UpdateMusicVolume_ADDR (0x004DAF40)
#define sithSoundSys_SetMusicVol_ADDR (0x004DB080)
#define sithSoundSys_ResumeMusic_ADDR (0x004DB0F0)
#define sithSoundSys_sub_4DB180_ADDR (0x004DB180)
#define sithSoundSys_sub_4DB230_ADDR (0x004DB230)
#define sithSoundSys_sub_4DB340_ADDR (0x004DB340)
#define sithSoundSys_StopAll_ADDR (0x004DB3C0)
#define sithSoundSys_ResumeAll_ADDR (0x004DB410)
#define sithSoundSys_sub_4DB460_ADDR (0x004DB460)
#define sithSoundSys_cog_playsound_internal_ADDR (0x004DB4F0)
#define sithSoundSys_PlaySoundPosFollowsThing_ADDR (0x004DB880)
#define sithSoundSys_PlaySoundPosAbsolute_ADDR (0x004DBA60)
#define sithSoundSys_sub_4DBF40_ADDR (0x004DBF40)
#define sithSoundSys_sub_4DBF90_ADDR (0x004DBF90)
#define sithSoundSys_SetPitch_ADDR (0x004DC070)
#define sithSoundSys_SetFrequency_ADDR (0x004DC110)
#define sithSoundSys_FadeSound_ADDR (0x004DC170)
#define sithSoundSys_sub_4DC280_ADDR (0x004DC280)
#define sithSoundSys_sub_4DC2F0_ADDR (0x004DC2F0)
#define sithSoundSys_sound_idk2_ADDR (0x004DC750)
#define sithSoundSys_sub_4DC790_ADDR (0x004DC790)
#define sithSoundSys_sub_4DCC00_ADDR (0x004DCC00)
#define sithSoundSys_sub_4DCE10_ADDR (0x004DCE10)
#define sithSoundSys_StopSound_ADDR (0x004DCE80)
#define sithSoundSys_FreeThing_ADDR (0x004DCF20)
#define sithSoundSys_GetSoundFromRef_ADDR (0x004DD040)
#define sithSoundSys_sub_4DD190_ADDR (0x004DD190)
#define sithSoundSys_sub_4DD310_ADDR (0x004DD310)
#define sithSoundSys_SectorSound_ADDR (0x004DD330)
#define sithSoundSys_SyncSounds_ADDR (0x004DD360)
#define sithSoundSys_sub_4DD3C0_ADDR (0x004DD3C0)
#define sithSoundSys_sub_4DD3F0_ADDR (0x004DD3F0)
#define sithSoundSys_sub_4DD5D0_ADDR (0x004DD5D0)

enum SITHSOUNDFLAG
{
    SITHSOUNDFLAG_LOOP = 0x1,
    SITHSOUNDFLAG_FADING = 0x2,
    SITHSOUNDFLAG_AMBIENT_NOPAN = 0x4,
    SITHSOUNDFLAG_8 = 0x8,
    SITHSOUNDFLAG_10 = 0x10,
    SITHSOUNDFLAG_20 = 0x20,
    SITHSOUNDFLAG_ABSOLUTE = 0x40,
    SITHSOUNDFLAG_FOLLOWSTHING = 0x80,
    SITHSOUNDFLAG_HIGHPRIO = 0x100,
    SITHSOUNDFLAG_NOOVERRIDE = 0x10000,
};

typedef struct sithPlayingSound
{
    LPDIRECTSOUNDBUFFER field_0;
    int anonymous_0;
    int vtable;
    int flags;
    int anonymous_3;
    float vol_2;
    int anonymous_5;
    int anonymous_6;
    int anonymous_7;
    float volume_interpolation_idk;
    float volume;
    float pitch;
    int anonymous_11;
    int anonymous_12;
    int anonymous_13;
    int anonymous_14;
    int anonymous_15;
    int anonymous_16;
    int anonymous_17;
    int anonymous_18;
    int anonymous_19;
    int anonymous_20;
    int refid;
} sithPlayingSound;

static int (*sithSoundSys_PlaySong)(unsigned int trackTo, unsigned int trackFrom, unsigned int trackNum, int a4) = (void*)sithSoundSys_PlaySong_ADDR;
static void (*sithSoundSys_UpdateMusicVolume)(float musicVolume) = (void*)sithSoundSys_UpdateMusicVolume_ADDR;
static void (*sithSoundSys_FreeThing)(sithThing *thing) = (void*)sithSoundSys_FreeThing_ADDR;
static sithPlayingSound* (*sithSoundSys_PlaySoundPosAbsolute)(sithSound *a1, sithThing *a2, float a3, float a4, float a5, int a6) = (void*)sithSoundSys_PlaySoundPosAbsolute_ADDR;
static sithPlayingSound* (*sithSoundSys_PlaySoundPosFollowsThing)(sithSound *a1, rdVector3 *a2, sithSector *a3, float a4, float a5, float a6, int a7) = (void*)sithSoundSys_PlaySoundPosFollowsThing_ADDR;
static sithPlayingSound* (*sithSoundSys_cog_playsound_internal)(sithSound *a1, float a2, float a3, int a4) = (void*)sithSoundSys_cog_playsound_internal_ADDR;
static void (*sithSoundSys_StopSong)() = (void*)sithSoundSys_StopSong_ADDR;
static int (*sithSoundSys_StopSound)(sithPlayingSound *a1) = (void*)sithSoundSys_StopSound_ADDR;
static sithPlayingSound* (*sithSoundSys_GetSoundFromRef)(int a1) = (void*)sithSoundSys_GetSoundFromRef_ADDR;
static void (*sithSoundSys_FadeSound)(sithPlayingSound *sound, float vol_, float fadeintime_) = (void*)sithSoundSys_FadeSound_ADDR;
static void (*sithSoundSys_SetPitch)(sithPlayingSound *a1, float pitch, float changetime) = (void*)sithSoundSys_SetPitch_ADDR;
static void (*sithSoundSys_SectorSound)(sithSector *a1, sithSound *a2, float a3) = (void*)sithSoundSys_SectorSound_ADDR;
static void (*sithSoundSys_SetMusicVol)(float a1) = (void*)sithSoundSys_SetMusicVol_ADDR;

#endif // _SITHSOUNDSYS_H