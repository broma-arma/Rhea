#include "../defines.hpp"

// Note: suspension is allowed here, but will halt the mission loading until complete.
0 spawn {
	waitUntil { !(isNil "nfe_rhea_init") };

	private _displayMission = getNumber (configFile >> "RscDisplayMission" >> "idd");

	waitUntil { !(isNull findDisplay _displayMission) };

	findDisplay _displayMission displayAddEventHandler ["KeyDown", {
		params ["_display", "_key", "_shift", "_ctrl", "_alt"];

		if (_key == DIK_END) exitWith {
			DEBUG_2("MP=%1, logged_in=%2", isMultiplayer, player getVariable [ARR_2("nfe_rhea_loggedIn", false)]);
			[] call RHEA_fnc_open;

			true
		};

		false
	}];

	INFO_2("Started %1 @ %2", getText (configFile >> "CfgPatches" >> "nfe_rhea" >> "version"), time);

	[player, "", true] remoteExec ["RHEA_SERVER_fnc_loginPlayer", 2];
};