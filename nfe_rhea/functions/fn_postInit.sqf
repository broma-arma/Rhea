#include "../defines.hpp"

// Note: suspension is allowed here, but will halt the mission loading until complete.
0 spawn {
	waitUntil { !(isNil "nfe_rhea_init") };

	INFO_2("Started %1 @ %2", getText (configFile >> "CfgPatches" >> "nfe_rhea" >> "version"), time);

	[player, "", true] remoteExec ["RHEA_SERVER_fnc_loginPlayer", 2];
};
