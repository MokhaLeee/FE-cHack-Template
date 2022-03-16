#include "gbafe.h"

int GetUnitPower(struct Unit* unit) {
	
	int stat;

	stat = unit->pow;
	stat += GetItemPowBonus(GetUnitEquippedWeapon(unit));
	
	if( CHARACTER_EIRIKA == unit->pCharacterData->number )
	{
		stat += 1;
	}
	
	
    return stat;
}