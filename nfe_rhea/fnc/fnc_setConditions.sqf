
_rangeTime = 1900;
_rangeRain = 1901;

sliderSetRange [_rangeTime, 0, 24];
sliderSetRange [_rangeRain, 0, 1];

_currentHour = (date select 3);
_currentRain = overcast;

sliderSetPosition [_rangeTime, floor(date select 3)];
sliderSetPosition [_rangeRain, _currentRain];

hint format ["Rain: %1 | Hour: %2", _currentRain, _currentHour];