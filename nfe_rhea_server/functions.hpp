class RHEA_SERVER {
	class general {
		file = "nfe_rhea_server\functions";
		class preInit { preInit = 1; RECOMPILE; };
		class postInit { postInit = 1; RECOMPILE; };

		class loginPlayer { RECOMPILE; };
		class logoutPlayer { RECOMPILE; };
		class startZeus { RECOMPILE; };
		class stopZeus { RECOMPILE; };

		class deleteDead { RECOMPILE; };
		class cleanup { RECOMPILE; };
		class rearmVehicle { RECOMPILE; };
	};
};
class RHEA_REMOTE {
	class general {
		file = "nfe_rhea_server\functions";
		class teleport {};
	};
};
