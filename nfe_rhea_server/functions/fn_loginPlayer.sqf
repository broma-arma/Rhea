#include "../defines.hpp"

if !(isServer) exitWith { false };

TRACE_1("fn_loginPlayer: %1", _this);

params [["_player", objNull], ["_pass", ""], ["_autoLogin", false]];

if (isNull _player || _player isKindOf "HeadlessClient_F") exitWith { false };

#include "\userconfig\rhea\serverconfig.sqf"
params ["_password", "_steamIDs", "_loggedAdmins", "_votedAdmins"];

if (_loggedAdmins) then { _loggedAdmins = (admin (owner _player)) == 2 };
if (_votedAdmins) then { _votedAdmins = (admin (owner _player)) == 1 };

private _isServer = (player == _player);
private _isMissionMaker = if (!(isNil "mission_author_name")) then { (name _player) in mission_author_name } else { false };

if (
        _isServer ||
        _loggedAdmins ||
        _votedAdmins ||
        (_pass == _password) ||
        (_autoLogin && ((getPlayerUID _player) in _steamIDs)) ||
        _isMissionMaker
    ) then {
	RHEA_Channel radioChannelAdd [_player];
	_player setVariable ["nfe_rhea_loggedIn", true, true];
};

_player setVariable ["nfe_rhea_waiting", false, true];

true
