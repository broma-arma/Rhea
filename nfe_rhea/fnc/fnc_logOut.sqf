_unit = player;

_isZeus = _unit getVariable ["isZeus",false];

logOutZeus = {
    _module = _this select 0;
    unassignCurator _module;
    deleteVehicle _module;
};
publicVariable "logOutZeus";

if (_isZeus) exitWith {
    _unit setVariable ["isZeus",false,true];
    _module = _unit getVariable "zModule";
    hint "Logged out from RHEA.";
    [[_module],"logOutZeus",false,true] spawn BIS_fnc_MP;
    closeDialog 0;
};