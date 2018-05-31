#include "../defines.hpp"

TRACE_1("fn_errorMessage: %1", _this);

params ["_message"];

cutText [format ["<t color='#ff0000' size='1.5' shadow='2'>%1</t>", _message], "PLAIN", 0.3, true, true];
