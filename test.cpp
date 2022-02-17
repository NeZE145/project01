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
char pieces[] = {'.','#','o',' ',' ','b','w',' ','+'};
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

void clear_block(){
    for (int i=0; i<block.size(); i++) board[block[i]] = EMPTY;
}

void restore_board(){
    liberties = {}, block = {};

    for (int i=0; i < board_range*board_range; i++){
        if (board[i] != OFFBOARD) board[i] &= 3;
    }
}

void clear_board(){
    liberties = {}, block = {};

    for (int i=0; i < board_range*board_range; i++){
        if (board[i] != OFFBOARD) board[i] = 0;
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

        board[square] |= MARKER;

        count(square - board_range , color);
        count(square - 1 , color);
        count(square + board_range, color);
        count(square + 1, color);
        
    } 
    else if (piece == EMPTY) {
        board[square] |= LIBERTY;
        liberties.push_back(square);
    }
}

// loop แล้วตรวจว่าล้อมไหมถ้าล้อมให้ลบ (ยังไม่เสร็จ)
void check_stone(int color){
    int oppcolor;
    if (color == BLACK) oppcolor = WHITE;
    else if (color == WHITE) oppcolor = BLACK;

    // check.push_back(i);
    for (int j=0; j<check.size(); j++){
       count(check[j], color);
       for (int k=0; k<liberties.size(); k++){
           if (oppcolor != board[liberties[k]]) return;
       }
       clear_block;
    }
}

void place_stone(int color){
    string position;
    int i;
    // int oppcolor;
    // if (color == BLACK) oppcolor = WHITE;
    // else if (color == WHITE) oppcolor = BLACK;
    
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

    // count(i, color);
    // clear_block();
    // restore_board();


    check.push_back(i);

    check_stone(color);
    
    // for (int j=0; j<check.size(); j++){
    //    count(check[j], color);
    //    for (int k=0; k<liberties.size(); k++){
    //        if (oppcolor != board[liberties[k]]) return;

    //    }
    // }


    // clear_block();

    //print board
    print_board();
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

void switch_player(){
    int turn = 1;
    while (true) {
        // player one's turn
        cout <<"\n\n";
        cout <<"[Turn " <<turn << "] Player 1 !!!" <<"\n\n";
        place_stone(BLACK);
        print_detail();
        restore_board();

        // player two's turn
        cout <<"\n\n";
        cout <<"[Turn " <<turn << "] Player 2 !!!" <<"\n\n";
        place_stone(WHITE);
        print_detail();
        restore_board();

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
