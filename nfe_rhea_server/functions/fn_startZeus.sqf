#include "../defines.hpp"

if !(isServer) exitWith {};

TRACE_1("fn_startZeus: %1", _this);

params [["_player", objNull]];

if (isNull _player || { _player isKindOf "HeadlessClient_F" }) exitWith {
	["nfe_rhea_zeusStarted", [1], _player] call CBA_fnc_targetEvent;
};

if (!(_player getVariable ["nfe_rhea_loggedIn", false])) exitWith {
	["nfe_rhea_zeusStarted", [2], _player] call CBA_fnc_targetEvent;
};

if (!isNull getAssignedCuratorLogic _player) exitWith {
	["nfe_rhea_zeusStarted", [3], _player] call CBA_fnc_targetEvent;
};

private _index = nfe_rhea_server_zeusSlots findIf { isNull getAssignedCuratorUnit _x };
if (_index != -1) then {
	["nfe_rhea_zeusStarted", [0], _player] call CBA_fnc_targetEvent;
	_player assignCurator (nfe_rhea_server_zeusSlots select _index);
	missionNamespace setVariable [format ["nfe_rhea_server_zeus%1", _index], _player];
	_player setVariable ["nfe_rhea_server_zeus", _index];
} else {
	["nfe_rhea_zeusStarted", [4], _player] call CBA_fnc_targetEvent;
};
