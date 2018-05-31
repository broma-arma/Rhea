#include "../defines.hpp"

TRACE_1("fn_playerMenu: %1", _this);

disableSerialization;

params ["_control", "_action"];

private _display = ctrlParent _control;
private _listPlayers = _display displayCtrl 2100;

private _refreshPlayerList = false;
{
	private _selectedPlayer = missionNamespace getVariable (_listPlayers lbData _x);
	if !(isNil "_selectedPlayer" || {isNull _selectedPlayer}) then {
		switch (_action) do {
			case "GoTo";
			case "Bring": {
				private _from = player;
				private _to = _selectedPlayer;
				if (_action == "Bring") then {
					_from = _to; _to = player;
				};
				_to = getPos _to;

				_from setPos [(_to select 0) + random(5), (_to select 1) + random(5)];
			};

			case "Heal": {
				if (HAS_ADDON("ace_medical")) then {
					[_selectedPlayer, _selectedPlayer] call ace_medical_fnc_treatmentAdvanced_fullHeal;
				} else {
					_selectedPlayer setDamage 0;
				};
			};

			case "Kill": {
				_selectedPlayer setDamage 1;
				_refreshPlayerList = true;
			};

			case "Freeze": {
				[_selectedPlayer, {
					_this enableSimulationGlobal !(simulationEnabled _this);
				}] remoteExec ["call", 2];
			};

			case "RepairArmFuel": {
				private _vehicle = vehicle _selectedPlayer;
				if (_vehicle != _selectedPlayer) then {
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
				} else {
					DEBUG_1("Not in a vehicle: %1", _selectedPlayer);
				};
			};

			case "AssignLoadout": {
				if !(isNil "BRM_fnc_assignLoadout") then {
					[{
						[player, toLower str (player getVariable ["unit_side", side player])] call BRM_fnc_assignLoadout;
					}] remoteExec ["call", _selectedPlayer];
				} else {
					"Broma mission framework not loaded" call RHEA_fnc_errorMessage;
				};
			};

			case "Notify": {
				_selectedPlayer spawn {
					(["Notification message", "Enter the notification message:", ""] call RHEA_fnc_inputDialog) params ["_status", "_text"];
					if (_status) then {
						["Alert", [_text]] remoteExec ["BIS_fnc_showNotification", _this];
					};
				};
			};

			case "Respawn": {
				if (USES_BRMFMK_PLUGIN("respawn_system")) then {
					private _deadPlayer = [getPlayerUID _selectedPlayer, name _selectedPlayer, _selectedPlayer getVariable "unit_side"];
					if (_deadPlayer in mission_dead_players) then {
						mission_dead_players = mission_dead_players - [_deadPlayer];
						publicVariable "mission_dead_players";
						DEBUG_1("Respawned: %1", _selectedPlayer);
						_refreshPlayerList = true;
					} else {
						DEBUG_2("Not Dead: %1 | %2", _selectedPlayer, _deadPlayer);
					};
				} else {
					"respawn_system plugin not loaded" call RHEA_fnc_errorMessage;
				};
			};
		};
	};
} forEach lbSelection _listPlayers;

if (_refreshPlayerList) then {
	[_listPlayers] spawn {
		disableSerialization;
		params ["_listPlayers"];

		_listPlayers lbSetCurSel -1;
		_listPlayers call RHEA_fnc_listPlayers;
	};
};
