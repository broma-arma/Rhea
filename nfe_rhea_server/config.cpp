class CfgPatches {
	class nfe_gaia {
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"Extended_EventHandlers", "A3_Modules_F"};
		author[] = {"Nife"};
		authorUrl = "http://bro.ma";
		version = "0.80";
		versionDesc = "RHEA Server - Instant Zeus";
	};	
};

class Extended_PostInit_EventHandlers {
	class nfe_rhea_server {
		init = "[] execVM 'nfe_rhea_server\init.sqf';";
	};
};