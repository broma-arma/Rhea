#include "../defines.hpp"

if (!isServer) exitWith {};

TRACE_1("fn_cleanup: %1", _this);

{
	{
		deleteVehicle _x;
	} forEach allMissionObjects _x;
} forEach ["WeaponHolder", "WeaponHolderSimulated", "CraterLong"];

if !(isNil "ace_medical_allCreatedLitter") then {
	// ACE3 <= 3.12.6
	{
		_x params ["_time", "_objects"];

		{
			deleteVehicle _x;
		} forEach _objects;
	} forEach ace_medical_allCreatedLitter;
	ace_medical_allCreatedLitter = [];
};

if !(isNil "ace_medical_treatment_litterObjects") then {
	// ACE3 >= 3.13.0
	{
		_x params ["_object", "_timeCreated"];

		deleteVehicle _object;
	} forEach ace_medical_treatment_litterObjects;
	ace_medical_treatment_litterObjects = [];
};
