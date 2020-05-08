#include "../defines.hpp"

TRACE_1("MenuBar: %1", _this);

disableSerialization;

params ["_control", "_configPath", "_action"];

switch (_action) do {
	case "OnLoad": {
		private _fnc_menuConfig = {
			if (_this isEqualTo []) exitWith { configNull };

			private _cfg = _configPath >> "Items";
			{
				_cfg = _configPath >> "Items" >> (getArray (_cfg >> "items") select _x);
			} forEach _this;

			_cfg
		};

		private _fnc_compileProperty = {
			params ["_property", ["_default", nil]];

			private _value = getText (_cfgMenu >> _property);
			if (_value == "") exitWith { _default };

			_value = compile _value;
			if (isNil "_value") exitWith { _default };

			_value = call _value;
			if (isNil "_value") exitWith { _default };

			_value
		};

		private _disabledPaths = [];
		private _fnc_initMenu = {
			private _path = _this;
			private _cfgMenu = _path call _fnc_menuConfig;
			private _size = _control menuSize _path;

			private _enable = ["nfe_rhea_enable", true] call _fnc_compileProperty;
			if (_enable) then {
				if (_size == 0) then {
					private _menuData = _control menuData _path;
					if (_menuData != "") then {
						_control menuSetAction [_path, format ["_this + ['%1'] call RHEA_fnc_menuBar;", _menuData]];
					};

					private _checked = ["nfe_rhea_checked"] call _fnc_compileProperty;
					if (!isNil "_checked") then {
						_control menuSetCheck [_path, _checked];
					};
				} else {
						for "_i" from 0 to _size - 1 do {
							(_this + [_i]) call _fnc_initMenu;
						};
					};
			} else {
				_disabledPaths pushBack _path;
			};
		};
		[] call _fnc_initMenu;

		reverse _disabledPaths;
		{ _control menuDelete _x; } forEach _disabledPaths;
	};

	case "ShowAI";
	case "ShowDead": {
		private _var = "RHEA_cfg_" + (toLower _action);
		profileNamespace setVariable [_var, !(profileNamespace getVariable [_var, true])];
		saveProfileNamespace;
		(ctrlParent _control displayCtrl 2100) call RHEA_fnc_listPlayers;
	};
	case "CuratorCamEars": {
		if (HAS_ADDON("tfar_core")) then {
			player setVariable ["TFAR_curatorCamEars", !(player getVariable ["TFAR_curatorCamEars", false])];
		} else {
			"tfar_core addon not loaded" call RHEA_fnc_message;
		};
	};

	case "Zeus": {
		if (isNull getAssignedCuratorLogic player) then {
			[player] remoteExec ["RHEA_SERVER_fnc_startZeus", 2];

			0 spawn {
				waitUntil { !isNull getAssignedCuratorLogic player };
				private _curatorLogic = getAssignedCuratorLogic player;

				_curatorLogic addEventHandler ["CuratorObjectRegistered", {
					params ["_curator", "_input"];

					0 spawn {
						waitUntil { !isNull curatorCamera };

						curatorCamera camCommand "maxPitch 89.0";
					};
				}];

				_curatorLogic addEventHandler ["CuratorPinged", {
					params ["_curator", "_player"];

					systemChat format ["Pinged: %1", name _player];
				}];
			};
		} else {
			"Zeus already started" call RHEA_fnc_message;
		};
	};

	case "Arsenal_BIS": {
		ctrlParent _control closeDisplay 0;
		['Open', true] spawn BIS_fnc_arsenal;
	};

	case "Arsenal_ACE": {
		if (HAS_ADDON("ace_arsenal")) then {
			ctrlParent _control closeDisplay 0;
			[player, player, true] call ace_arsenal_fnc_openBox;
		} else {
			"ace_arsenal addon not loaded" call RHEA_fnc_message;
		};
	};

	case "Camera": {
		ctrlParent _control closeDisplay 0;
		[] spawn BIS_fnc_camera;
	};

	case "Debug": {
		createDialog "nfe_rhea_debug";
	};

	case "TFARSpecFix": {
		if (HAS_ADDON("tfar_core")) then {
			{
				if (alive _x && !(_x getVariable ["isDead", false]) && (_x getVariable ["TFAR_forceSpectator", false])) then {
					systemChat format ["TFARSpecFix: %1", _x];
					{
						if !(["IsSpectating"] call BIS_fnc_EGSpectator) then { // Local
							[player, false] call TFAR_fnc_forceSpectator;
						};
					} remoteExec ["call", _x];
				};
			} forEach allPlayers;
		} else {
			"tfar_core addon not loaded" call RHEA_fnc_message;
		};
	};

	case "MoveRespawn": {
		private _names = ["General", "West", "East", "Resistance", "Resistance", "Civilian"];
		private _markerNames = ["respawn", "respawn_west", "respawn_east", "respawn_guerrila", "respawn_resistance", "respawn_civilian"];

		private _options = [];
		{
			if (markerType _x != "") then {
				_options pushBack [_names select _forEachIndex, _x];
			};
		} forEach _markerNames;

		if (count _options > 0) then {
			[ctrlParent _control, _options] spawn {
				disableSerialization;
				params ["_display", "_options"];

				(["Side", "Select a side:", 0, _options] call RHEA_fnc_inputDialog) params ["_status", "_text", "_data", "_value"];
				if (_status) then {
					_display closeDisplay 2;
					openMap [true, true];
					rheaRespawnPos = [];
					onMapSingleClick "rheaRespawnPos = _pos; true";
					waitUntil { count rheaRespawnPos > 0 };
					onMapSingleClick "";
					_data setMarkerPos rheaRespawnPos;
					rheaRespawnPos = nil;
					openMap [false, false];
					findDisplay getNumber (configFile >> "RscDisplayMission" >> "idd") createDisplay "nfe_rhea_main";
				};
			};
		} else {
			"No respawn markers" call RHEA_fnc_message;
		};
	};

	case "DisableSpawnProtection": {
		if (USES_BRMFMK_PLUGIN("spawn_protection")) then {
			{
				if (mission_spawn_protection_time > 0) then {
					mission_spawn_protection_time = 0;
				} else {
					["Spawn Protection is already disabled"] remoteExec ["RHEA_fnc_message", remoteExecutedOwner];
				};
			} remoteExec ["call", 2];
		} else {
			"spawn_protection plugin not loaded" call RHEA_fnc_message;
		};
	};

	case "DisableCommanderLock": {
		if (USES_BRMFMK_PLUGIN("commander_lock")) then {
			if !(co_lock_allSidesReady) then {
				locked_sides = [];
				publicVariable "locked_sides";

				co_lock_allSidesReady = true;
				publicVariable "co_lock_allSidesReady";

				["Alert", ["Zeus declares that the mission is ready to begin!"]] remoteExec ["BIS_fnc_showNotification", 0];
			} else {
				"Commander Lock is already disabled" call RHEA_fnc_message;
			};
		} else {
			"commander_lock plugin not loaded" call RHEA_fnc_message;
		};
	};

	case "TimeLimit": {
		if (USES_BRMFMK_PLUGIN("time_limit")) then {
			0 spawn {
				(["Add to Time Limit", "Minutes to add:", "5"] call RHEA_fnc_inputDialog) params ["_status", "_text"];
				if (_status) then {
					private _seconds = (parseNumber _text) * 60;
					if (_seconds > 0) then {
						[_seconds] remoteExec ["BRM_FMK_TimeLimit_fnc_addTime", 2];
					} else {
						"Value must be greater than 0" call RHEA_fnc_message;
					};
				};
			};
		} else {
			"time_limit plugin not loaded" call RHEA_fnc_message;
		};
	};

	case "Conditions": {
		createDialog "nfe_rhea_conditions";
	};

	case "EndMission": {
		0 spawn {
			private _options = if (isNil "BRM_FMK_fnc_callEnding") then {
				[
					["Everyone Won", "EveryoneWon", "Mission Completed"],
					["Everyone Lost", "EveryoneLost", "Mission Failed"],
					["Side Score", "SideScore", "Side with the best score wins"],
					["Group Score", "GroupScore", "Group with the best score wins"],
					["Player Score", "PlayerScore", "Player with the best score wins"]
				]
			} else {
				if (mission_game_mode == "coop") exitWith {
					// COOP
					[
						["Victory", endings_victory],
						["Defeat", endings_defeat]
					]
				};
				// (CO-)TVT
				[
					["Auto", endings_tvt_auto],
					["A Victory", endings_tvt_side_a_victory],
					["B Victory", endings_tvt_side_b_victory],
					["C Victory", endings_tvt_side_c_victory]
				]
			};

			(["End Mission", "Select the ending:", 0, _options] call RHEA_fnc_inputDialog) params ["_status", "_text", "_data", "_value"];
			if (_status) then {
				[_data] remoteExec [if (isNil "BRM_FMK_fnc_callEnding") then { "BIS_fnc_endMissionServer" } else { "BRM_FMK_fnc_callEnding" }, 2];
			};
		};
	};

	case "SelectAll": {
		private _ctrlPlayersList = ctrlParent _control displayCtrl 2100;
		for "_i" from 0 to lbSize _ctrlPlayersList - 1 do {
			_ctrlPlayersList lbSetSelected [_i, true];
		};
	};

	case "SelectAll";
	case "SelectPlayers";
	case "SelectAI";
	case "SelectWest";
	case "SelectEast";
	case "SelectGuer";
	case "SelectCiv": {
		private _filter = switch (_action) do {
			case "SelectAll": { {true} };
			case "SelectPlayers": { {isPlayer _this} };
			case "SelectAI": { {!isPlayer _this} };
			case "SelectWest": { {side _this == west} };
			case "SelectEast": { {side _this == east} };
			case "SelectGuer": { {side _this == independent} };
			case "SelectCiv": { {side _this == civilian} };
		};

		private _ctrlPlayersList = ctrlParent _control displayCtrl 2100;
		for "_i" from 0 to lbSize _ctrlPlayersList - 1 do {
			private _unit = missionNamespace getVariable (_ctrlPlayersList lbData _i);
			_ctrlPlayersList lbSetSelected [_i, _unit call _filter];
		};
	};

	case "DeleteDead": {
		{
			{
				deleteVehicle _x;
			} forEach allDead;
		} remoteExec ["call", 2];
	};

	case "Cleanup": {
		{
			{
				{
					deleteVehicle _x;
				} forEach allMissionObjects _x;
			} forEach ["WeaponHolder", "WeaponHolderSimulated", "CraterLong"];

			if !(isNil "ace_medical_allCreatedLitter") then {
				{
					_x params ["_time", "_objects"];

					{
						deleteVehicle _x;
					} forEach _objects;
				} forEach ace_medical_allCreatedLitter;
				ace_medical_allCreatedLitter = [];
			};
		} remoteExec ["call", 2];
	};
};
