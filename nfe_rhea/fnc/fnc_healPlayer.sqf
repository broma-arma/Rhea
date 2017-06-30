_unit = lbText[2100, lbCurSel 2100];
_data = lbData [2100, lbCurSel 2100];
_data = (missionNamespace getVariable _data);

if (!(_unit == "")) then {
    [_data, _data] remoteExec ["ace_medical_fnc_treatmentAdvanced_fullHealLocal", _data];
};