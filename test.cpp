#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int board_9x9[] = {
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

string coords_9x9[] = {
    "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX",
    "XX", "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "I9", "XX",
    "XX", "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "I8", "XX",
    "XX", "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "I7", "XX",
    "XX", "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "I6", "XX",
    "XX", "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "I5", "XX",
    "XX", "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "I4", "XX",
    "XX", "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "I3", "XX",
    "XX", "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "I2", "XX",
    "XX", "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1", "XX",
    "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"
};

int board_13x13[] = {
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

string coords_13x13[] = {
    "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX",
    "XX", "A13","B13","C13","D13","E13","F13","G13","H13","I13","J13","K13","L13","M13","XX",
    "XX", "A12","B12","C12","D12","E12","F12","G12","H12","I12","J12","K12","L12","M12","XX",
    "XX", "A11","B11","C11","D11","E11","F11","G11","H11","I11","J11","K11","L11","M11","XX",
    "XX", "A10","B10","C10","D10","E10","F10","G10","H10","I10","J10","K10","L10","M10","XX",
    "XX", "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "I9", "J9", "K9", "L9", "M9", "XX",
    "XX", "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "I8", "J8", "K8", "L8", "M8", "XX",
    "XX", "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "I7", "J7", "K7", "L7", "M7", "XX",
    "XX", "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "I6", "J6", "K6", "L6", "M6", "XX",
    "XX", "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "I5", "J5", "K5", "L5", "M5", "XX",
    "XX", "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "I4", "J4", "K4", "L4", "M4", "XX",
    "XX", "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "I3", "J3", "K3", "L3", "M3", "XX",
    "XX", "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "I2", "J2", "K2", "L2", "M2", "XX",
    "XX", "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1", "J1", "K1", "L1", "M1", "XX",
    "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"
};

int board_19x19[] = {
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

string coords_19x19[] = {
    "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX",
    "XX", "A19","B19","C19","D19","E19","F19","G19","H19","I19","J19","K19","L19","M19","N19","O19","P19","Q19","R19","S19","XX",
    "XX", "A18","B18","C18","D18","E18","F18","G18","H18","I18","J18","K18","L18","M18","N18","O18","P18","Q18","R18","S18","XX",
    "XX", "A17","B17","C17","D17","E17","F17","G17","H17","I17","J17","K17","L17","M17","N17","O17","P17","Q17","R17","S17","XX",
    "XX", "A16","B16","C16","D16","E16","F16","G16","H16","I16","J16","K16","L16","M16","N16","O16","P16","Q16","R16","S16","XX",
    "XX", "A15","B15","C15","D15","E15","F15","G15","H15","I15","J15","K15","L15","M15","N15","O15","P15","Q15","R15","S15","XX",
    "XX", "A14","B14","C14","D14","E14","F14","G14","H14","I14","J14","K14","L14","M14","N14","O14","P14","Q14","R14","S14","XX",
    "XX", "A13","B13","C13","D13","E13","F13","G13","H13","I13","J13","K13","L13","M13","N13","O13","P13","Q13","R13","S13","XX",
    "XX", "A12","B12","C12","D12","E12","F12","G12","H12","I12","J12","K12","L12","M12","N12","O12","P12","Q12","R12","S12","XX",
    "XX", "A11","B11","C11","D11","E11","F11","G11","H11","I11","J11","K11","L11","M11","N11","O11","P11","Q11","R11","S11","XX",
    "XX", "A10","B10","C10","D10","E10","F10","G10","H10","I10","J10","K10","L10","M10","N10","O10","P10","Q10","R10","S10","XX",
    "XX", "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "I9", "J9", "K9", "L9", "M9", "N9", "O9", "P9", "Q9", "R9", "S9", "XX",
    "XX", "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "I8", "J8", "K8", "L8", "M8", "N8", "O8", "P8", "Q8", "R8", "S8", "XX",
    "XX", "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "I7", "J7", "K7", "L7", "M7", "N7", "O7", "P7", "Q7", "R7", "S7", "XX",
    "XX", "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "I6", "J6", "K6", "L6", "M6", "N6", "O6", "P6", "Q6", "R6", "S6", "XX",
    "XX", "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "I5", "J5", "K5", "L5", "M5", "N5", "O5", "P5", "Q5", "R5", "S5", "XX",
    "XX", "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "I4", "J4", "K4", "L4", "M4", "N4", "O4", "P4", "Q4", "R4", "S4", "XX",
    "XX", "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "I3", "J3", "K3", "L3", "M3", "N3", "O3", "P3", "Q3", "R3", "S3", "XX",
    "XX", "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "I2", "J2", "K2", "L2", "M2", "N2", "O2", "P2", "Q2", "R2", "S2", "XX",
    "XX", "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1", "J1", "K1", "L1", "M1", "N1", "O1", "P1", "Q1", "R1", "S1", "XX",
    "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"
};


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
char pieces[] = {'.','#','o',' ',' ','#','o',' ','.'};
char files[] = "     a b c d e f g h i j k l m n o p q r s t";
vector<int> liberties = {}, block = {};

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
    //loop ask board size
    do {
    cout << "Select board size (9, 13, 19) : ";
    cin >> board_size;
    }while (board_size != 9 && board_size != 13 && board_size != 19);

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

        //move around square
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
    // init opposite color
    int oppcolor;
    if (color == BLACK) oppcolor = WHITE;
    else if (color == WHITE) oppcolor = BLACK;

    // loop over the board
    for (int square=0; square<board_range*board_range; square++){
        int piece = board[square];

        // skip offboard squares
        if (piece == OFFBOARD) continue;
        
        // if stone belongs to the given color
        if (piece & color){
            // count liberties
            count(square, color);

            // if no liberties left remove the stones
            if (liberties.size() == 0) clear_block();
            restore_board();
        }
        // if stone belongs to the opposite color
        else if (piece & oppcolor){
            // count liberties
            count(square, oppcolor);

            // if no liberties left remove the stones
            if (liberties.size() == 0) clear_block();
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
    captures(color);

    //print board
    print_board();
}

bool endgame(){
    int w=0,b=0;
    int total_size = (int) pow(board_size+2, 2);
    if (board_size == 9){
        for (int i=0; i<total_size; i++){
            if(board[i]==WHITE) w++;
            if(board[i]==BLACK) b++;
        }
    } else if (board_size == 13){
        for (int i=0; i<total_size; i++){
            if(board[i]==WHITE) w++;
            if(board[i]==BLACK) b++;
        }
    } else if (board_size == 19){
        for (int i=0; i<total_size; i++){
            if(board[i]==WHITE) w++;
            if(board[i]==BLACK) b++;
        }
    }

    cout << "WHITE:"<<w<< endl<<"Black:"<<  b;
    if (board_size == 9){
        if(w-b>=5){
            cout<<endl<< "WHITE WIN";
            return false;
        }
        if(b-w>=5){
            cout<<endl<<"BLACK WIN";
            return false;
        }
    }
    if (board_size == 13){
        if(w-b>=10){
            cout<<endl<<"WHITE WIN";
            return false;
        }
        if(b-w>=10){
            cout<<endl<<"BLACK WIN";
            return false;
        }
    }
    if (board_size == 19){
        if(w-b>=15){
            cout<<endl<<"WHITE WIN";
            return false;
        }
        if(b-w>=15){
            cout<<endl<<"BLACK WIN";
            return false;
        }
    }
    return true;

}

void switchTurn(){
    int turn = 1;
    do{
        // player one's turn
        cout <<"\n\n";
        cout <<"[Turn " <<turn << "] Player 1 !!!" <<"\n\n";
        place_stone(BLACK);
        endgame();
        // player two's turn
        cout <<"\n\n";
        cout <<"[Turn " <<turn << "] Player 2 !!!" <<"\n\n";
        place_stone(WHITE);

        // next turn
        turn++;

    }while(endgame());
}

int main() {
    //set board 
    set_board();
    print_board();

    // take turns
    switchTurn();

    return 0;
}
