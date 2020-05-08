#include "../defines.hpp"

if !(isServer) exitWith {};

TRACE_1("fn_postInit: %1", _this);

activateAddons ("true" configClasses (configFile >> "CfgPatches") apply { configName _x });

RHEA_Channel = radioChannelCreate [[1, 0, 0, 1], "RHEA", "%UNIT_NAME: ", [], false];

addMissionEventHandler ["HandleDisconnect", {
	params ["_unit", "_id", "_uid", "_name"];
	if (_unit getVariable ["nfe_rhea_loggedIn", false]) then {
		_unit call RHEA_SERVER_fnc_logoutPlayer;
	};
}];

INFO_2("Started %1 @ %2", getText (configFile >> "CfgPatches" >> "nfe_rhea_server" >> "version"), time);

nfe_rhea_init = true;
publicVariable "nfe_rhea_init";
