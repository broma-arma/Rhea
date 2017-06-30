hint format ["Deleted %1 bodies.", count allDead];
{{deleteVehicle _x} forEach (allDead);} remoteExec ["BIS_fnc_call", 2];