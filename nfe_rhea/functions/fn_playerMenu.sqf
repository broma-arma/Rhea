#include "../defines.hpp"

TRACE_1("fn_playerMenu: %1", _this);

disableSerialization;

params ["_control", "_action"];

private _display = ctrlParent _control;
private _ctrlPlayersList = _display displayCtrl 2100;
private _selectedPlayers = lbSelection _ctrlPlayersList apply { missionNamespace getVariable (_ctrlPlayersList lbData _x) } select { !(isNil "_x" || {isNull _x}) };
_selectedPlayers = _selectedPlayers arrayIntersect _selectedPlayers;

if (count _selectedPlayers == 0) exitWith {};

private _refreshPlayerList = false;

switch (_action) do {
	case "GoTo";
	case "Bring": {
		private _fnc_teleport = {
			params ["_from", "_to"];

			private _toVehicle = objectParent _to;
			if (isNull _toVehicle) then {
				_to = getPos _to;

				private _emptyTo = _to findEmptyPosition [1, 10, typeOf _from];
				if (count _emptyTo > 0) then {
					_from setPos (_emptyTo select [0, 2]);
				} else {
					_from setPos [(_to select 0) + random 5, (_to select 1) + random 5];
				};

				true
			} else {
				_from moveInAny _toVehicle
			};
		};

		if (_action == "GoTo") then {
			[player, _selectedPlayers select 0] call _fnc_teleport;
		} else {
			private _fails = [];
			{
				if !([_x, player] call _fnc_teleport) then {
					_fails pushBack _x;
				};
			} forEach _selectedPlayers;

			if (count _fails > 0) then {
				(format ["Failed to teleport the following players: %1", _fails apply { name _x } joinString ", "]) call RHEA_fnc_message;
			};
		};
	};

	case "Heal": {
		if (HAS_ADDON("ace_medical")) then {
			private _fnc_fullHeal = if (HAS_ADDON("ace_medical_treatment")) then { ace_medical_treatment_fnc_fullHeal } else { ace_medical_fnc_treatmentAdvanced_fullHeal };
			{
				[player, _x] call _fnc_fullHeal;
			} forEach _selectedPlayers;
		} else {
			{
				_x setDamage 0;
			} forEach _selectedPlayers;
		};
	};

	case "Kill": {
		{
			_x setDamage 1;
		} forEach _selectedPlayers;
		_refreshPlayerList = true;
	};

	case "Freeze": {
		[_selectedPlayers, {
			{
				_x enableSimulationGlobal !(simulationEnabled _x);
			} forEach _this;
		}] remoteExec ["call", 2];
	};

	case "RepairArmFuel": {
		private _vehicles = (_selectedPlayers apply { objectParent _x } select { !isNull _x });
		{
			private _vehicle = _x;

			// Repair
			_vehicle setDamage 0;

			// Refuel
			if (local _vehicle) then {
				_vehicle setFuel 1;
			} else {
				[_vehicle, 1] remoteExec ["setFuel", _vehicle];
			};
		} forEach _vehicles;

		// Rearm
		_vehicles remoteExec ["RHEA_SERVER_fnc_rearmVehicle", 2];
	};

	case "Repair": {
		{
			_x setDamage 0;
		} forEach (_selectedPlayers apply { objectParent _x } select { !isNull _x });
	};

	case "Rearm": {
		(_selectedPlayers apply { objectParent _x } select { !isNull _x }) remoteExec ["RHEA_SERVER_fnc_rearmVehicle", 2];
	};

	case "Refuel": {
		{
			private _vehicle = _x;
			if (local _vehicle) then {
				_vehicle setFuel 1;
			} else {
				[_vehicle, 1] remoteExec ["setFuel", _vehicle];
			};
		} forEach (_selectedPlayers apply { objectParent _x } select { !isNull _x });
	};

	case "AssignLoadout": {
		if !(isNil "BRM_fnc_assignLoadout") then {
			[{
				[player, toLower str (player getVariable ["unit_side", side player])] call BRM_fnc_assignLoadout;
			}] remoteExec ["call", _selectedPlayers];
		} else {
			"Broma mission framework not loaded" call RHEA_fnc_message;
		};
	};

	case "Notify": {
		_selectedPlayers spawn {
			(["Notification message", "Enter the notification message:", ""] call RHEA_fnc_inputDialog) params ["_status", "_text"];
			if (_status) then {
				if (isNil "BRM_fnc_initPlayer") then {
					["TaskDescriptionUpdatedIcon", ["\A3\ui_f\data\map\markers\military\warning_ca.paa", _text]] remoteExec ["BIS_fnc_showNotification", _this];
				} else {
					["Alert", [_text]] remoteExec ["BIS_fnc_showNotification", _this];
				};
			};
		};
	};

	case "Respawn": {
		if (USES_BRMFMK_PLUGIN("respawn_system")) then {
			private _deadPlayers = _selectedPlayers apply { [getPlayerUID _x, name _x, _x getVariable "unit_side"] } select { _x in mission_dead_players };
			if (count _deadPlayers > 0) then {
				mission_dead_players = mission_dead_players - _deadPlayers;
				publicVariable "mission_dead_players";
				_refreshPlayerList = true;
			};
		} else {
			"respawn_system plugin not loaded" call RHEA_fnc_message;
		};
	};
};

if (_refreshPlayerList) then {
	[{
		disableSerialization;
		params ["_listPlayers"];

		_listPlayers lbSetCurSel -1;
		_listPlayers call RHEA_fnc_listPlayers;
	}, [_listPlayers]] call CBA_fnc_execNextFrame;
};
