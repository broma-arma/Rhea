class nfe_rhea_login {
	idd = -1;
	onLoad = "ctrlSetFocus ((_this select 0) displayCtrl 1400);";

	class ControlsBackground {
		class background: IGUIBack {
			idc = -1;
			x = 16.5 * GUI_GRID_W + GUI_GRID_X;
			y = 10.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 7 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
			colorBackground[] = {0.05,0.05,0.05,1};
		};
		class txtTitle: RscText {
			idc = -1;
			text = "RHEA - Login";
			x = 16.5 * GUI_GRID_W + GUI_GRID_X;
			y = 10.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 6.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorBackground[] = GUI_BCG_COLOR;
		};
		class txtError: RscText {
			idc = 1006;
			x = 17 * GUI_GRID_W + GUI_GRID_X;
			y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 6 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorText[] = IGUI_ERROR_COLOR;
		};
	};
	class Controls {
		class btnClose: RscButton {
			idc = 1600;
			action = "closeDialog 0";
			text = "X";
			x = 23 * GUI_GRID_W + GUI_GRID_X;
			y = 10.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorBackground[] = GUI_BCG_COLOR;
			colorBackgroundActive[] = IGUI_ERROR_COLOR;
		};
		class btnLogin: RscButton {
			idc = 1601;
			onButtonClick = "ctrlParent (_this select 0) call RHEA_fnc_login;";
			text = "Login";
			x = 19 * GUI_GRID_W + GUI_GRID_X;
			y = 13 * GUI_GRID_H + GUI_GRID_Y;
			w = 2 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class txtPass: RscEdit {
			idc = 1400;
			onKeyDown="params ['_control', '_key', '_shift', '_ctrl', '_alt']; if (_key == 28 || _key == 156) then { ctrlParent _control call RHEA_fnc_login; };";
			x = 17 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
			w = 6 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
	};
};

class nfe_rhea_main {
	idd = 7268;
	onLoad = "_this call RHEA_fnc_initMainMenu";
	onUnload = "";
	class ControlsBackground {};
	class Controls {
		class btnClose: RscButton {
			action = "findDisplay getNumber (configFile >> 'nfe_rhea_main' >> 'idd') closeDisplay 0;";
			text = "X";
			tooltip = "Close this menu.";
			x = 39.5 * GUI_GRID_W + GUI_GRID_X;
			y = 0 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,1};
			colorBackgroundActive[] = IGUI_ERROR_COLOR;
		};
		class listPlayers: RscListbox {
			idc = 2100;
			style = LB_MULTI;

			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 6.5 * GUI_GRID_W;
			h = 24.5 * GUI_GRID_H;
			colorBackground[] = {0.05,0.05,0.05,1};
		};
		class listTasks: listPlayers {
			idc = 2101;

			x = 33.5 * GUI_GRID_W + GUI_GRID_X;
		};
		class MenuStrip: ctrlMenuStrip {
			onLoad = "_this + ['OnLoad'] call RHEA_fnc_menuBar;";
			idc = 2102;
			x = 0 * GUI_GRID_W + GUI_GRID_X;
			y = 0 * GUI_GRID_H + GUI_GRID_Y;
			w = 39.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorStripBackground[] = {0,0,0,1};
			colorBackground[] = {0.1,0.1,0.1,1};
			class Items {
				items[] = {
					"Rhea",
					"Tools",
					"Mission",
					"Select",
					"Utility"
				};
				class Rhea {
					text = "Rhea";
					items[] = {
						"Rhea_Options",
						"Rhea_Logout",
						"Rhea_Close"
					};
				};
				class Rhea_Options {
					text = "Options";
					items[] = {
						"Rhea_Options_ShowAI",
						"Rhea_Options_ShowDead"
					};
				};
				class Rhea_Options_ShowAI {
					text = "Show AI";
					data = "ShowAI";
					tooltip = "Toggle showing of AI in the unit list.";
					type = "CheckBox";
					default = "true";
				};
				class Rhea_Options_ShowDead {
					text = "Show Dead Players";
					data = "ShowDead";
					tooltip = "Toggle showing of dead units in the unit list.";
					type = "CheckBox";
					default = "false";
				};
				class Rhea_Logout {
					text = "Logout";
					action="call RHEA_fnc_logout;";
					tooltip = "Logout.";
				};
				class Rhea_Close {
					text = "Close";
					action="findDisplay getNumber (configFile >> 'nfe_rhea_main' >> 'idd') closeDisplay 0;";
					tooltip = "Close this menu.";
				};
				class Tools {
					text = "Tools";
					items[] = {
						"Tools_Zeus",
						"Tools_Arsenal",
						"Tools_Camera",
						"Tools_Debug"
					};
				};
				class Tools_Zeus {
					text = "Zeus";
					data = "Zeus";
				};
				class Tools_Arsenal {
					text = "Arsenal";
					data = "Arsenal";
					tooltip = "Opens the Virtual Arsenal.";
				};
				class Tools_Camera {
					text = "Camera";
					data = "Camera";
					tooltip = "Opens the Splendid Camera.";
				};
				class Tools_Debug {
					text = "Debug";
					data = "Debug";
				};
				class Mission {
					text = "Mission";
					items[] = {
						"Mission_Respawn",
						"Mission_DisableCommanderLock",
						"Mission_TimeLimit",
						"Mission_Conditions",
						"Mission_End"
					};
				};
				class Mission_Respawn {
					text = "Respawn";
					items[] = {
						"Mission_Respawn_Move",
						"Mission_Respawn_DisableProtection"
					};
				};
				class Mission_Respawn_Move {
					text = "Move";
					data = "MoveRespawn";
				};
				class Mission_Respawn_DisableProtection {
					text = "Disable Protection";
					data = "DisableSpawnProtection";
				};
				class Mission_DisableCommanderLock {
					text = "Disable Commander Lock";
					data = "DisableCommanderLock";
				};
				class Mission_TimeLimit {
					text = "Time Limit";
					data = "TimeLimit";
				};
				class Mission_Conditions {
					text = "Conditions";
					data = "Conditions";
				};
				class Mission_End {
					text = "End";
					data = "EndMission";
				};

				class Select {
					text = "Select";
					items[] = {
						"Select_All",
						"Select_Players",
						"Select_AI",
						"Select_Side"
					};
				};
				class Select_All {
					text = "All";
					data = "SelectAll";
				};
				class Select_Players {
					text = "Players";
					data = "SelectPlayers";
				};
				class Select_AI {
					text = "AI";
					data = "SelectAI";
				};
				class Select_Side {
					text = "Side";
					items[] = {
						"Select_Side_West",
						"Select_Side_East",
						"Select_Side_Guer",
						"Select_Side_Civ"
					};
				};
				class Select_Side_West {
					text = "West";
					data = "SelectWest";
				};
				class Select_Side_East {
					text = "East";
					data = "SelectEast";
				};
				class Select_Side_Guer {
					text = "Guer";
					data = "SelectGuer";
				};
				class Select_Side_Civ {
					text = "Civ";
					data = "SelectCiv";
				};
				class Utility {
					text = "Utility";
					items[] = {
						"Utility_DeleteDead",
						"Utility_Cleanup",
						"Utility_TFAR"
					};
				};
				class Utility_DeleteDead {
					text = "Delete Dead";
					data = "DeleteDead";
				};
				class Utility_Cleanup {
					text = "Cleanup";
					data = "Cleanup";
					tooltip = "Delete's dropped weapons, items, craters, ...";
				};
				class Utility_TFAR {
					text = "TFAR";
					items[] = {
						"Utility_TFAR_CuratorCamEars",
						"Utility_TFAR_SpecFix"
					};
				};
				class Utility_TFAR_CuratorCamEars {
					text = "Curator Camera Ears";
					data = "CuratorCamEars";
					tooltip = "Toggle hearing of units from Curator camera.";
					type = "CheckBox";
					default = "false";
				};
				class Utility_TFAR_SpecFix { // In-case someone manually enters Spectator.
					text = "Spectator Fix";
					data = "TFARSpecFix";
					tooltip = "Fix player's experiencing the spectator TFAR issue when alive. (Radio works, no proximity)";
				};
				class Separator {};
				class Default {
					text="$STR_3DEN_Display3DEN_MenuBar_Default_text";
					enable=0;
				};
			};
		};
	};
}

class nfe_rhea_conditions {
	idd = -1;
	onLoad = "_this call RHEA_fnc_initConditions;";
	class ControlsBackground {
		class BG: IGUIBack {
			idc = -1;
			x = 14.5 * GUI_GRID_W + GUI_GRID_X;
			y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 11 * GUI_GRID_W;
			h = 5.4 * GUI_GRID_H;
			colorBackground[] = {0.05,0.05,0.05,1};
		};
	};
	class Controls {
		class txtTitle: RscText {
			idc = 9036;
			text = "Conditions";
			x = 14.5 * GUI_GRID_W + GUI_GRID_X;
			y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 10.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorBackground[] = GUI_BCG_COLOR;
		};
		class btnClose: RscButton {
			idc = 9636;
			text = "X";
			x = 25 * GUI_GRID_W + GUI_GRID_X;
			y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorBackground[] = GUI_BCG_COLOR;
			colorBackgroundActive[] = IGUI_ERROR_COLOR;
		};
		class btnOk: RscButtonMenuOK {
			idc = 1600;
			x = 23.6 * GUI_GRID_W + GUI_GRID_X;
			y = 14.1 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.7 * GUI_GRID_W;
			h = 0.6 * GUI_GRID_H;
		};
		class btnCancel: RscButtonMenuCancel {
			idc = 1601;
			x = 21.8 * GUI_GRID_W + GUI_GRID_X;
			y = 14.1 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.7 * GUI_GRID_W;
			h = 0.6 * GUI_GRID_H;
		};
		class txtHour: RscText {
			idc = 9037;
			text = "Hour";
			x = 14.6 * GUI_GRID_W + GUI_GRID_X;
			y = 10 * GUI_GRID_H + GUI_GRID_Y;
			w = 10.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class sdrHour: RscSlider {
			idc = 9936;
			onSliderPosChanged = "";
			x = 14.6 * GUI_GRID_W + GUI_GRID_X;
			y = 10.6 * GUI_GRID_H + GUI_GRID_Y;
			w = 10.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class txtRain: RscText {
			idc = 9038;
			text = "Rain & Overcast";
			x = 14.6 * GUI_GRID_W + GUI_GRID_X;
			y = 11.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 10.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class sdrRain: RscSlider {
			idc = 9937;
			onSliderPosChanged = "";
			x = 14.6 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
			w = 10.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class txtFog: RscText {
			idc = 9039;
			text = "Fog";
			x = 14.6 * GUI_GRID_W + GUI_GRID_X;
			y = 12.8 * GUI_GRID_H + GUI_GRID_Y;
			w = 10.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class sdrFog: RscSlider {
			idc = 9938;
			onSliderPosChanged = "";
			x = 14.6 * GUI_GRID_W + GUI_GRID_X;
			y = 13.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 10.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
	};
};

class nfe_rhea_input {
	idd = -1;
	onLoad = "uiNamespace setVariable ['RHEA_inputDialog_status', nil]; uiNamespace setVariable ['RHEA_inputDialog', _this select 0];";
	onUnload = "uiNamespace setVariable ['RHEA_inputDialog', nil];";
	onKeyDown = "if ((_this select 1) == 1) then {uiNamespace setVariable ['RHEA_inputDialog_status', false]; true} else {false}";
	class ControlsBackground {
		class background: IGUIBack {
			idc = -1;
			x = 16 * GUI_GRID_W + GUI_GRID_X;
			y = 10.8 * GUI_GRID_H + GUI_GRID_Y;
			w = 8 * GUI_GRID_W;
			h = 3.4 * GUI_GRID_H;
			colorBackground[] = {0.05,0.05,0.05,1};
		};
	};
	class Controls {
		class txtTitle: RscText {
			idc = 9036;
			text = "Input";
			x = 16 * GUI_GRID_W + GUI_GRID_X;
			y = 10.8 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorBackground[] = GUI_BCG_COLOR;
		};
		class btnClose: RscButton {
			idc = 9636;
			text = "X";
			action = "uiNamespace setVariable ['RHEA_inputDialog_status', false];";
			x = 23.5 * GUI_GRID_W + GUI_GRID_X;
			y = 10.8 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorBackground[] = GUI_BCG_COLOR;
			colorBackgroundActive[] = IGUI_ERROR_COLOR;
		};
		class btnOk: RscButtonMenuOK {
			idc = 1600;
			action = "uiNamespace setVariable ['RHEA_inputDialog_status', true];";
			x = 22 * GUI_GRID_W + GUI_GRID_X;
			y = 13.6 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.9 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class btnCancel: RscButtonMenuCancel {
			idc = 1601;
			action = "uiNamespace setVariable ['RHEA_inputDialog_status', false];";
			x = 20 * GUI_GRID_W + GUI_GRID_X;
			y = 13.6 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.9 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class stxtMsg: RscStructuredText {
			idc = 9136;
			text = "Enter your input:";
			x = 16.1 * GUI_GRID_W + GUI_GRID_X;
			y = 11.4 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.8 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class editBox: RscEdit {
			idc = 9436;
			default = 1;
			x = 16.1 * GUI_GRID_W + GUI_GRID_X;
			y = 13 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class cmbBox: RscCombo {
			idc = 10136;
			default = 1;
			fade = 1;
			x = 16.1 * GUI_GRID_W + GUI_GRID_X;
			y = 13 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
	};
};

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

class nfe_rhea_main_taskMenu: ctrlMenu {
	colorBackground[]={0.1,0.1,0.1,1};
	class Items {
		items[]= {
			"Succeeded",
			"Failed",
			"Canceled"
		};
		class Succeeded {
			text="Succeeded";
			action="[_this select 0, 'Succeeded'] call RHEA_fnc_taskMenu;";
		};
		class Failed {
			text="Failed";
			action="[_this select 0, 'Failed'] call RHEA_fnc_taskMenu;";
		};
		class Canceled {
			text="Canceled";
			action="[_this select 0, 'Canceled'] call RHEA_fnc_taskMenu;";
		};
		class Default {
			text="$STR_3DEN_Display3DEN_MenuBar_Default_text";
			enable=0;
		};
	};
};

class nfe_rhea_debug {
	idd = -1;
	onLoad = "['onLoad', _this] call RHEA_fnc_debug";
	onUnload = "['onUnload', _this] call RHEA_fnc_debug";
	class ControlsBackground {
		class DebugBackground: IGUIBack {
			idc = -1;
			x = 12 * GUI_GRID_W + GUI_GRID_X;
			y = 6 * GUI_GRID_H + GUI_GRID_Y;
			w = 16 * GUI_GRID_W;
			h = 13 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class Title: RscText {
			idc = -1;
			text = "Debug"; //--- ToDo: Localize;
			x = 12 * GUI_GRID_W + GUI_GRID_X;
			y = 6 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			colorBackground[] = GUI_BCG_COLOR;
		};
		class ExpressionFrame: RscFrame {
			idc = -1;
			text = "Execute"; //--- ToDo: Localize;
			x = 12 * GUI_GRID_W + GUI_GRID_X;
			y = 6.8 * GUI_GRID_H + GUI_GRID_Y;
			w = 16 * GUI_GRID_W;
			h = 8.7 * GUI_GRID_H;
		};
		class WatchFrame: RscFrame {
			idc = -1;
			text = "Watch"; //--- ToDo: Localize;
			x = 12 * GUI_GRID_W + GUI_GRID_X;
			y = 15.7 * GUI_GRID_H + GUI_GRID_Y;
			w = 16 * GUI_GRID_W;
			h = 3.4 * GUI_GRID_H;
		};
	};
	class Controls {
		class Expression: RscEdit {
			idc = 1400;
			style = ST_MULTI;
			autocomplete = "scripting";
			font = "EtelkaMonospacePro";
			x = 12.1 * GUI_GRID_W + GUI_GRID_X;
			y = 7.1 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.8 * GUI_GRID_W;
			h = 7.7 * GUI_GRID_H;
			//sizeEx = "0.7 * GUI_GRID_H";
			sizeEx = "0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonExecuteLocal: RscButtonMenu {
			idc = 2401;
			text = "LOCAL";
			onButtonClick = "['executeButton', [0] + _this] call RHEA_fnc_debug;";
			x = 24.1 * GUI_GRID_W + GUI_GRID_X;
			y = 14.9 * GUI_GRID_H + GUI_GRID_Y;
			w = 3.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class ButtonExecuteGlobal: RscButtonMenu {
			idc = 2402;
			text = "GLOBAL";
			onButtonClick = "['executeButton', [1] + _this] call RHEA_fnc_debug;";
			x = 12.1 * GUI_GRID_W + GUI_GRID_X;
			y = 14.9 * GUI_GRID_H + GUI_GRID_Y;
			w = 3.8 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class ButtonExecuteServer: RscButtonMenu {
			idc = 2403;
			text = "SERVER";
			onButtonClick = "['executeButton', [2] + _this] call RHEA_fnc_debug;";
			x = 20.1 * GUI_GRID_W + GUI_GRID_X;
			y = 14.9 * GUI_GRID_H + GUI_GRID_Y;
			w = 3.9 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class ButtonExecuteClient: RscButtonMenu {
			idc = 2404;
			text = "CLIENT";
			onButtonClick = "['executeButton', [3] + _this] call RHEA_fnc_debug;";
			x = 16 * GUI_GRID_W + GUI_GRID_X;
			y = 14.9 * GUI_GRID_H + GUI_GRID_Y;
			w = 3.9 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class ButtonClose: RscButtonMenuCancel {
			idc = 2400;
			text = "X";
			onButtonClick = "closeDialog 2;";
			x = 27.5 * GUI_GRID_W + GUI_GRID_X;
			y = 6 * GUI_GRID_H + GUI_GRID_Y;
			w = 0.5 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
		};
		class WatchInput1: RscEdit {
			idc = 1401;
			autocomplete = "scripting";
			font = "EtelkaMonospacePro";
			x = 12.1 * GUI_GRID_W + GUI_GRID_X;
			y = 16 * GUI_GRID_H + GUI_GRID_Y;
			w = 7.3 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			//sizeEx = "0.7 * GUI_GRID_H";
			sizeEx = "0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class WatchInput2: WatchInput1 {
			idc = 1402;
			y = 16.6 * GUI_GRID_H + GUI_GRID_Y;
		};
		class WatchInput3: WatchInput1 {
			idc = 1403;
			y = 17.2 * GUI_GRID_H + GUI_GRID_Y;
		};
		class WatchInput4: WatchInput1 {
			idc = 1404;
			y = 17.8 * GUI_GRID_H + GUI_GRID_Y;
		};
		class WatchInput5: WatchInput1 {
			idc = 1405;
			y = 18.4 * GUI_GRID_H + GUI_GRID_Y;
		};
		class WatchOutput1: RscEdit {
			idc = 1406;
			lineSpacing = 1;
			style = ST_NO_RECT;
			font = "EtelkaMonospacePro";
			colorBackground[] = {0,0,0,0.75};
			x = 19.6 * GUI_GRID_W + GUI_GRID_X;
			y = 16 * GUI_GRID_H + GUI_GRID_Y;
			w = 8.3 * GUI_GRID_W;
			h = 0.5 * GUI_GRID_H;
			//sizeEx = "0.7 * (safezoneH / 25)";
			sizeEx = "0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class WatchOutput2: WatchOutput1 {
			idc = 1407;
			y = 16.6 * GUI_GRID_H + GUI_GRID_Y;
		};
		class WatchOutput3: WatchOutput1 {
			idc = 1408;
			y = 17.2 * GUI_GRID_H + GUI_GRID_Y;
		};
		class WatchOutput4: WatchOutput1 {
			idc = 1409;
			y = 17.8 * GUI_GRID_H + GUI_GRID_Y;
		};
		class WatchOutput5: WatchOutput1 {
			idc = 1410;
			y = 18.4 * GUI_GRID_H + GUI_GRID_Y;
		};
	};
};
