#include "../defines.hpp"

if !(isServer) exitWith {};

TRACE_1("fn_logoutPlayer: %1", _this);

params [["_player", objNull]];

if (_player getVariable ["nfe_rhea_loggedIn", false]) then {
	RHEA_Channel radioChannelRemove [_player];

	private _module = getAssignedCuratorLogic _player;
	if (!isNull _module && { _module getVariable ["nfe_rhea_server_zeus", false] }) then {
		private _index = nfe_rhea_server_zeusSlots findIf { _x == _module };
		if (_index != -1) then {
			missionNamespace setVariable [format ["nfe_rhea_server_zeus%1", _index], objNull];
			_module removeCuratorEditableObjects [curatorEditableObjects _module, false];
		};
	};

	_player setVariable ["nfe_rhea_loggedIn", false, true];
};
