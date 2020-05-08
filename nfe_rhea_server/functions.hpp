class RHEA_SERVER {
	class general {
		file = "nfe_rhea_server\functions";
		class preInit { preInit = 1; };
		class postInit { postInit = 1; };

		class loginPlayer {};
		class logoutPlayer {};
		class startZeus {};
		class stopZeus {};

		class deleteDead {};
		class cleanup {};
		class rearmVehicle {};
	};
};
class RHEA_REMOTE {
	class general {
		file = "nfe_rhea_server\functions";
		class teleport {};
	};
};
