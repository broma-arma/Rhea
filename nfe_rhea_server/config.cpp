#include "defines.hpp"

class CfgPatches {
	class nfe_rhea_server {
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = { "A3_Modules_F" };
		author = "BromA";
		url = "http://broma.onozuka.info";
		authors[] = { "Nife", "Coryf88" };
		name = "RHEA Server - Instant Zeus";
		VERSION_CONFIG;
	};	
};

class CfgFunctions {
	#include "functions.hpp"
};
