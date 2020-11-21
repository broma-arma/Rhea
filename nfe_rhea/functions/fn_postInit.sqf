#include "../defines.hpp"

if !(hasInterface) exitWith {};

[{ !isNil "nfe_rhea_init" }, {
	INFO_2("Started %1 @ %2", getText (configFile >> "CfgPatches" >> "nfe_rhea" >> "versionStr"), time);

	["nfe_rhea_zeusStarted", {
		params ["_errorCode"];

		switch (_errorCode) do {
			case 0: { ["Zeus started", "FFFFFF"] call RHEA_fnc_message; };
			case 1: { "Cannot start Zeus, internal error" call RHEA_fnc_message; };
			case 2: { "Cannot start Zeus, not logged in" call RHEA_fnc_message; };
			case 3: { "Zeus already started" call RHEA_fnc_message; };
			case 4: { "Cannot start Zeus, no available slot" call RHEA_fnc_message; };
		};
	}] call CBA_fnc_addEventHandler;

	["nfe_rhea_zeusStopped", {
		params ["_errorCode"];

		switch (_errorCode) do {
			case 0: { ["Zeus stopped", "FFFFFF"] call RHEA_fnc_message; };
			case 1: { "Cannot stop Zeus, internal error" call RHEA_fnc_message; };
			case 2: { "Cannot stop Zeus, not a Zeus" call RHEA_fnc_message; };
			case 3: { "Cannot stop Zeus, not a Rhea zeus" call RHEA_fnc_message; };
		};
	}] call CBA_fnc_addEventHandler;

	[player, ""] remoteExec ["RHEA_SERVER_fnc_loginPlayer", 2];
}] call CBA_fnc_waitUntilAndExecute;
