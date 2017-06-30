private ["_unit","_input","_rightPass","_isZeus","_allowedZeus"];
ctrlSetText [1006, ""];

_unit = player;
authorized = false;

_input = ctrlText 1400;
_isZeus = _unit getVariable ["isZeus",false];

if (!(_isZeus)) then {
    [0, { [_this select 0, _this select 1] call fnc_logPlayer }, [player, _input]] call CBA_fnc_globalExecute;
};

0 spawn {
    _text = ".";
    while {!(_text == ".....")} do {
        _text = _text + ".";
        ctrlSetText [1006, "     waiting" + _text];
        sleep 0.5;
    };
};

waitUntil{!(_unit getVariable ["nfe_waiting", true])};

sleep 3;

_isZeus = _unit getVariable ["isZeus", false];

if ((_isZeus)||(isServer)) then {
    _unit setVariable ["isZeus", true, true];
    ctrlSetText [1006, "LOGIN SUCCESSFUL!"];
    sleep 1;
    closeDialog 0;
    [] call fnc_initMainMenu;

    _unit addEventHandler ["Respawn", {
        if (_unit getVariable "isZeus") then {
            sleep 5;


            _module = _unit getVariable "zModule";
        };
    }];
} else {
    ctrlSetText [1006, "BAD CREDENTIALS!"];
    sleep 2;
    hint "";
};