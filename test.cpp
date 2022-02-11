#include <iostream>
#include <cmath>
#include <vector>
#include "board.h"
using namespace std;

//stones
int EMPTY = 0;
int BLACK = 1;
int WHITE = 2;
int MARKER = 4;
int OFFBOARD = 7;
int LIBERTY = 8;

//Variable
int board_size, board_range;
char pieces[] = {'.','#','o',' ',' ','b','w',' ','+'};
char files[] = "     a b c d e f g h i j k l m n o p q r s t";

//count
vector<int> liberties = {}, block = {};

//define function
void print_board(int board[], int board_size, char pieces[], char files[]){
    board_range = board_size + 2;
    int square, stone, rank;

    // loop rows
    for (int row=0; row<board_range; row++){
        //loop columns
        for (int col=0; col<board_range; col++){
            square = row * board_range + col;
            stone = board[square];

            //print rank
            if (col == 0 && row > 0 && row < board_range - 1){
                rank = board_range - 1 - row;
                if (rank < 10) cout <<" " <<rank <<" ";
                else cout <<rank <<" ";
            }
            //print board
            cout << pieces[stone] <<" ";
        }
        //print new line
        cout <<endl;
    }
    //print files
    for (int i=0; i<board_range*2; i++) cout <<files[i];
    cout <<endl;
}

void set_board(int board[], string coord[], int board_size, int total_size){
    //duplicate board
    if (board_size == 9){
        for (int i=0; i<total_size; i++){
        board[i] = board_9x9[i];
        }
    } else if (board_size == 13){
        for (int i=0; i<total_size; i++){
        board[i] = board_13x13[i];
        }
    } else if (board_size == 19){
        for (int i=0; i<total_size; i++){
        board[i] = board_19x19[i];
        }
    }

    //duplicate coord
    if (board_size == 9){
        for (int i=0; i<total_size; i++){
        coord[i] = coords_9x9[i];
        }
    } else if (board_size == 13){
        for (int i=0; i<total_size; i++){
        coord[i] = coords_13x13[i];
        }
    } else if (board_size == 19){
        for (int i=0; i<total_size; i++){
        coord[i] = coords_19x19[i];
        }
    }
}

void count(int board[], int square, int color){ 
    // init piece
    int piece = board[square];
    
    // skip offboard squares
    if (piece == OFFBOARD) return;
    
    // if there's a stone at square
    if (piece == color){
        // save stone's coordinate
        block.push_back(square);

        board[square] |= MARKER;

        count(board, square - board_range , color);
        count(board, square - 1 , color);
        count(board, square + board_range, color);
        count(board, square + 1, color);
        
    } 
    else if (piece == EMPTY) {
        board[square] |= LIBERTY;
        liberties.push_back(square);
    }
}

void clear_stone(int board[]){
    for (int i=0; i<block.size(); i++) board[block[i]] = EMPTY;
}

void restore_board(int board[]){
    liberties = {}, block = {};

    for (int i=0; i < board_range*board_range; i++){
        if (board[i] != OFFBOARD) board[i] &= 3;
    }
}

// just test place stone function
void place_stone(int board[], string coord[], int board_size){
    string position;
    
    // loop ask position
    while (true) {
        // select position
        cout << "select position (Example A4, B5, ...): ";
        cin >> position;
    
        // convert to uppercase
        if (position[0]>='a' && position[0] <= 'z') position[0] = position[0] - 32;

        // find position
        int i=0;
        while (coord[i] != "\0"){
            if (coord[i] == position) break;
            i++;
        }
        if (board[i] == EMPTY) {
            board[i] = BLACK;
            break;
        } else cout <<"Alredy Exist !" <<endl; 
    }

    print_board(board, board_size, pieces, files);
}

int main() {
    //loop ask board size
    do {
    cout << "Select board size (9, 13, 19) : ";
    cin >> board_size;
    }while (board_size != 9 && board_size != 13 && board_size != 19);

    //set board size
    int total_size = (int) pow(board_size+2, 2);
    int board[total_size];
    string coord[total_size];
    set_board(board, coord, board_size, total_size);

    print_board(board, board_size, pieces, files);

    // just test 5 times
    for (int k=0; k<5; k++){
        place_stone(board, coord, board_size);
    };

    return 0;
}
