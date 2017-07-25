#include "../defines.hpp"

TRACE_1("fn_listTasks: %1", _this);

disableSerialization;

params ["_listTasks"];

private _selection = lbSelection _listTasks;
private _size = lbSize _listTasks;
_listTasks lbSetCurSel -1;
lbClear _listTasks;
{
	_listTasks lbAdd (taskDescription _x select 1);
	_listTasks lbSetColor [_forEachIndex, switch (taskState _x) do {
		case "Succeeded": { [0, 1, 0, 1] };
		case "Failed": { [1, 0, 0, 1] };
		case "Canceled": { [0.5, 0.5, 0.5, 1] };
		default { [1, 1, 1, 1] };
	}];
} forEach (simpleTasks player);
if (_size == lbSize _listTasks) then {
	{ _listTasks lbSetSelected [_x, true]; } forEach _selection;
};
