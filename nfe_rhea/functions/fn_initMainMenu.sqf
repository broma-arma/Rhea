#include "../defines.hpp"

TRACE_1("fn_initMainMenu: %1", _this);

disableSerialization;

params ["_display"];

private _listPlayers = _display displayCtrl 2100;
_listPlayers call RHEA_fnc_listPlayers;
_listPlayers ctrlAddEventHandler ["MouseButtonClick", {
	params ["_control", "_button", "_x", "_y", "_shift", "_ctrl", "_alt"];
	if (_button == 1) then { // Right Mouse Button
		if (count lbSelection _control > 0) then {
			private _ctrlMenu = (ctrlParent _control) ctrlCreate ["nfe_rhea_main_playerMenu", -1];
			_ctrlMenu ctrlSetPosition [_x, _y];
			_ctrlMenu ctrlCommit 0;
			ctrlSetFocus _ctrlMenu;
		} else {
			DEBUG("No player's selected.");
		};
	};
}];
_listPlayers ctrlAddEventHandler ["LBSelChanged", {
	params ["_control", "_index"];

	ctrlParent _control displayCtrl 2101 call RHEA_fnc_listTasks;
}];

private _listTasks = _display displayCtrl 2101;
_listTasks call RHEA_fnc_listTasks;
_listTasks ctrlAddEventHandler ["MouseButtonClick", {
	params ["_control", "_button", "_x", "_y", "_shift", "_ctrl", "_alt"];
	if (_button == 1) then { // Right Mouse Button
		if (count lbSelection _control > 0) then {
			private _ctrlMenu = (ctrlParent _control) ctrlCreate ["nfe_rhea_main_taskMenu", -1];
			_ctrlMenu ctrlSetPosition [_x, _y];
			_ctrlMenu ctrlCommit 0;
			ctrlSetFocus _ctrlMenu;
		} else {
			DEBUG("No task's selected.");
		};
	};
}];

_display displayAddEventHandler ["KeyDown", {
	params ["_display", "_key", "_shift", "_ctrl", "_alt"];

	if (_key == DIK_END) exitWith {
		_display closeDisplay 0;

		true
	};

	false
}];
