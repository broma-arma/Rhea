_unit = lbText[2100, lbCurSel 2100];
_data = lbData [2100, lbCurSel 2100];
_data = (missionNamespace getVariable _data);

if (simulationEnabled _data) then {
    [_data, false] remoteExecCall ["enableSimulationGlobal", _data];
} else {
    [_data, true] remoteExecCall ["enableSimulationGlobal", _data];
};