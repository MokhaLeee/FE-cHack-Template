#include "gbafe.h"

int GetUnitPower(struct Unit* unit) {
    return unit->pow + GetItemPowBonus(GetUnitEquippedWeapon(unit));
}

int GetUnitSpeed(struct Unit* unit) {
    int item = GetUnitEquippedWeapon(unit);

    if (unit->state & US_RESCUING)
        return unit->spd / 2 + GetItemSpdBonus(item);

    return unit->spd + GetItemSpdBonus(item);
}