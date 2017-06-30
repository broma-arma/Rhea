_unit = lbText[2100, lbCurSel 2100];
_data = lbData [2100, lbCurSel 2100];
_data = missionNamespace getVariable _data;

// _data setDamage 1;

// [] call fnc_listPlayers;

_hour = floor(sliderPosition 1900);
_rainvercast = sliderPosition 1901;

setDate [(date select 0), (date select 1), (date select 2), _hour, (date select 4)];

hint str(_rainvercast);

0 setRain _rainvercast;
0 setOvercast _rainvercast;

forceWeatherChange;