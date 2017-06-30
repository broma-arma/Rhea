private["_taskDo","_found"];

_task = lbText[2101, lbCurSel 2101];
_state = lbText[2102, lbCurSel 2102];
_found = false;

_allTasks = [player] call BIS_fnc_tasksUnit;

{
    _maintask = [_x] call BIS_fnc_taskDescription;    
    _taskName = (_maintask select 1) select 0;
    
    if (_taskName == _task) exitWith { 
        _taskDo = _x;
        _found = true;
    };
} forEach _allTasks;

if (_found) then { [_taskDo,_state,true] call BIS_fnc_taskSetState };