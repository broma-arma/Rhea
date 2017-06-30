
_targets = [] call fnc_getTargetSelected;

hint format ["%1", _targets];

// _allUnits = (allPlayers - entities "HeadlessClient_F");
_allUnits = allUnits;

_type = (_targets select 0);
_target = (_targets select 1);

switch (_type) do {
    case "SIDE": {
        {
            if (side _x == _target) then {
                _x setPos [(getPos player select 0) + random(5), (getPos player select 1) + random(5), 0];
            };
        } forEach _allUnits;
    };
    case "UNIT": { _target setPos [(getPos player select 0) + random(5), (getPos player select 1) + random(5), 0]; };
};
