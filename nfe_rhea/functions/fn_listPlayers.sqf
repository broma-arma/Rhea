#include "../defines.hpp"

TRACE_1("fn_listPlayers: %1", _this);

disableSerialization;

params ["_ctrlPlayersList"];

private _selection = lbSelection _ctrlPlayersList;
private _size = lbSize _ctrlPlayersList;
_ctrlPlayersList lbSetCurSel -1;
lbClear _ctrlPlayersList;

private _colors = [
	[profilenamespace getvariable ['Map_BLUFOR_R',      0], profilenamespace getvariable ['Map_BLUFOR_G',      1], profilenamespace getvariable ['Map_BLUFOR_B',      1], profilenamespace getvariable ['Map_BLUFOR_A',      0.8]],
	[profilenamespace getvariable ['Map_OPFOR_R',       0], profilenamespace getvariable ['Map_OPFOR_G',       1], profilenamespace getvariable ['Map_OPFOR_B',       1], profilenamespace getvariable ['Map_OPFOR_A',       0.8]],
	[profilenamespace getvariable ['Map_Independent_R', 0], profilenamespace getvariable ['Map_Independent_G', 1], profilenamespace getvariable ['Map_Independent_B', 1], profilenamespace getvariable ['Map_Independent_A', 0.8]],
	[profilenamespace getvariable ['Map_Civilian_R',    0], profilenamespace getvariable ['Map_Civilian_G',    1], profilenamespace getvariable ['Map_Civilian_B',    1], profilenamespace getvariable ['Map_Civilian_A',    0.8]],
	[profilenamespace getvariable ['Map_Unknown_R',     0], profilenamespace getvariable ['Map_Unknown_G',     1], profilenamespace getvariable ['Map_Unknown_B',     1], profilenamespace getvariable ['Map_Unknown_A',     0.8]]
];

private _showDead = profileNamespace getVariable ["RHEA_cfg_showdead", false];
private _showAI = profileNamespace getVariable ["RHEA_cfg_showai", true];

{
	if !(isNil "_x" || {isNull _x}) then {
		private _isPlayer = isPlayer _x;
		private _alive = !(_x getVariable ["isDead", false]);
		if (alive _x && (_showDead || _alive) && (_showAI || _isPlayer)) then {
			private _i = _ctrlPlayersList lbAdd ((if (_isPlayer) then {""} else {"[AI] "}) + (name _x)); // Note: name doesn't work with !alive units.
			private _sideIndex = [west, east, independent, civilian] find side _x;
			if (_sideIndex == -1) then { _sideIndex = 4; };
			_ctrlPlayersList lbSetColor [_i, _colors select _sideIndex];
			_ctrlPlayersList lbSetData [_i, _x call BIS_fnc_objectVar];
			private _picture = if !(simulationEnabled _x) then {
				"\A3\Ui_f\data\GUI\Rsc\RscDisplaySingleMission\locked_ca.paa"
			} else {
				if (_alive) then {
					if (_x getVariable ["ace_isunconscious", false]) then {
						"\A3\Ui_f\data\IGUI\Cfg\Revive\overlayIcons\r100_ca.paa"
					} else {
						""
					}
				} else {
					"\A3\Ui_f\data\IGUI\Cfg\Revive\overlayIcons\d100_ca.paa"
				};
			};
			_ctrlPlayersList lbSetPicture [_i, _picture];
		};
	} else {
		WARNING("Entry in allUnits is nil/null");
	};
} forEach allUnits;
if (_size == lbSize _ctrlPlayersList) then {
	{ _ctrlPlayersList lbSetSelected [_x, true]; } forEach _selection;
};
