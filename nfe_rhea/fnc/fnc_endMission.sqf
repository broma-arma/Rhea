_status = lbText[2100, lbCurSel 2100];

if (!(_status == "")) then {
    [_status] remoteExec ["BRM_fnc_callEnding", 2];
};