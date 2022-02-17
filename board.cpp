#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "board.h"
using namespace std;

void chooseboardsize();
void printboard(int,int);
void setstone_printboard();
int a;
int board[1000][1000];

void chooseboardsize(){
    /*do{
    cout <<  "Choose board size (9,13,19): ";
    cin >> a;
    if(a != 9&&a != 13&&a != 19) cout << "Please input correct number" << endl;
    }while(a != 9&&a != 13&&a != 19);*/
    a=9;
    if(a==9){
        for(int x=0;x<11;x++){
            for(int y=0;y<11;y++){
                board[y][x] = board_9x9[y][x];
            }
        }
    }
    if(a==13){
        for(int x=0;x<15;x++){
            for(int y=0;y<15;y++){
                board[y][x] = board_13x13[y][x];
            }
        }
    }
    if(a==19){
        for(int x=0;x<21;x++){
            for(int y=0;y<21;y++){
                board[y][x] = board_19x19[y][x];
            }
        }
    }
}

void printboard(int a,int board[][1000]){
    for(int i=0;i<a+1;i++){
        if(i !=0)
        cout << i <<'\t';
        for(int y =0;y<a+2;y++){
            if(board[i][y]==0) cout << "."  << " ";
            if(board[i][y]==1) cout << "x"  << " ";
            if(board[i][y]==2) cout << "y"  << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void setstone_printboard(){
    int x,y;
    cout << "player 1: : ";
    cin >> x >> y;
    while(board[x][y] !=0){
        cout << "Alredy" << endl;
        cout << "player 1 : ";
        cin >> x >> y;
    }
    board[x][y] = 1;
    printboard(a,board);
    cout << "player 2 : ";
    cin >> x >> y;
   while(board[x][y] !=0){
        cout << "Alredy"<< endl;
        cout << "player 2 : ";
        cin >> x >> y;
    }
    board[x][y] = 2;
    printboard(a,board);

}






int main(){
    int g=1;
    chooseboardsize();
    printboard(a,board);
    while(g != 0){
        setstone_printboard();
        cout << " GGGG: ";
        cin >> g;
    }
    
}