#include "../defines.hpp"

if (!isServer) exitWith {};

TRACE_1("fn_startZeus: %1", _this);

params [["_player", objNull]];

if (isNull _player || {_player isKindOf "HeadlessClient_F"} || {!(_player getVariable ["nfe_rhea_loggedIn", false])} || {!(isNull getAssignedCuratorLogic _player)}) exitWith {};

// Note: Created group will be deleted in moduleInit.
private _module = createGroup sideLogic createUnit ["ModuleCurator_F", [0, 0, 0], [], 0, "CAN_COLLIDE"];
_module setVariable ["owner", getPlayerUID _player]; // Default ""
//_module setVariable ["Addons", 2]; // Default 2
//_module setVariable ["forced", 0]; // Default 0
//_module setVariable ["name", ""]; // Default "" (localize "STR_A3_curator")
//_module setVariable ["channels", []]; // Default []
_module setVariable ["showNotification", false]; // Default true
_module setVariable ["birdType", ""]; // Default "eagle_f"

_module setVariable ["RheaZeus", true];

_module setCuratorWaypointCost 0;
_module allowCuratorLogicIgnoreAreas true;
_module addCuratorEditableObjects [(vehicles + allUnits), true];
{ _module setCuratorCoef [_x, 0]; } forEach ["place", "edit", "delete", "destroy", "group", "synchronize"];
