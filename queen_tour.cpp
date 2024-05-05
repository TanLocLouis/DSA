#include <iostream>

using namespace std;

const int board_size = 8;

void show_board(int board[8][8]) {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            cout << board[i][j] << char(32);
        }
        cout << endl;
    }
    cout << endl;
}

void knight(int step, int x, int y, int board[8][8], bool col[8], bool main_diag[16], bool sub_diag[16]) {
    board[x][y] = step;
    col[y] = true; // row and col
    main_diag[x - y + board_size - 1] = true; // main diagonal
    sub_diag[x + y] = true; // sub diagonal

    // show result
    if (step == board_size) {
        show_board(board);
        return;
    }

    // next move
    for (int i = 0; i < board_size; i++) {
        int next_x = x + 1;
        int next_y = i;

        if (next_x >= 0 && next_x < board_size && next_y >= 0 && next_y < board_size) {
            if (board[next_x][next_y] == 0 && !col[next_y] && !main_diag[next_x - next_y + board_size - 1] && !sub_diag[next_x + next_y]) {
                // choose
                knight(step + 1, next_x, next_y, board, col, main_diag, sub_diag);
                // reverse
                board[next_x][next_y] = 0;
                col[next_y] = false;
                main_diag[next_x - next_y + board_size - 1] = false;
                sub_diag[next_x + next_y] = false;
            }
        }
    }
}

int main() {
    int board[8][8] = {0};

    bool col[8] = {0};
    bool main_diag[16] = {0};
    bool sub_diag[16] = {0};

    knight(1, 0, 5, board, col, main_diag, sub_diag);

    return 0;
}