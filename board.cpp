#include<iostream>

using namespace std;
const int N = 9; // เปลี่ยนได้ตามขนาด นั้นนี้ตั้งค่าเริ่มต้นไว้เฉยๆ
const int M = 9;

void pullpiecse(bool [][M], int,int);

void pull(const bool [][M]);

void board(const bool[][M],const bool[][M],int );

    


int main(){
    bool player1[N][M] = {};
    bool player2[N][M] = {};
    int x, y,w,z,g;
    int turn =1;
    //ใส่หมากยังไม่ตรง

        do{
            board(player1,player2,turn);
            cout << "Player1 Input your location: ";
            cin >> x >> y;
            player1[x][y] = 1;
            board(player1,player2,turn);
           cout << "Player2 Input your location: ";
           cin >> w >> z;
           player2[w][z] = 1;
           board(player1,player2,turn);
           cout << "0 to stop ";
           cin >> g;
        }while(g!=0);
           

      
    return 0;
}


void board(const bool A[][M],const bool B[][M],int turn){
    char a='a';
    for(int i=0;i<9;i++){
        cout << 9-i << "  ";
        for (int j=0;j<9;j++){
            if(A[j][i])
                cout << " *";
            if(B[j][i])
                cout << " #";
            if(A[j][i] ==0 && B[j][i]==0)
                cout << " .";
        }
            cout << endl;

    }
    cout << "    ";
    for(int i=0;i<9;i++){
        cout << a++<<" ";
    }
    cout << "\n";

}














