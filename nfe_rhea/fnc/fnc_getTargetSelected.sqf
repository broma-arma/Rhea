
private ["_unitSelected", "_unitData", "_sideSelected", "_sideData", "_unit", "_data", "_typeSelected"];

_lbUnit = 2100;
_lbSide = 2103;

_sideSelected = lbText [_lbSide, lbCurSel _lbSide];
_unitSelected = lbText [_lbUnit, lbCurSel _lbUnit];

if (_sideSelected != "") then {
    _sideData = lbData [_lbSide, lbCurSel _lbSide];
    _sideData = missionNamespace getVariable (_sideSelected + "sideValue");

    _data = _sideData;
    _unit = _sideSelected;

    _typeSelected = "SIDE";
};

if (_unitSelected != "") then {
    _unitData = lbData [_lbUnit, lbCurSel _lbUnit];
    _unitData = missionNamespace getVariable (_unitData);

    _data = _unitData;
    _unit = _unitSelected;

    _typeSelected = "UNIT";
};

[_typeSelected, _data, _unit];