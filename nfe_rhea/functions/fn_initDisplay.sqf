#include "../defines.hpp"

TRACE_1("fn_initDisplay: %1", _this);

params ["_display"];

_display displayAddEventHandler ["KeyDown", {
	params ["_display", "_key", "_shift", "_ctrl", "_alt"];

	if (isNil "nfe_rhea_init") exitWith { false };

	if (_key == DIK_END) exitWith {
		[_display] call RHEA_fnc_open;

		true
	};

	false
}];
