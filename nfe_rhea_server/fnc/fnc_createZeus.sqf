_pos = [0,0,0];
_unit = _this select 0;

player sideChat format ["%1 has logged into Zeus.", name _unit];

_module = RheaGroup createUnit ["ModuleCurator_F", _pos,[],0.5,"NONE"];
_module setvariable ["Text", "Zeus", true];
_module setvariable ["Forced", 0, true];
_module setVariable ["birdType", "", true];
_module setvariable ["Addons", 3,true];

_module allowCuratorLogicIgnoreAreas true;
_module setCuratorEditingAreaType true;

_module addCuratorEditableObjects [(vehicles + allUnits), true];
_module setCuratorWaypointCost 0;

{ _module setCuratorCoef [_x, 0] } forEach ["place","edit","delete","destroy","group","synchronize"];
_module setvariable ["vehicleinit",""];

_module AddCuratorAddons RheaAddons;

_unit assignCurator _module;

//[_unit, _module] spawn {
//    params ["_unit", "_module"];
//
//    player sideChat format ["UNIT: %1 | MODULE: %2", _unit, _module];
//
//    waitUntil{(!alive _unit)};
//
//    player sideChat format ["%1 has died.", name _unit];
//
//    sleep 1;
//
//    deleteVehicle _module;
//
//    waitUntil{(alive _unit)};
//
//    player sideChat format ["%1 has respawned.", name _unit];
//
//    sleep 3;
//
//    diag_log format ["== RHEA: Reassigning Zeus to %1.", name _unit];
//    hint format ["== RHEA: Reassigning Zeus to %1.", name _unit];
//
//    [_unit] call fnc_createZeus;
//
//    player sideChat format ["Module reassigned.", name _unit];
//};

_module
