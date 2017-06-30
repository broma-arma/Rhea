private["_unit"];

_name = _this select 0;
_firstchar = [_name, 0, 0] call BIS_fnc_trimString;

if (_firstchar == "[") then {    
    _return = [_name, 5, -x] call BIS_fnc_trimString;
    _return
};