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

nfe_rhea_server_zeusSlots = [];
for "_i" from 0 to nfe_rhea_zeusCount - 1 do {
	// Note: Created group will be deleted in moduleInit.
	private _module = createGroup sideLogic createUnit ["ModuleCurator_F", [0, 0, 0], [], 0, "CAN_COLLIDE"];
	private _varName = format ["nfe_rhea_server_zeus%1", _i];
	missionNamespace setVariable [_varName, objNull];
	_module setVariable ["owner", _varName];
	//_module setVariable ["Addons", 2]; // Default 2
	//_module setVariable ["forced", 0]; // Default 0
	//_module setVariable ["name", ""]; // Default "" (localize "STR_A3_curator")
	//_module setVariable ["channels", []]; // Default []
	_module setVariable ["showNotification", false]; // Default true
	_module setVariable ["birdType", ""]; // Default "eagle_f"

	_module setVariable ["nfe_rhea_server_zeus", true];

	_module setCuratorWaypointCost 0;
	_module allowCuratorLogicIgnoreAreas true;
	_module setCuratorCameraAreaCeiling 50000;
	//_module addCuratorEditableObjects [(vehicles + allUnits), true];
	{ _module setCuratorCoef [_x, 0]; } forEach ["place", "edit", "delete", "destroy", "group", "synchronize"];

	_module setVariable ["bis_fnc_initModules_activate", true];

	nfe_rhea_server_zeusSlots pushBack _module;
};

publicVariable "RHEA_REMOTE_fnc_teleport";

INFO_2("Started %1 @ %2", getText (configFile >> "CfgPatches" >> "nfe_rhea_server" >> "versionStr"), time);

nfe_rhea_init = true;
publicVariable "nfe_rhea_init";
