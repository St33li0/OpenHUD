#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#include "debug.c"

#include "struct.c"
#include "data.c"
#include "time.c"
#include "func.c"

__declspec(dllexport) char *GetModID()
{
	return "mxbikes";
}

__declspec(dllexport) int GetModDataVersion()
{
	return 8;
}

__declspec(dllexport) int GetInterfaceVersion()
{
	return 9;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    // No special actions needed on DLL load/unload
    return TRUE;
}

/* called when software is started */
__declspec(dllexport) int Startup(char *_szSavePath)
{
	if (DEBUG) {
		InitDebugConsole();
		printf("[%S] Plugin started. Save path: %s\n", GetShortTimeString(time(NULL)), _szSavePath);
	}

	// 0 = 100hz; 1 = 50hz; 2 = 20hz; 3 = 10hz; -1 = disable
	return 1;
}

/* called when software is closed */
__declspec(dllexport) void Shutdown()
{
	if (DEBUG) printf("Shutting down and closing debug console.\n");
	CloseConsole();
}

/* called when event is initialized. This function is optional */
__declspec(dllexport) void EventInit(void *_pData,int _iDataSize)
{
	if (DEBUG) printf("[%s] EventInit called.\n", GetShortTimeString(time(NULL)));
	psEventData = (SPluginsBikeEvent_t*)_pData;
}

/* called when event is closed. This function is optional */
__declspec(dllexport) void EventDeinit()
{
	if (DEBUG) printf("[%s] EventDeinit called.\n", GetShortTimeString(time(NULL)));
}


/* called when bike goes to track. This function is optional */
__declspec(dllexport) void RunInit(void *_pData,int _iDataSize)
{
	if (DEBUG) printf("[%s] RunInit called.\n", GetShortTimeString(time(NULL)));
	psSessionData = (SPluginsBikeSession_t*)_pData;
}

/* called when bike leaves the track. This function is optional */
__declspec(dllexport) void RunDeinit()
{
	if (DEBUG) printf("[%s] RunDeinit called.\n", GetShortTimeString(time(NULL)));
}

/* called when simulation is started / resumed. This function is optional */
__declspec(dllexport) void RunStart()
{
	if (DEBUG) printf("[%s] RunStart called.\n", GetShortTimeString(time(NULL)));
}

/* called when simulation is paused. This function is optional */
__declspec(dllexport) void RunStop()
{
	if (DEBUG) printf("[%s] RunStop called.\n", GetShortTimeString(time(NULL)));
}

/* called when a new lap is recorded. This function is optional */
__declspec(dllexport) void RunLap(void *_pData,int _iDataSize)
{
	if (EXTRA_DEBUG) printf("[%s] RunLap called.\n", GetShortTimeString(time(NULL)));
	psLapData = (SPluginsBikeLap_t*)_pData;
}

/* called when a split is crossed. This function is optional */
__declspec(dllexport) void RunSplit(void *_pData,int _iDataSize)
{
	if (EXTRA_DEBUG) printf("[%s] RunSplit called.\n", GetShortTimeString(time(NULL)));
	psSplitData = (SPluginsBikeSplit_t*)_pData;
}

/* _fTime is the ontrack time, in seconds. _fPos is the position on centerline, from 0 to 1. This function is optional */
__declspec(dllexport) void RunTelemetry(void *_pData,int _iDataSize,float _fTime,float _fPos)
{
	psBikeData = (SPluginsBikeData_t*)_pData;
}

/* 
called when software is started.
Set _piNumSprites to the number of zero-separated filenames in _pszSpriteName.
Set _piNumFonts to the number of zero-separated filenames in _pszFontName.
The base path for the sprite and font files is the plugins folder.
This function is optional
*/
__declspec(dllexport) int DrawInit(int *_piNumSprites,char **_pszSpriteName,int *_piNumFonts,char **_pszFontName)
{
	/*
	return 0 if pointers are set
	*/
	return -1;
}

/*
_iState: 0 = on track; 1 = spectate; 2 = replay.
Set _piNumQuads to the number of quads to draw.
Set _ppQuad to an array of SPluginQuad_t structures.
Set _piNumString to the number of strings to draw.
Set _ppString to an array of SPluginString_t structures.
This function is optional
*/
__declspec(dllexport) void Draw(int _iState,int *_piNumQuads,void **_ppQuad,int *_piNumString,void **_ppString)
{
	*_piNumQuads = 0;
	*_piNumString = 0;
}

/*
_pRaceData is a pointer to a float array with the longitudinal position of the start / finish line, splits and holeshot.
This function is optional
*/
__declspec(dllexport) void TrackCenterline(int _iNumSegments,SPluginsTrackSegment_t *_pasSegment,void *_pRaceData)
{
	
}

/* called when event is initialized or a replay is loaded. This function is optional */
__declspec(dllexport) void RaceEvent(void *_pData,int _iDataSize)
{
	psRaceEvent = (SPluginsRaceEvent_t*)_pData;
}

/* called when event is closed. This function is optional */
__declspec(dllexport) void RaceDeinit()
{
}

/* This function is optional */
__declspec(dllexport) void RaceAddEntry(void *_pData,int _iDataSize)
{
	psRaceAddEntry = (SPluginsRaceAddEntry_t*)_pData;
}

/* This function is optional */
__declspec(dllexport) void RaceRemoveEntry(void *_pData,int _iDataSize)
{
	psRaceRemoveEntry = (SPluginsRaceRemoveEntry_t*)_pData;
}

/* This function is optional */
__declspec(dllexport) void RaceSession(void *_pData,int _iDataSize)
{
	psRaceSession = (SPluginsRaceSession_t*)_pData;
}

/* This function is optional */
__declspec(dllexport) void RaceSessionState(void *_pData,int _iDataSize)
{
	psRaceSessionState = (SPluginsRaceSessionState_t*)_pData;
}

/* This function is optional */
__declspec(dllexport) void RaceLap(void *_pData,int _iDataSize)
{
	psRaceLap = (SPluginsRaceLap_t*)_pData;
}

/* This function is optional */
__declspec(dllexport) void RaceSplit(void *_pData,int _iDataSize)
{
	psRaceSplit = (SPluginsRaceSplit_t*)_pData;
}

/* This function is optional */
__declspec(dllexport) void RaceHoleshot(void *_pData,int _iDataSize)
{
	psRaceHoleshot = (SPluginsRaceHoleshot_t*)_pData;
}

/* This function is optional */
__declspec(dllexport) void RaceCommunication(void *_pData,int _iDataSize)
{
	psRaceCommunication = (SPluginsRaceCommunication_t*)_pData;
}

/* The number of elements of _pArray if given by m_iNumEntries in _pData. This function is optional */
__declspec(dllexport) void RaceClassification(void *_pData,int _iDataSize,void *_pArray,int _iElemSize)
{
	psRaceClassification = (SPluginsRaceClassification_t*)_pData;
	pasRaceClassificationEntry = (SPluginsRaceClassificationEntry_t*)_pArray;
}

/* This function is optional */
__declspec(dllexport) void RaceTrackPosition(int _iNumVehicles,void *_pArray,int _iElemSize)
{
	pasRaceTrackPosition = (SPluginsRaceTrackPosition_t*)_pArray;
}

/* This function is optional */
__declspec(dllexport) void RaceVehicleData(void *_pData,int _iDataSize)
{
	psRaceVehicleData = (SPluginsRaceVehicleData_t*)_pData;
}