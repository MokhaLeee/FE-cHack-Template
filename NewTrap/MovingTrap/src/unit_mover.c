#include "unit_mover.h"

extern const uint8_t pFacingTable[];

const ProcCode ProcCode_UnitMoveAnim[] = {
	_6C_SET_DESTRUCTOR(UnitMoveAnim_OnDestruct), // Delet
	_6C_YIELD,                                   // Yielding to ensure everything is set up properly
	_6C_LOOP_ROUTINE(UnitMoveAnim_OnLoop),       // Move that sprite
	_6C_END                                      // End
};

UnitMoveAnimProc* NewUnitMoveAnim(MoveUnitProc* moveunit, Vector2 from, Vector2 to, Proc* parent) {
	UnitMoveAnimProc* moveAnimProc = 0;

	// making 6C
	if (parent) {
		moveAnimProc = (UnitMoveAnimProc*) New6CBlocking(ProcCode_UnitMoveAnim, parent);
		moveAnimProc->locks = 0;
	} else {
		moveAnimProc = (UnitMoveAnimProc*) New6C(ProcCode_UnitMoveAnim, ProcThread(3));
		
		moveAnimProc->locks = 1;
		LockGameLogic();
	}
	
	// making linked MOVEUNIT
	// MoveUnitProc* moveunit = NewMoveUnitForMapUnit(unit);
	// SetMoveUnitDirection(moveunit, facing);
	
	SetMoveUnitDisplayPosition(moveunit, from.x, from.y);
	
	// writing fields to the proc struct
	moveAnimProc->pMoveUnit = moveunit;
	moveAnimProc->from      = from;
	moveAnimProc->to        = to;
	moveAnimProc->clock     = 0;
	
	// Returning
	return moveAnimProc;
}

void UnitMoveAnim_OnDestruct(UnitMoveAnimProc* proc) {
	if (proc->locks)
		UnlockGameLogic();
}

void UnitMoveAnim_OnLoop(UnitMoveAnimProc* proc) {
	// TODO: check for fast/slow speed option
	if (!MoveMoveUnitTowards(proc->pMoveUnit, proc->to.x, proc->to.y, 5))
		Break6CLoop((Proc*) proc);
	// else {
		// int localTime = (proc->timer++) % 4;
		
		// if (!localTime) { // localTime == 0
			// int facing = pFacingTable[((proc->timer++) / 4) % 4];
			// SetMoveUnitDirection(proc->pMoveUnit, facing);
		// }
	// }
}
