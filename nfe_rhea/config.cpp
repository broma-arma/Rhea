class CfgPatches {
	class nfe_gaia {
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"Extended_EventHandlers", "A3_Modules_F"};
		author[] = {"Nife"};
		authorUrl = "http://broma.co.uk";
		version = "0.74";
		versionDesc = "RHEA - Instant Zeus";
	};	
};

#include "dialogs\common.hpp"
#include "dialogs\main.hpp"

class Extended_PostInit_EventHandlers {
	class nfe_rhea {
		init = "[] execVM 'nfe_rhea\init.sqf';";
	};
};