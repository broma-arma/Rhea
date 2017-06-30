private['_handled','_button'];

_button = _this select 1;
_handled = false;

_isZeus = player getVariable ["isZeus",false];

if (_button == 207) then{
    if(not dialog) then{
        if (!_isZeus) then {
            
            [] call fnc_initMainMenu;
            // createDialog "nfe_rhea_login";
        } else {
            [] call fnc_initMainMenu;
        };
    } else{
        closeDialog 0;
    };
    _handled = true;
};

_handled