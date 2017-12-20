#include "../defines.hpp"

TRACE_1("fn_isOpen: %1", _this);

!isNull (uiNamespace getVariable ["nfe_rhea_loginDialog", displayNull]) || !isNull findDisplay getNumber (configFile >> "nfe_rhea_main" >> "idd")
