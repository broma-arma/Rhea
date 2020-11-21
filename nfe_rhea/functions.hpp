class RHEA {
	class general {
		file = "nfe_rhea\functions";
		class preInit { preInit = 1; RECOMPILE; };
		class postInit { postInit = 1; RECOMPILE; };

		class open { RECOMPILE; };
		class isOpen { RECOMPILE; };

		class initMainMenu { RECOMPILE; };

		class initDisplay { RECOMPILE; };
		class initDisplayCurator { RECOMPILE; };
		class initModuleCurator { RECOMPILE; };

		class login { RECOMPILE; };
		class logout { RECOMPILE; };

		class listPlayers { RECOMPILE; };
		class listTasks { RECOMPILE; };

		class menuBar { RECOMPILE; };
		class playerMenu { RECOMPILE; };
		class taskMenu { RECOMPILE; };

		class initConditions { RECOMPILE; };

		class inputDialog { RECOMPILE; };

		class debug { RECOMPILE; };

		class message { RECOMPILE; };
	};
};
