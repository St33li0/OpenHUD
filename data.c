#pragma once

#include "struct.c"

/*
    Global Structure Pointers
*/

SPluginsBikeEvent_t *psEventData;
SPluginsBikeSession_t *psSessionData;
SPluginsBikeLap_t *psLapData;
SPluginsBikeSplit_t *psSplitData;
SPluginsBikeData_t *psBikeData;
SPluginsRaceEvent_t *psRaceEvent;
SPluginsRaceAddEntry_t *psRaceAddEntry;
SPluginsRaceRemoveEntry_t *psRaceRemoveEntry;
SPluginsRaceSession_t *psRaceSession;
SPluginsRaceSessionState_t *psRaceSessionState;
SPluginsRaceLap_t *psRaceLap;
SPluginsRaceSplit_t *psRaceSplit;
SPluginsRaceHoleshot_t *psRaceHoleshot;
SPluginsRaceCommunication_t *psRaceCommunication;
SPluginsRaceClassification_t *psRaceClassification;
SPluginsRaceClassificationEntry_t *pasRaceClassificationEntry;
SPluginsRaceTrackPosition_t *pasRaceTrackPosition;
SPluginsRaceVehicleData_t *psRaceVehicleData;

/*
    Replay Structure Pointers
*/

SPluginsSpectateVehicle_t *pasVehicleData;
char *pszCameraName;