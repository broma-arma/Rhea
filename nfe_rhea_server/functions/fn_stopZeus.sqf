#include "../defines.hpp"

if (!isServer) exitWith {};

TRACE_1("fn_stopZeus: %1", _this);

params [["_player", objNull]];

if (!isRemoteExecuted && isMultiplayer || { isNull _player } || { _player isKindOf "HeadlessClient_F" }) exitWith {
	["nfe_rhea_zeusStopped", [1], _player] call CBA_fnc_targetEvent;
};

private _module = getAssignedCuratorLogic _player;
if (isNull _module) exitWith {
	["nfe_rhea_zeusStopped", [2], _player] call CBA_fnc_targetEvent;
};

if !(_module getVariable ["nfe_rhea_server_zeus", false]) exitWith {
	["nfe_rhea_zeusStopped", [3], _player] call CBA_fnc_targetEvent;
};

private _index = nfe_rhea_server_zeusSlots findIf { _x == _module };
if (_index != -1) then {
	["nfe_rhea_zeusStopped", [0], _player] call CBA_fnc_targetEvent;
	missionNamespace setVariable [format ["nfe_rhea_server_zeus%1", _index], objNull];
	_module removeCuratorEditableObjects [curatorEditableObjects _module, false];
};
