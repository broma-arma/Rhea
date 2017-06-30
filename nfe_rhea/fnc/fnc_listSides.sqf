
_lb = 2103;

lbClear _lb;

lbAdd [_lb, ""];
{
    lbAdd [_lb, (_x select 0)];
    lbSetData [_lb, (_forEachIndex + 1), str (_x select 0)];

    missionNamespace setVariable [(_x select 0) + "sideValue", (_x select 1)];

} forEach [["BLUFOR", WEST], ["OPFOR", EAST], ["INDFOR", RESISTANCE], ["Civilian", CIVILIAN]];