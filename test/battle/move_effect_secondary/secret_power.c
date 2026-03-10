#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_SECRET_POWER, MOVE_EFFECT_SECRET_POWER) == TRUE);
}

SINGLE_BATTLE_TEST("Secret Power paralyzes in Electric Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, MOVE_SECRET_POWER); }
    } SCENE {
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}
