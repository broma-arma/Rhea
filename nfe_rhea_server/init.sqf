if (!isServer) exitWith {};

nfe_rhea_init = false;

addons_compiled = false;

fnc_createZeus = compile preprocessFileLineNumbers ("nfe_rhea_server\fnc\fnc_createZeus.sqf");

#include "userconfig.sqf"

fnc_logPlayer = compileFinal "
    _player = _this select 0;
    _pass = _this select 1;
    _allow = false;

    diag_log format [""%1 attempted to login with password %2"", _player, _pass];

    if (_pass == RHEA_password) then { _allow = true };
    if ((name _player) in (RHEA_allowed_units)) then { _allow = true };

    if (_allow) then {
        _module = [_player] call fnc_createZeus;
        _player setVariable [""isZeus"",true,true];
        _player setVariable [""zModule"",_module,true];
    };
    _player setVariable [""nfe_waiting"",false,true];
";

RheaAddons = [""];

RheaCenter = createCenter sideLogic;
RheaGroup = createGroup RheaCenter;

_cfgPatches = (configfile >> "cfgPatches");
for "_i" from 0 to (count _cfgPatches - 1) do {
    _class = _cfgPatches select _i;
    if (isClass _class) then { RheaAddons pushBack (configName _class) };
};

RheaAddons call BIS_fnc_activateAddons;

nfe_rhea_init = true;
publicVariable "nfe_rhea_init";

diag_log format ["== %1: RHEA SERVER VERSION 0.80 enabled.", time];
