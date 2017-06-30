_unit = lbText[2100, lbCurSel 2100];
_data = lbData [2100, lbCurSel 2100];
_data = missionNamespace getVariable _data;

player setPos [(getPos _data select 0)+random(5), (getPos _data select 1)+random(5), 0];