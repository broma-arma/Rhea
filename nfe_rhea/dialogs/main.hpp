class nfe_rhea_login {
	idd = -1;
	movingEnable = true;
	onLoad = "";
	onUnload = "";
	controls[] = { btnLogin, txtPass, btnExit };
	controlsBackground[] = { mainFrame, IGUIBack_2200, RscText_1003, bgPass, txtError };

	class mainFrame: NFE_IGUIBack
	{
		idc = 1800;

		x = 13 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
		y = 8 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
		w = 12 * NFE_GUI_GRID_W;
		h = 8 * NFE_GUI_GRID_H;
		colorBackground[] = {0.9,0.7,0.4,0.9};
		colorActive[] = {1,1,1,1};
	};
	class txtPass: NFE_RscEdit
	{
		idc = 1400;

		x = 14 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
		y = 10.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
		w = 10 * NFE_GUI_GRID_W;
		h = 1 * NFE_GUI_GRID_H;
		colorBackground[] = {1,1,1,0};
	};
	class IGUIBack_2200: NFE_IGUIBack
	{
		idc = 2200;
		moving = 1;

		x = 13 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
		y = 8 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
		w = 12 * NFE_GUI_GRID_W;
		h = 1.5 * NFE_GUI_GRID_H;
		colorBackground[] = {1,1,1,1};
	};
	class btnLogin: NFE_RscButton
	{
		onButtonClick = "[] spawn fnc_assignZeus";
		idc = 1600;

		text = "Login"; //--- ToDo: Localize;
		x = 17.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
		y = 14 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
		w = 3 * NFE_GUI_GRID_W;
		h = 1.5 * NFE_GUI_GRID_H;
		colorBackground[] = {0.3,0.6,0.3,1};
		colorActive[] = {0.3,0.6,0.3,1};
		colorBackgroundActive[] = {0.1,0.4,0.1,1};
		colorFocused[] = {0.2,0.5,0.2,1};
		colorShadow[] = {0,0,0,0};
	};
	class RscText_1003: NFE_RscText
	{
		idc = 1003;
		shadow = 0;

		text = "RHEA - Login"; //--- ToDo: Localize;
		x = 14.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
		y = 8 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
		w = 6.5 * NFE_GUI_GRID_W;
		h = 1.5 * NFE_GUI_GRID_H;
		colorText[] = {0,0,0,1};
	};
	class bgPass: NFE_IGUIBack
	{
		idc = 2200;

		x = 14 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
		y = 10.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
		w = 10 * NFE_GUI_GRID_W;
		h = 1 * NFE_GUI_GRID_H;
		colorBackground[] = {1,1,1,1};
	};
	class txtError: NFE_RscText
	{
		idc = 1006;
		text = ""; //--- ToDo: Localize;
		shadow = 0;

		x = 14.2 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
		y = 12 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
		w = 10.5 * NFE_GUI_GRID_W;
		h = 1 * NFE_GUI_GRID_H;
		colorText[] = {0.5,0.1,0.1,1};
	};
	class btnExit: NFE_RscButton
	{
		onButtonClick = "closeDialog 0";
		idc = 1600;
		text = "X"; //--- ToDo: Localize;
		x = 23 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
		y = 8 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
		w = 2 * NFE_GUI_GRID_W;
		h = 1.5 * NFE_GUI_GRID_H;

		colorBackground[] = {0.6,0.3,0.3,1};
		colorActive[] = {0.6,0.3,0.3,1};
		colorBackgroundActive[] = {0.4,0.1,0.1,1};
		colorFocused[] = {0.5,0.2,0.2,1};
		colorShadow[] = {0,0,0,0};
	};
};

class nfe_rhea_main {

	idd = -1;
	movingEnable = true;
	onLoad = "";
	onUnload = "";
	controls[] = { btnArsenal, btnTpPlayer, btnTpToPlayer, btnTask, btnLogout, btnClose, btnCamera, listPlayers, listTasks, listTaskStates, listSide, btnKill, btnFreeze, btnClear, btnHeal, btnDisableSpawnProtection, btnChangeRespawn, editLoadout, editRole, btnLoadout, btnRepair, btnResetPlayer, btnResetSide, editNotificationText, btnNotificationButton, sdrTime, sdrRain, btnCondition };
	controlsBackground[] = { BG1, BG2, txtTop, txtSide, txtPlayers, frmFunctions, frmTasks, frmPlayer, txtLoadout, txtRole, txtNotificationText, frmMission, txtMissionTime, txtRain };

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by Nife, v1.063, #Hepuvu)
////////////////////////////////////////////////////////

class BG1: NFE_IGUIBack
{
	idc = 2200;

	x = 2 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 2 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 36 * NFE_GUI_GRID_W;
	h = 23 * NFE_GUI_GRID_H;
	colorBackground[] = {0.9,0.7,0.4,0.9};
	colorActive[] = {1,1,1,1};
};
class BG2: NFE_IGUIBack
{
	idc = 2200;
	moving = 1;

	x = 2 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 0 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 35 * NFE_GUI_GRID_W;
	h = 2 * NFE_GUI_GRID_H;
	colorBackground[] = {1,1,1,1};
};
class frmFunctions: NFE_RscFrame
{
	idc = 1801;

	text = "Misc"; //--- ToDo: Localize;
	x = 3 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 3 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 7 * NFE_GUI_GRID_W;
	h = 6 * NFE_GUI_GRID_H;
};
class frmPlayer: NFE_RscFrame
{
	idc = 1802;

	text = "Units"; //--- ToDo: Localize;
	x = 11 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 3 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 26 * NFE_GUI_GRID_W;
	h = 14 * NFE_GUI_GRID_H;
};
class frmTasks: NFE_RscFrame
{
	idc = 1803;

	text = "Tasks"; //--- ToDo: Localize;
	x = 3 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 10 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 7 * NFE_GUI_GRID_W;
	h = 7 * NFE_GUI_GRID_H;
	sizeEx = 1 * 	(0.04) * 	(0.04) * 	(0.04) * 	(0.04) * 	(0.04) * NFE_GUI_GRID_H;
};
class btnArsenal: NFE_RscButton
{
	onButtonClick = "closeDialog 0; ['Open',true] spawn BIS_fnc_arsenal";
	idc = 1600;
	colorShadow[] = {0,0,0,0};

	text = "Arsenal"; //--- ToDo: Localize;
	x = 3.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 4.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Opens the Virtual Arsenal."; //--- ToDo: Localize;
};
class btnCamera: NFE_RscButton
{
	onButtonClick = "closeDialog 0; [] spawn bis_fnc_camera";
	idc = 1009;
	colorShadow[] = {0,0,0,0};

	text = "Camera"; //--- ToDo: Localize;
	x = 3.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 6 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Opens the Splendid Camera."; //--- ToDo: Localize;
};
class btnTpToPlayer: NFE_RscButton
{
	onButtonClick = "[] call fnc_tpToPlayer";
	idc = 1601;
	colorShadow[] = {0,0,0,0};

	text = "Go to"; //--- ToDo: Localize;
	x = 11.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 7.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 2.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Teleports to the selected Player or Side."; //--- ToDo: Localize;
};
class btnTpPlayer: NFE_RscButton
{
	onButtonClick = "[] call fnc_tpPlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Bring"; //--- ToDo: Localize;
	x = 14.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 7.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 3 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Brings the selected Player or Side to you."; //--- ToDo: Localize;
};
class btnTask: NFE_RscButton
{
	onButtonClick = "[] call fnc_setTaskState";
	idc = 1602;
	colorShadow[] = {0,0,0,0};

	text = "Set State"; //--- ToDo: Localize;
	x = 3.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 15.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Sets a Task's to the selected state."; //--- ToDo: Localize;
};
class btnFreeze: NFE_RscButton
{
	onButtonClick = "[] call fnc_freezePlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Freeze"; //--- ToDo: Localize;
	x = 11.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 9 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 3 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Freezes/Unfreezes the selected Player or Side."; //--- ToDo: Localize;
};
class btnKill: NFE_RscButton
{
	onButtonClick = "[] call fnc_killPlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Kill"; //--- ToDo: Localize;
	x = 18 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 9 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 3 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Kills the selected Player or Side."; //--- ToDo: Localize;
};
class btnLogout: NFE_RscButton
{
	onButtonClick = "[] call fnc_logOut";
	idc = 1600;
	colorBackgroundActive[] = {0.4,0.1,0.1,1};
	colorFocused[] = {0.5,0.2,0.2,1};
	colorShadow[] = {0,0,0,0};

	text = "[<]"; //--- ToDo: Localize;
	x = 34 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 0 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 2 * NFE_GUI_GRID_W;
	h = 2 * NFE_GUI_GRID_H;
	colorBackground[] = {0.6,0.3,0.3,1};
	colorActive[] = {0.6,0.3,0.3,1};
	tooltip = "Logout."; //--- ToDo: Localize;
};
class btnClose: NFE_RscButton
{
	onButtonClick = "closeDialog 0";
	idc = 1601;
	colorBackgroundActive[] = {0.4,0.1,0.1,1};
	colorFocused[] = {0.5,0.2,0.2,1};
	colorShadow[] = {0,0,0,0};

	text = "X"; //--- ToDo: Localize;
	x = 36 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 0 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 2 * NFE_GUI_GRID_W;
	h = 2 * NFE_GUI_GRID_H;
	colorBackground[] = {0.6,0.3,0.3,1};
	colorActive[] = {0.6,0.3,0.3,1};
	tooltip = "Close this menu."; //--- ToDo: Localize;
};
class txtTop: NFE_RscText
{
	idc = 1006;
	shadow = 0;

	text = "RHEA - Tools"; //--- ToDo: Localize;
	x = 16.9 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 0.28 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 7.5 * NFE_GUI_GRID_W;
	h = 1.5 * NFE_GUI_GRID_H;
	colorText[] = {0,0,0,1};
};
class listPlayers: NFE_RscCombo
{
	idc = 2100;

	x = 11.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 5.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 7.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class listTasks: NFE_RscCombo
{
	idc = 2101;

	x = 3.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 12 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class listTaskStates: NFE_RscCombo
{
	idc = 2102;

	x = 3.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 13.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class listSide: NFE_RscCombo
{
	idc = 2103;

	x = 22 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 5.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class btnClear: NFE_RscButton
{
	onButtonClick = "[] call fnc_cleanDeadUnits";
	idc = 1600;
	colorShadow[] = {0,0,0,0};

	text = "Clear bodies"; //--- ToDo: Localize;
	x = 3.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 7.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Clears up all dead bodies in the mission."; //--- ToDo: Localize;
};
class btnHeal: NFE_RscButton
{
	onButtonClick = "[] call fnc_healPlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Heal"; //--- ToDo: Localize;
	x = 18 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 7.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 2.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Heals the selected Player or Side from any ACE wounds."; //--- ToDo: Localize;
};
class txtPlayers: NFE_RscText
{
	idc = 1020;

	text = "Players"; //--- ToDo: Localize;
	x = 11.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 4.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 3.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class txtSide: NFE_RscText
{
	idc = 1021;

	text = "Side"; //--- ToDo: Localize;
	x = 22 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 4.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 2.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class btnDisableSpawnProtection: NFE_RscButton
{
	onButtonClick = "[] call fnc_killPlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Disable Spwn. Prtection."; //--- ToDo: Localize;
	x = 29 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 7 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 7.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Disables the Spawn Protection for the selected Side."; //--- ToDo: Localize;
	sizeEx = 0.75 * 	(0.04) * 	(0.04) * 	(0.04) * 	(0.04) * NFE_GUI_GRID_H;
};
class btnChangeRespawn: NFE_RscButton
{
	onButtonClick = "[] call fnc_killPlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Change Respawn"; //--- ToDo: Localize;
	x = 29 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 5.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 7.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Changes the respawn point for the selected Side."; //--- ToDo: Localize;
};
class editLoadout: NFE_RscEdit
{
	idc = 1400;

	x = 11.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 14 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class txtLoadout: NFE_RscText
{
	idc = 1020;

	text = "Loadout"; //--- ToDo: Localize;
	x = 11.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 13 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 3.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class txtRole: NFE_RscText
{
	idc = 1020;

	text = "Role"; //--- ToDo: Localize;
	x = 18.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 13 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 2.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class editRole: NFE_RscEdit
{
	idc = 1401;

	x = 18.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 14 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class btnLoadout: NFE_RscButton
{
	onButtonClick = "[] call fnc_killPlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Assign Loadout"; //--- ToDo: Localize;
	x = 11.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 15.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 7 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Assigns the selected loadout to the selected Player or Side."; //--- ToDo: Localize;
};
class btnRepair: NFE_RscButton
{
	onButtonClick = "[] call fnc_healPlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Repair/Rearm"; //--- ToDo: Localize;
	x = 21 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 7.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 5.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Repairs, rearms, and refuels the vehicles for the selected Player or Side."; //--- ToDo: Localize;
};
class btnResetPlayer: NFE_RscButton
{
	onButtonClick = "lbSetCurSel [2100, -1];";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "X"; //--- ToDo: Localize;
	x = 19 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 5.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 1 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	colorBackground[] = {0.6,0.3,0.3,1};
	colorActive[] = {0.6,0.3,0.3,1};
	tooltip = "Resets the selected Player."; //--- ToDo: Localize;
};
class btnResetSide: NFE_RscButton
{
	onButtonClick = "lbSetCurSel [2103, -1];";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "X"; //--- ToDo: Localize;
	x = 27 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 5.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 1 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	colorBackground[] = {0.6,0.3,0.3,1};
	colorActive[] = {0.6,0.3,0.3,1};
	tooltip = "Resets the selected Side."; //--- ToDo: Localize;
};
class editNotificationText: NFE_MultiEdit
{
	idc = 1401;

	x = 27 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 11 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 9.5 * NFE_GUI_GRID_W;
	h = 4 * NFE_GUI_GRID_H;
	sizeEx = 0.7 * 	(0.04) * NFE_GUI_GRID_H;
};
class txtNotificationText: NFE_RscText
{
	idc = 1020;

	text = "Notification Text"; //--- ToDo: Localize;
	x = 27 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 10 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 7 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class btnNotificationButton: NFE_RscButton
{
	onButtonClick = "[] call fnc_killPlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Send"; //--- ToDo: Localize;
	x = 27 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 15.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 2.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Sends the notification typed above to the Player or Side."; //--- ToDo: Localize;
};
class frmMission: NFE_RscFrame
{
	idc = 1802;

	text = "Mission"; //--- ToDo: Localize;
	x = 11 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 18 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 19 * NFE_GUI_GRID_W;
	h = 6 * NFE_GUI_GRID_H;
};
class sdrTime: NFE_RscSlider
{
	idc = 1900;

	x = 11.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 20.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class txtMissionTime: NFE_RscText
{
	idc = 1020;

	text = "Time"; //--- ToDo: Localize;
	x = 11.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 19.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 3.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class btnCondition: NFE_RscButton
{
	onButtonClick = "[] call fnc_killPlayer";
	idc = 1603;
	colorShadow[] = {0,0,0,0};

	text = "Commit"; //--- ToDo: Localize;
	x = 16.5 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 22.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 3.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
	tooltip = "Changes the mission weather to the selected above."; //--- ToDo: Localize;
};
class sdrRain: NFE_RscSlider
{
	idc = 1901;

	x = 19 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 20.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 6.5 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
class txtRain: NFE_RscText
{
	idc = 1020;

	text = "Rain & Overcast"; //--- ToDo: Localize;
	x = 19 * NFE_GUI_GRID_W + NFE_GUI_GRID_X;
	y = 19.5 * NFE_GUI_GRID_H + NFE_GUI_GRID_Y;
	w = 7 * NFE_GUI_GRID_W;
	h = 1 * NFE_GUI_GRID_H;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////

}