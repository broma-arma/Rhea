#include "../defines.hpp"

TRACE_1("fn_taskMenu: %1", _this);

disableSerialization;

params ["_control", "_state"];

private _display = ctrlParent _control;
private _listTasks = _display displayCtrl 2101;

private _refreshTaskList = false;
{
	private _task = _listTasks lbText _x;
	{
		(taskDescription _x) params ["_description", "_title", "_marker"];
		if (_task == _title) exitWith {
			if ((taskState _x) != _state) then {
				_refreshTaskList = true;

				_x setTaskState _state;

				private _data = ["task" + _state, [_description, _title, _marker]];
				private _typeTexture = [taskType _x] call BIS_fnc_taskTypeIcon;
				if (_typeTexture != "") then {
					if (_state == "Created") then {
						_state = "Unassigned";
					};
					_data = ["task" + _state + "Icon", [_typeTexture, _title]];
				};
				_data remoteExec ["BIS_fnc_showNotification"];
			};
		};
	} forEach (simpleTasks player);
} forEach lbSelection _listTasks;

if (_refreshTaskList) then {
	_listTasks call RHEA_fnc_listTasks;
};
