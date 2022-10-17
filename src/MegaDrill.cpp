#include "Tool.h"
#include "PowerTool.h"
#include "MegaDrill.h"
#include <string>
using namespace std;

//Same constructor as PowerTool, however 
MegaDrill::MegaDrill(double baseRate_, string toolName_, double poweredMultiplier_, double _price){
    baseRate = baseRate_;
    toolName = toolName_;
    poweredMultiplier = poweredMultiplier_;
    price = _price;
    powerTool = 1;
}

void MegaDrill::upgrade(){
    if (upgraded == 0) {
        upgraded = 1;
        baseRate = baseRate * 10;
        poweredMultiplier = poweredMultiplier * 10;
    }
}