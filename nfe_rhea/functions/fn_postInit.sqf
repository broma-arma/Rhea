#include "../defines.hpp"

// Note: suspension is allowed here, but will halt the mission loading until complete.
0 spawn {
	waitUntil { !(isNil "nfe_rhea_init") };

	private _displayMission = getNumber (configFile >> "RscDisplayMission" >> "idd");

	waitUntil { !(isNull findDisplay _displayMission) };

	findDisplay _displayMission displayAddEventHandler ["KeyDown", {
		params ["_display", "_key", "_shift", "_ctrl", "_alt"];

		if (_key == DIK_END) exitWith {
			if (!dialog) then {
				DEBUG_2("MP=%1, logged_in=%2", isMultiplayer, player getVariable [ARR_2("nfe_rhea_loggedIn", false)]);
				if (isMultiplayer && !(player getVariable ["nfe_rhea_loggedIn", false])) then {
					createDialog "nfe_rhea_login";
				} else {
					findDisplay getNumber (configFile >> "RscDisplayMission" >> "idd") createDisplay "nfe_rhea_main";
				};
			} else {
				closeDialog 0;
			};

			true
		};

		false
	}];

	INFO_2("Started %1 @ %2", getText (configFile >> "CfgPatches" >> "nfe_rhea" >> "version"), time);

	[player, "", true] remoteExec ["RHEA_SERVER_fnc_loginPlayer", 2];
};