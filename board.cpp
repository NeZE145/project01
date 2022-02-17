#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "board.h"
#include "xy.cpp"

using namespace std;
  


void chooseboardsize();
void printboard(int,int);
void setstone_printboard_deletestone();
int a;
int board[1000][1000];

void chooseboardsize(){
    /*do{
    cout <<  "Choose board size (9,13,19): ";
    cin >> a;
    if(a != 9&&a != 13&&a != 19) cout << "Please input correct number" << endl;
    }while(a != 9&&a != 13&&a != 19);*/
    a=13;
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
    cout << '\t';
    char d;
    if(a==9){
    for (d = 'A'; d <= 'i'; d++)
    {
        cout << d <<" ";
    }}
    if(a==13){
    for (d = 'A'; d <= 'M'; d++)
    {
        cout << d <<" ";
    }}
    if(a==19){
    for (d = 'A'; d <= 'S'; d++)
    {
        cout << d <<" ";
    }}
    cout << endl;
}



void floodFillUtil(int board[][1000], int x, int y, int prevV, int newV)
{
    if (x < 0 || x >= a+2 || y < 0 || y >= a+2)
        return;
    if (board[x][y] != prevV)
        return;
 
    board[x][y] = newV;
 
    floodFillUtil(board, x+1, y, prevV, newV);
    floodFillUtil(board, x-1, y, prevV, newV);
    floodFillUtil(board, x, y+1, prevV, newV);
    floodFillUtil(board, x, y-1, prevV, newV);
}
 
void replaceSurroundedforplayer2(int board[][1000])
{
   for (int i=0; i<a+2; i++)
      for (int j=0; j<a+2; j++)
          if (board[i][j] == 1)
             board[i][j] = 6;
 
   for (int i=0; i<a+2; i++) 
      if (board[i][0] == 6)
        floodFillUtil(board, i, 0, 6, 1);
   for (int i=0; i<a+2; i++)
      if (board[i][a+2-1] == 6)
        floodFillUtil(board, i, a+2-1, 6, 1);
   for (int i=0; i<a+2; i++)
      if (board[0][i] == 6)
        floodFillUtil(board, 0, i, 6, 1);
   for (int i=0; i<a+2; i++)  
      if (board[a+2-1][i] == 6)
        floodFillUtil(board, a+2-1, i, 6, 1);

   for (int i=0; i<a+2; i++)
      for (int j=0; j<a+2; j++)
         if (board[i][j] == 6)
             board[i][j] = 0;
 
}
void setstone_printboard_deletestone(){
    int x=0,y=0;
    string position;

    cout << "Player 1 select position (Example A4, B5, ...): ";
    cin >> position;
    if (position[0]>='a' && position[0] <= 'z') position[0] = position[0] - 32;
    changetoXY(position,y,x);
    while(board[x][y] !=0){
        cout << "Please input valid place" << endl;
        cout << "Player 1 select position (Example A4, B5, ...): ";
        cin >> position;
        if (position[0]>='a' && position[0] <= 'z') position[0] = position[0] - 32;
        changetoXY(position,y,x);
    }
    board[x][y] = 1;
    printboard(a,board);
    cout << "Player 2 select position (Example A4, B5, ...): ";
    cin >> position;
    if (position[0]>='a' && position[0] <= 'z') position[0] = position[0] - 32;
    changetoXY(position,y,x);
    while(board[x][y] !=0){
        cout << "Please input valid place" << endl;
        cout << "Player 1 select position (Example A4, B5, ...): ";
        cin >> position;
        if (position[0]>='a' && position[0] <= 'z') position[0] = position[0] - 32;
        changetoXY(position,y,x);
    }
    board[x][y] = 2;
    replaceSurroundedforplayer2(board);
    printboard(a,board);

}













int main(){
    int g=1;
    chooseboardsize();
    printboard(a,board);
    while(g != 0){
        setstone_printboard_deletestone();
        cout << " GGGG: ";
        cin >> g;
    }
    
}