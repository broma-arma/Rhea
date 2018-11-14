#include "../defines.hpp"

TRACE_1("fn_initKeys: %1", _this);

params ["_display"];

_display displayAddEventHandler ["KeyDown", {
	params ["_display", "_key", "_shift", "_ctrl", "_alt"];

	if (isNil "nfe_rhea_init") exitWith { false };

	if (_key == DIK_END) exitWith {
		DEBUG_2("MP=%1, logged_in=%2", isMultiplayer, player getVariable [ARR_2("nfe_rhea_loggedIn", false)]);
		[_display] call RHEA_fnc_open;

		true
	};

	false
}];
