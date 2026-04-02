#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
    ASSUME(GetMoveNonVolatileStatus(MOVE_YAWN) == MOVE_EFFECT_YAWN);
}

SINGLE_BATTLE_TEST("Yawn causes target to fall asleep at the end of the next turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_YAWN); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        
    }
}
