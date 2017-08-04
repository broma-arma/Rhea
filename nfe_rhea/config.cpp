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
	#include "functions.hpp"
};

#include "dialogs\common.hpp"
#include "dialogs.hpp"
