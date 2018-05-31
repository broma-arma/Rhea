#include "../defines.hpp"

TRACE_1("fn_listPlayers: %1", _this);

disableSerialization;

params ["_listPlayers"];

private _selection = lbSelection _listPlayers;
private _size = lbSize _listPlayers;
_listPlayers lbSetCurSel -1;
lbClear _listPlayers;

private _colors = [
	[profilenamespace getvariable ['Map_Unknown_R', 0], profilenamespace getvariable ['Map_Unknown_G', 1], profilenamespace getvariable ['Map_Unknown_B', 1], profilenamespace getvariable ['Map_Unknown_A', 0.8]],
	[profilenamespace getvariable ['Map_BLUFOR_R', 0], profilenamespace getvariable ['Map_BLUFOR_G', 1], profilenamespace getvariable ['Map_BLUFOR_B', 1], profilenamespace getvariable ['Map_BLUFOR_A', 0.8]],
	[profilenamespace getvariable ['Map_OPFOR_R', 0], profilenamespace getvariable ['Map_OPFOR_G', 1], profilenamespace getvariable ['Map_OPFOR_B', 1], profilenamespace getvariable ['Map_OPFOR_A', 0.8]],
	[profilenamespace getvariable ['Map_Independent_R', 0], profilenamespace getvariable ['Map_Independent_G', 1], profilenamespace getvariable ['Map_Independent_B', 1], profilenamespace getvariable ['Map_Independent_A', 0.8]],
	[profilenamespace getvariable ['Map_Civilian_R', 0], profilenamespace getvariable ['Map_Civilian_G', 1], profilenamespace getvariable ['Map_Civilian_B', 1], profilenamespace getvariable ['Map_Civilian_A', 0.8]]
];

private _showDead = profileNamespace getVariable ["RHEA_cfg_showdead", false];
private _showAI = profileNamespace getVariable ["RHEA_cfg_showai", true];

{
	if !(isNil "_x" || {isNull _x}) then {
		private _isPlayer = isPlayer _x;
		private _alive = !(_x getVariable ["isDead", false]);
		if (alive _x && (_showDead || _alive) && (_showAI || _isPlayer)) then {
			private _i = _listPlayers lbAdd ((if (_isPlayer) then {""} else {"[AI] "}) + (name _x)); // Note: name doesn't work with !alive units.
			_listPlayers lbSetColor [_i, _colors select (switch (side _x) do {
				case west: { 1 };
				case east: { 2 };
				case resistance: { 3 };
				case civilian: { 4 };
				default { 0 };
			})];
			_listPlayers lbSetData [_i, _x call BIS_fnc_objectVar];
			private _picture = if (_alive) then {
				if (_x getVariable ["ace_isunconscious", false]) then {
					"\A3\Ui_f\data\IGUI\Cfg\Revive\overlayIcons\r100_ca.paa"
				} else {
					""
				}
			} else {
				"\A3\Ui_f\data\IGUI\Cfg\Revive\overlayIcons\d100_ca.paa"
			};
			_listPlayers lbSetPicture [_i, _picture];
		};
	} else {
		diag_log text "Entry in allUnits is Nil/Null";
	};
} forEach allUnits;
if (_size == lbSize _listPlayers) then {
	{ _listPlayers lbSetSelected [_x, true]; } forEach _selection;
};
