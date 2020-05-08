#include "../defines.hpp"

TRACE_1("fn_logout: %1", _this);

if (player getVariable ["nfe_rhea_loggedIn", false]) then {
	player remoteExec ["RHEA_SERVER_fnc_logoutPlayer", 2];

	[{ !(player getVariable ["nfe_rhea_loggedIn", false]) }, {
		findDisplay getNumber (configFile >> "nfe_rhea_main" >> "idd") closeDisplay 0;
		systemChat "RHEA: Logged out";
	}] call CBA_fnc_waitUntilAndExecute;
};
