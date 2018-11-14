class CfgPatches {
	class nfe_rhea {
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Modules_F", "A3_UI_F", "3DEN", "cba_xeh"};
		author[] = {"Nife"};
		authorUrl = "http://bro.ma";
		version = "0.82";
		versionDesc = "RHEA - Instant Zeus";
	};
};

class CfgFunctions {
	#include "functions.hpp"
};

class Extended_DisplayLoad_EventHandlers {
	class RscDisplayMission {
		InitKeys = "_this call RHEA_fnc_initKeys";
	};
	class RscDisplayEGSpectator {
		InitKeys = "_this call RHEA_fnc_initKeys";
	};
};

#include "dialogs\common.hpp"
#include "dialogs.hpp"
