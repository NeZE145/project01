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
int board[500];
string coord[500];
int board_size, board_range;
// char pieces[] = {'.','#','o',' ',' ','b','w',' ','+'};
char pieces[] = {'.','#','o',' ',' ','#','o',' ','.'};
char files[] = "     a b c d e f g h i j k l m n o p q r s t";
vector<int> liberties = {}, block = {}, check = {};

//define function
void print_board(){
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

void set_board(){
    int total_size = (int) pow(board_size+2, 2);
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

void print_detail(){
    cout <<"\n";
    cout <<"block : ";
    for (int i=0; i<block.size(); i++) cout<<block[i] <<" ";
    cout << "\n";
    cout <<"liberties : ";
    for (int i=0; i<liberties.size(); i++) cout<<liberties[i] <<" ";
    cout << "\n";
}

void clear_block(){
    // remove captured stones
    for (int i=0; i<block.size(); i++) board[block[i]] = EMPTY;
}

void restore_board(){
    liberties = {}, block = {};
    //unmark stones
    for (int i=0; i < board_range*board_range; i++){
        if (board[i] != OFFBOARD) board[i] &= 3;
    }
}

void clear_board(){
    liberties = {}, block = {};

    for (int i=0; i < board_range*board_range; i++){
        if (board[i] != OFFBOARD) board[i] = EMPTY;
    }
}

void count(int square, int color){ 
    // init piece
    int piece = board[square];
    
    // skip offboard squares
    if (piece == OFFBOARD) return;
    
    // if there's a stone at square
    if (piece && piece & color && (piece & MARKER) == 0){
        // save stone's coordinate
        block.push_back(square);
        // mark the stone
        board[square] |= MARKER;

        count(square - board_range , color);
        count(square - 1 , color);
        count(square + board_range, color);
        count(square + 1, color);
        
    } 
    else if (piece == EMPTY) {
        // mark liberty
        board[square] |= LIBERTY;
        // save liberty
        liberties.push_back(square);
    }
}

void captures(int color){
    int oppcolor;
    if (color == BLACK) oppcolor = WHITE;
    else if (color == WHITE) oppcolor = BLACK;

    //loop find 
    for (int j=0; j<check.size(); j++){
        count(check[j], color);

        // if no liberties left remove the stones
        if (liberties.size() == 0){
            clear_block();
            restore_board();
        }
    }
}

void place_stone(int color){
    string position;
    int i;
    
    // loop ask position
    while (true) {
        // select position
        cout <<"select position (Example A4, B5, ...): ";
        cin >> position;
    
        // convert to uppercase
        if (position[0]>='a' && position[0] <= 'z') position[0] = position[0] - 32;

        // find position
        i=0;
        while (coord[i] != "\0"){
            if (coord[i] == position) break;
            i++;
        }
        if (board[i] == EMPTY || board[i] == LIBERTY) {
            board[i] = color;
            break;
        } else cout <<"Alredy Exist !" <<endl; 
    }

    // check captures
    check.push_back(i);
    captures(color);

    //print board
    print_board();
}

void switch_player(){
    int turn = 1;
    while (true) {
        // player one's turn
        cout <<"\n\n";
        cout <<"[Turn " <<turn << "] Player 1 !!!" <<"\n\n";
        place_stone(BLACK);
        restore_board();
        clear_block();

        // player two's turn
        cout <<"\n\n";
        cout <<"[Turn " <<turn << "] Player 2 !!!" <<"\n\n";
        place_stone(WHITE);
        restore_board();
        clear_block();
 
        // next turn
        turn++;
    }
}

int main() {
    //loop ask board size
    do {
    cout << "Select board size (9, 13, 19) : ";
    cin >> board_size;
    }while (board_size != 9 && board_size != 13 && board_size != 19);

    //set board size & print
    set_board();
    print_board();

    // take turns
    switch_player();

    return 0;
}
