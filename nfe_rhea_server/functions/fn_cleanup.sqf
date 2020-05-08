#include "../defines.hpp"

if (!isServer) exitWith {};

TRACE_1("fn_cleanup: %1)", _this);

{
	{
		deleteVehicle _x;
	} forEach allMissionObjects _x;
} forEach ["WeaponHolder", "WeaponHolderSimulated", "CraterLong"];

if !(isNil "ace_medical_allCreatedLitter") then {
	{
		_x params ["_time", "_objects"];

		{
			deleteVehicle _x;
		} forEach _objects;
	} forEach ace_medical_allCreatedLitter;
	ace_medical_allCreatedLitter = [];
};
