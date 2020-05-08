#include "../defines.hpp"

if !(isServer) exitWith {};

TRACE_1("fn_preInit: %1", _this);

if !(isDedicated) exitWith {};

#include "../initSettings.sqf"
