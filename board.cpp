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





void floodFillUtil(int board[][1000], int x, int y, int prevV, int newV)
{
    // Base cases
    if (x < 0 || x >= a+2 || y < 0 || y >= a+2)
        return;
    if (board[x][y] != prevV)
        return;
 
    // Replace the color at (x, y)
    board[x][y] = newV;
 
    // Recur for north, east, south and west
    floodFillUtil(board, x+1, y, prevV, newV);
    floodFillUtil(board, x-1, y, prevV, newV);
    floodFillUtil(board, x, y+1, prevV, newV);
    floodFillUtil(board, x, y-1, prevV, newV);
}
 
// Returns size of maximum size subsquare matrix
// surrounded by 'X'
void replaceSurrounded(int board[][1000])
{
   // Step 1: Replace all 1  with 6
   for (int i=0; i<a+2; i++)
      for (int j=0; j<a+2; j++)
          if (board[i][j] == 1)
             board[i][j] = 6;
 
   // Call floodFill for all 6 lying on edges
   for (int i=0; i<a+2; i++)   // Left side
      if (board[i][0] == 6)
        floodFillUtil(board, i, 0, 6, 1);
   for (int i=0; i<a+2; i++)  //  Right side
      if (board[i][a+2-1] == 6)
        floodFillUtil(board, i, a+2-1, 6, 1);
   for (int i=0; i<a+2; i++)   // Top side
      if (board[0][i] == 6)
        floodFillUtil(board, 0, i, 6, 1);
   for (int i=0; i<a+2; i++)  // Bottom side
      if (board[a+2-1][i] == 6)
        floodFillUtil(board, a+2-1, i, 6, 1);
 
   // Step 3: Replace all 6 with 'X'
   for (int i=0; i<a+2; i++)
      for (int j=0; j<a+2; j++)
         if (board[i][j] == 6)
             board[i][j] = 0;
 
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
    replaceSurrounded(board);
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