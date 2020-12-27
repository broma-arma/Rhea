#include "defines.hpp"

class CfgPatches {
	class nfe_rhea {
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = { "A3_Modules_F", "A3_UI_F", "3DEN", "cba_xeh", "cba_settings" };
		author = "BromA";
		url = "http://broma.onozuka.info";
		authors[] = { "Nife", "Coryf88" };
		name = "RHEA - Instant Zeus";
		VERSION_CONFIG;
	};
};

class CfgFunctions {
	#include "functions.hpp"
};

class Extended_DisplayLoad_EventHandlers {
	class RscDisplayCurator {
		nfe_rhea_initKeys = "_this call RHEA_fnc_initDisplayCurator";
	};
	class RscDisplayEGSpectator {
		nfe_rhea_initKeys = "_this call RHEA_fnc_initDisplay";
	};
	class ace_spectator_display {
		nfe_rhea_initKeys = "_this call RHEA_fnc_initDisplay";
	};
};

class Extended_Init_EventHandlers {
	class ModuleCurator_F {
		class nfe_rhea_ModuleCurator_F_init_eh {
			init = "_this call RHEA_fnc_initModuleCurator";
		};
	};
};

#include "dialogs\common.hpp"
#include "dialogs.hpp"
