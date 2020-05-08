#include "../defines.hpp"

if !(hasInterface) exitWith {};

[{ !isNil "nfe_rhea_init" }, {
	INFO_2("Started %1 @ %2", getText (configFile >> "CfgPatches" >> "nfe_rhea" >> "version"), time);

	[player, "", true] remoteExec ["RHEA_SERVER_fnc_loginPlayer", 2];
}] call CBA_fnc_waitUntilAndExecute;
