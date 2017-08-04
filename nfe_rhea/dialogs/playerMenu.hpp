class nfe_rhea_main_playerMenu: ctrlMenu {
	colorBackground[]={0.1,0.1,0.1,1};
	class Items {
		items[]= {
			"Notify",
			"Teleport",
			"Health",
			"State"
		};
		class Notify {
			text="Notify";
			action="[_this select 0, 'Notify'] call RHEA_fnc_playerMenu;";
		};
		class Teleport {
			text = "Teleport";
			items[] = {
				"Teleport_GoTo",
				"Teleport_Bring",
			};
		};
		class Health {
			text = "Health";
			items[] = {
				"Health_Heal",
				"Health_Kill",
			};
		};
		class State {
			text = "State";
			items[] = {
				"State_Freeze",
				"State_RepairArmFuel",
				"State_AssignLoadout",
				"State_Respawn"
			};
		};
		class Teleport_GoTo {
			text="Go To";
			action="[_this select 0, 'GoTo'] call RHEA_fnc_playerMenu;";
		};
		class Teleport_Bring {
			text="Bring";
			action="[_this select 0, 'Bring'] call RHEA_fnc_playerMenu;";
		};
		class Health_Heal {
			text="Heal";
			action="[_this select 0, 'Heal'] call RHEA_fnc_playerMenu;";
		};
		class Health_Kill {
			text="Kill";
			action="[_this select 0, 'Kill'] call RHEA_fnc_playerMenu;";
		};
		class State_Freeze {
			text="Freeze";
			action="[_this select 0, 'Freeze'] call RHEA_fnc_playerMenu;";
		};
		class State_RepairArmFuel {
			text="Repair/Arm/Fuel";
			action="[_this select 0, 'RepairArmFuel'] call RHEA_fnc_playerMenu;";
		};
		class State_AssignLoadout {
			text="Assign Loadout";
			action="[_this select 0, 'AssignLoadout'] call RHEA_fnc_playerMenu;";
		};
		class State_Respawn {
			text="Respawn";
			action="[_this select 0, 'Respawn'] call RHEA_fnc_playerMenu;";
		};
		class Separator {
			value=0;
		};
		class Default {
			text="$STR_3DEN_Display3DEN_MenuBar_Default_text";
			enable=0;
		};
	};
};
