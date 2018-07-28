#include "gbafe.h"

int AreUnitsSameAllegiance(const struct Unit* self, const struct Unit* other) {
	extern int IsSameAllegience(int, int) __attribute__((long_call));

	return IsSameAllegience(self->index, other->index);
}

int AreNeitherUnitPhantomClass(const struct Unit* self, const struct Unit* other) {
	static const unsigned ClassPhantom = 0x51;

	if (self->pClassData->number == ClassPhantom)
		return FALSE;

	if (other->pClassData->number == ClassPhantom)
		return FALSE;

	return TRUE;
}
