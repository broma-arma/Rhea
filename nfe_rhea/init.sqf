waitUntil {(time > 1)};

fnc_assignZeus = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_assignZeus.sqf");
fnc_logOut = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_logOut.sqf");
fnc_tpToPlayer = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_tpToPlayer.sqf");
fnc_tpPlayer = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_tpPlayer.sqf");
fnc_killPlayer = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_killPlayer.sqf");
fnc_freezePlayer = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_freezePlayer.sqf");
fnc_initMainMenu = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_initMainMenu.sqf");
fnc_keysPressed = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_func_keyspressed.sqf");
fnc_listPlayers = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_listPlayers.sqf");
fnc_listSides = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_listSides.sqf");
fnc_setConditions = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_setConditions.sqf");
fnc_getTargetSelected = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_getTargetSelected.sqf");
fnc_listTasks = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_listTasks.sqf");
fnc_setTaskState = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_setTaskState.sqf");
fnc_getAIName = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_getAIName.sqf");
fnc_endMission = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_endMission.sqf");
fnc_cleanDeadUnits = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_cleanDeadUnits.sqf");
fnc_healPlayer = compile preprocessFileLineNumbers ("nfe_rhea\fnc\fnc_healPlayer.sqf");

waitUntil {!(isNull (findDisplay 46))};
(findDisplay 46) displayAddEventHandler ["KeyDown","_this call fnc_keysPressed"];

diag_log format ["== %1: RHEA CLIENT VERSION 0.78 enabled.", time];