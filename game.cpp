#include <ctime>
#include <iostream>
#include "game.h"

FIELD g_board[3][3] = { {FLD_EMPTY, FLD_EMPTY, FLD_EMPTY},
                        {FLD_EMPTY, FLD_EMPTY, FLD_EMPTY},
                        {FLD_EMPTY, FLD_EMPTY, FLD_EMPTY}};

bool game_start() {
    // wylosowanie gracza
    int random_player;

    srand((unsigned int) time(NULL));
    random_player = rand() % 2;

    return random_player;
}


bool move_made(unsigned current_player) {
    int choice;
    char current_sign;
    int column;
    int row;

    if (current_player) current_sign = 'X';
    else current_sign = 'O';

    std::cout << "Where do you wanna put " << current_sign << " ?" << std::endl;
    std::cin >> choice;
    while (choice > 9 || choice < 1) {
        std::cout << "You can choose only from 1 to 9" << std::endl;
        std::cin >> choice;
    }
    choice = choice - 1;
    row = choice / 3;
    column = choice % 3;

    while (g_board[column][row] != FLD_EMPTY) {
        std::cout << "This place was already filled. Where do you wanna put " << current_sign << " ?" << std::endl;
        std::cin >> choice;
        choice = choice - 1;
        while (choice > 9 || choice < 1) {
            std::cout << "You can choose only from 1 to 9" << std::endl;
            std::cin >> choice;
        }
        choice = choice - 1;
        row = choice / 3;
        column = choice % 3;
    }

    if (current_player == SGN_CROSS) g_board[column][row] = FLD_CROSS;
    else if (current_player == SGN_CIRCLE) g_board[column][row] = FLD_CIRCLE;

}


bool draw_board() {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (g_board[column][row] == FLD_EMPTY) std::cout << ' ';
            else if (g_board[column][row] == FLD_CROSS) std::cout << 'X';
            else if (g_board[column][row] == FLD_CIRCLE) std::cout << 'O';
        }
        std::cout << std::endl;
    }
}

bool check_if_won() {
    using namespace std;

    for (int row = 0; row < 3; row++) {
        if (g_board[0][row] != FLD_EMPTY && g_board[1][row] != FLD_EMPTY && g_board[2][row] != FLD_EMPTY) {
            if (g_board[0][row] == g_board[1][row] == g_board[2][row]) return 1;
        }
    }

    for (int column = 0; column < 3; column++) {
        if (g_board[column][0] != FLD_EMPTY && g_board[column][1] && g_board[column][2] != FLD_EMPTY){
            if (g_board[column][0] == g_board[column][1] == g_board[column][2]) return 1;
        }
    }

    if (g_board[0][0] != FLD_EMPTY && g_board[1][1] != FLD_EMPTY && g_board[2][2] != FLD_EMPTY){
        if (g_board[0][0] == g_board[1][1] == g_board[2][2]) return 1;
    }
    return 0;
}

