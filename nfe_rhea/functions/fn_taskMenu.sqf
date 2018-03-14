#include "../defines.hpp"

TRACE_1("fn_taskMenu: %1", _this);

disableSerialization;

params ["_control", "_state"];

private _display = ctrlParent _control;
private _listTasks = _display displayCtrl 2101;

private _refreshTaskList = false;
{
	private _task = _listTasks lbData _x;
	if ((_task call BIS_fnc_taskState) != _state) then {
		_refreshTaskList = true;

		[_task, _state] call BIS_fnc_taskSetState;

		{
			if ({
				_x params ["_id", "_priority", "_condWin", "_condLose", "_cbCompleted", "_cbFailed"];

				if (_task == _id) exitWith {
					switch (_state) do {
						case "SUCCEEDED": { call _cbCompleted; };
						case "FAILED";
						case "CANCELED": { call _cbFailed; };
					};

					true
				};

				false
			} forEach _x) exitWith {};
		} forEach BRM_FMK_tasks;
	};
} forEach lbSelection _listTasks;

if (_refreshTaskList) then {
	_listTasks call RHEA_fnc_listTasks;
};
