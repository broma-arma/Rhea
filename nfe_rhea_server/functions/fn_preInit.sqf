#include "../defines.hpp"

if (!isServer) exitWith {};

TRACE_1("fn_preInit: %1", _this);

private _addons = [];
private _cfgPatches = configFile >> "cfgpatches";
for "_i" from 0 to (count _cfgPatches - 1) do {
	_class = _cfgPatches select _i;
	if (isClass _class) then {_addons pushBack configname _class;};
};
_addons call BIS_fnc_activateAddons;
