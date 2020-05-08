#include "../defines.hpp"

TRACE_1("fn_playerMenu: %1", _this);

disableSerialization;

params ["_control", "_action"];

private _display = ctrlParent _control;
private _listPlayers = _display displayCtrl 2100;
private _selectedPlayers = lbSelection _listPlayers apply { missionNamespace getVariable (_listPlayers lbData _x) } select { !(isNil "_x" || {isNull _x}) };
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
				(format ["Failed to teleport the following players: %1", _fails apply { name _x } joinString ", "]) call RHEA_fnc_errorMessage;
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
		{
			private _vehicle = _x;

			// Repair
			_vehicle setDamage 0;

			// Rearm
			[_vehicle, {
				params ["_vehicle"];

				private _turretOwners = [owner _vehicle] + (allTurrets _vehicle apply { _vehicle turretOwner _x });
				[_vehicle, 1] remoteExec ["setVehicleAmmo", _turretOwners arrayIntersect _turretOwners];
			}] remoteExec ["call", 2];

			// Refuel
			if (local _vehicle) then {
				_vehicle setFuel 1;
			} else {
				[_vehicle, 1] remoteExec ["setFuel", _vehicle];
			};
		} forEach (_selectedPlayers apply { objectParent _x } select { !isNull _x });
	};

	case "Repair": {
		{
			_x setDamage 0;
		} forEach (_selectedPlayers apply { objectParent _x } select { !isNull _x });
	};

	case "Rearm": {
		{
			private _vehicle = _x;
			[_vehicle, {
				params ["_vehicle"];

				private _turretOwners = [owner _vehicle] + (allTurrets _vehicle apply { _vehicle turretOwner _x });
				[_vehicle, 1] remoteExec ["setVehicleAmmo", _turretOwners arrayIntersect _turretOwners];
			}] remoteExec ["call", 2];
		} forEach (_selectedPlayers apply { objectParent _x } select { !isNull _x });
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
			"Broma mission framework not loaded" call RHEA_fnc_errorMessage;
		};
	};

	case "Notify": {
		_selectedPlayers spawn {
			(["Notification message", "Enter the notification message:", ""] call RHEA_fnc_inputDialog) params ["_status", "_text"];
			if (_status) then {
				["Alert", [_text]] remoteExec ["BIS_fnc_showNotification", _this];
			};
		};
	};

	case "Respawn": {
		if (USES_BRMFMK_PLUGIN("respawn_system")) then {
			{
				private _deadPlayer = [getPlayerUID _x, name _x, _x getVariable "unit_side"];
				if (_deadPlayer in mission_dead_players) then {
					mission_dead_players = mission_dead_players - [_deadPlayer];
					publicVariable "mission_dead_players";
					DEBUG_1("Respawned: %1", _x);
					_refreshPlayerList = true;
				} else {
					DEBUG_2("Not Dead: %1 | %2", _x, _deadPlayer);
				};
			} forEach _selectedPlayers;
		} else {
			"respawn_system plugin not loaded" call RHEA_fnc_errorMessage;
		};
	};
};

if (_refreshPlayerList) then {
	[_listPlayers] spawn {
		disableSerialization;
		params ["_listPlayers"];

		_listPlayers lbSetCurSel -1;
		_listPlayers call RHEA_fnc_listPlayers;
	};
};
