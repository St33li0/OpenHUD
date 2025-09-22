#pragma once

#include "struct.c"
#include "data.c"

/* Return 1 if _piSelect is set, from 0 to _iNumVehicles - 1 */
__declspec(dllexport) int SpectateVehicles(int _iNumVehicles,void *_pVehicleData,int _iCurSelection,int *_piSelect)
{

	pasVehicleData = (SPluginsSpectateVehicle_t*)_pVehicleData;

	return 0;
}

/* Return 1 if _piSelect is set, from 0 to _iNumCameras - 1 */
__declspec(dllexport) int SpectateCameras(int _iNumCameras,void *_pCameraData,int _iCurSelection,int *_piSelect)
{
	int i;

	pszCameraName = (char*)_pCameraData;
	for (i=0; i < _iNumCameras; i++)
	{
		pszCameraName += strlen(pszCameraName)+1;
	}

	return 0;
}