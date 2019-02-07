#ifndef GRA_GAME_H
#define GRA_GAME_H

enum FIELD {FLD_EMPTY, FLD_CIRCLE, FLD_CROSS};

enum GAMESTATE { GS_NOTSTARTED,
    GS_MOVE,
    GS_WON,
    GS_DRAW };


enum SIGN { SGN_CIRCLE, SGN_CROSS };

bool game_start();
bool move_made(unsigned current_player);
bool draw_board();
bool check_if_won();


#endif //GRA_GAME_H
