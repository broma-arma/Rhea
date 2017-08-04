class CfgPatches {
	class nfe_rhea {
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {
			"A3_Modules_F",
			"A3_UI_F",
			"3DEN"
		};
		author[] = {"Nife"};
		authorUrl = "http://broma.co.uk";
		version = "0.75";
		versionDesc = "RHEA - Instant Zeus";
	};
};

class CfgFunctions {
	class RHEA {
		class general {
			file = "nfe_rhea\functions";
			class postInit {postInit = 1;};

			class initMainMenu {};

			class login {};
			class logout {};

			class listPlayers {};
			class listTasks {};

			class menuBar {};
			class playerMenu {};
			class taskMenu {};

			class initConditions {};

			class inputDialog {};

			class debug {};
		};
	};
};

#include "dialogs\common.hpp"
#include "dialogs.hpp"
