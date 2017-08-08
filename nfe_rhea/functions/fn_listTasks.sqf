#include "../defines.hpp"

TRACE_1("fn_listTasks: %1", _this);

disableSerialization;

params ["_listTasks"];

private _selection = lbSelection _listTasks;
private _size = lbSize _listTasks;
_listTasks lbSetCurSel -1;
lbClear _listTasks;
{
    (_x call BIS_fnc_taskDescription) params ["_description", "_title", "_marker"];
    _description = _description select 0;
    _title = _title select 0;
    _marker = _marker select 0;

    private _index = _listTasks lbAdd _title;
    _listTasks lbSetData [_index, _x];
    _listTasks lbSetTooltip [_index, _description];
    _listTasks lbSetColor [_index, switch (_x call BIS_fnc_taskState) do {
        case "Succeeded": { [0, 1, 0, 1] };
        case "Failed": { [1, 0, 0, 1] };
        case "Canceled": { [0.5, 0.5, 0.5, 1] };
        default { [1, 1, 1, 1] };
    }];
} forEach (player call BIS_fnc_tasksUnit);
if (_size == lbSize _listTasks) then {
	{ _listTasks lbSetSelected [_x, true]; } forEach _selection;
};
