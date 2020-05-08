#include "../defines.hpp"

if (!isServer) exitWith {};

TRACE_1("fn_deleteDead: %1", _this);

{
	deleteVehicle _x;
} forEach allDead;
