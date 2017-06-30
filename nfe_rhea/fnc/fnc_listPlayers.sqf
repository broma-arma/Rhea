
_lb = 2100;

lbClear _lb;

lbAdd [_lb, ""];
{
    if (alive _x) then {
        if (isPlayer _x) then {
            lbAdd [_lb, (name _x)];
        } else {
            // Why did I ever think this was a good idea?
            // lbAdd [2100, "[AI] "+(name _x)];
        };
        lbSetData [_lb, (_forEachIndex + 1), str _x];
        missionNamespace setVariable [str _x, _x];
    };
} forEach allUnits;
