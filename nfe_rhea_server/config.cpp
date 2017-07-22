class CfgPatches {
	class nfe_gaia {
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Modules_F"};
		author[] = {"Nife"};
		authorUrl = "http://bro.ma";
		version = "0.81";
		versionDesc = "RHEA Server - Instant Zeus";
	};	
};

class CfgFunctions {
	class RHEA_SERVER {
		class general {
			file = "nfe_rhea_server\functions";
			class preInit {preInit = 1;};
			class postInit {postInit = 1;};

			class loginPlayer {};
			class logoutPlayer {};
			class startZeus {};
		};
	};
};
