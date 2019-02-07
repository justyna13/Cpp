#include <iostream>
#include "game.h"


GAMESTATE game_status = GS_NOTSTARTED;
SIGN current_player;

using namespace std;
int main() {
    int won;
    cout << "Tic Tac Toe" << endl << endl;

    if (game_status == GS_NOTSTARTED) {
        current_player = SIGN(game_start());

        cout << current_player << endl;
        game_status = GS_MOVE;
    }
    while (game_status == GS_MOVE) {
        move_made(current_player);
        draw_board();
        won = check_if_won();
        if (won) {
            game_status = GS_WON;
            break;
        }
        if (current_player == SGN_CIRCLE) current_player =  SGN_CROSS;
        else current_player = SGN_CIRCLE;
    }
    if (game_status == GS_WON) {
        if (current_player) cout << "Cross player won!";
        else cout << "Circle player won!";

        return 0;
    }
}