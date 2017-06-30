
_playerTasks = [player] call BIS_fnc_tasksUnit;

{
    _maintask = [_x] call BIS_fnc_taskDescription;

    _description = (_maintask select 0) select 0;
    _name = (_maintask select 1) select 0;

    lbAdd [2101, _name];
} forEach _playerTasks;

{ lbAdd [2102, _x] } forEach ["Succeeded","Failed","Canceled"];