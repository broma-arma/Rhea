#include "../defines.hpp"

TRACE_1("fn_login: %1", _this);

disableSerialization;

params ["_dialog"];

private _txtError = _dialog displayCtrl 1006;
private _txtPass = _dialog displayCtrl 1400;

_txtError ctrlSetText "Logging in...";

if (isMultiplayer) then {
	[_txtError, _txtPass] spawn {
		disableSerialization;

		params ["_txtError", "_txtPass"];

		player setVariable ["nfe_rhea_waiting", true, true];

		[player, (ctrlText _txtPass)] remoteExec ["RHEA_SERVER_fnc_loginPlayer", 2];

		private _dots = "...";
		private _step = 0;
		_txtError ctrlSetTextColor [1, 1, 1, 1];
		waitUntil {
			_txtError ctrlSetText ("Logging in" + (_dots select [0, _step + 1]));
			_step = (_step + 1) % 3;
			uiSleep 0.1;

			!(player getVariable ["nfe_rhea_waiting", true])
		};
		_txtError ctrlSetTextColor [
			profilenamespace getvariable ["IGUI_ERROR_RGB_R",0.8],
			profilenamespace getvariable ["IGUI_ERROR_RGB_G",0.0],
			profilenamespace getvariable ["IGUI_ERROR_RGB_B",0.0],
			profilenamespace getvariable ["IGUI_ERROR_RGB_A",1.0]
		];

		if !(player getVariable ["nfe_rhea_loggedIn", false]) then {
			_txtError ctrlSetText "Bad credentials!";
		} else {
			_txtError ctrlSetText "";
			(uiNamespace getVariable ["nfe_rhea_loginDialog", displayNull]) closeDisplay 0;
			findDisplay getNumber (configFile >> "RscDisplayMission" >> "idd") createDisplay "nfe_rhea_main";
		};
	};
} else {
	player setVariable ["nfe_rhea_loggedIn", true];
	_txtError ctrlSetText "";
	(uiNamespace getVariable ["nfe_rhea_loginDialog", displayNull]) closeDisplay 0;
	findDisplay getNumber (configFile >> "RscDisplayMission" >> "idd") createDisplay "nfe_rhea_main";
};
