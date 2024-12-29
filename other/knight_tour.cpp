#include <iostream>

using namespace std;

const int board_size = 5;

int dir_x[8] = {-1,-2,1,2,-1,-2,1,2};
int dir_y[8] = {-2,-1,-2,-1,2,1,2,1};

void show_board(int board[8][8]) {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            cout << board[i][j] << char(32);
        }
        cout << endl;
    }
    cout << endl;
}

void knight(int step, int x, int y, int board[8][8]) {
    board[x][y] = step;
    // show result
    if (step == board_size * board_size) {
        show_board(board);
        return;
    }

    // next move
    for (int i = 0; i < 8; i++) {
        int next_x = x + dir_x[i];
        int next_y = y + dir_y[i];

        if (next_x >= 0 && next_x < board_size && next_y >= 0 && next_y < board_size) {
            if (board[next_x][next_y] == 0) {
                // choose
                knight(step + 1, next_x, next_y, board);
                // reverse
                board[next_x][next_y] = 0;
            }
        }
    }
}

int main() {
    int board[8][8] = {0};

    knight(1, 1, 1, board);

    return 0;
}