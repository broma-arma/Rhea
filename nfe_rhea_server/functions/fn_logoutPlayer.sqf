#include "../defines.hpp"

if (!isServer) exitWith {};

TRACE_1("fn_logoutPlayer: %1", _this);

params [["_player", objNull]];

if (_player getVariable ["nfe_rhea_loggedIn", false]) then {
	RHEA_Channel radioChannelRemove [_player];

	_module = getAssignedCuratorLogic _player;
	if (!(isNull _module) && {_module getVariable ["RheaZeus", false]}) then {
		deleteVehicle _module;
	};

	_player setVariable ["nfe_rhea_loggedIn", false, true];
};

