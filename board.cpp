#include<iostream>

using namespace std;
const int N = 9; // เปลี่ยนได้ตามขนาด นั้นนี้ตั้งค่าเริ่มต้นไว้เฉยๆ
const int M = 9;

void pullpiecse(bool [][M], int,int);

void pull(const bool [][M]);

void board(const bool[][M],const bool[][M]);


    

int main(){
    bool player1[N][M] = {};
    bool player2[N][M] = {};
    int x, y,w,z,g;

        do{
            board(player1,player2);
            cout << "Player1 Input your location: ";
            do{
                cin >> x >> y;
                if(player1[x-1][y-1]==1 || player2[x-1][y-1] == 1)
                    cout << "Alredy Exist"<<endl << "Player1 Input your location: ";
            }while(player1[x-1][y-1]==1|| player2[x-1][y-1] == 1);
            player1[x-1][y-1] = 1;
           board(player1,player2);
            cout << "Player2 Input your location: ";
            do{
                cin >> w >> z;
                if(player1[w-1][z-1]==1 || player2[w-1][z-1] == 1)
                    cout << "Alredy Exist"<<endl << "Player2 Input your location: ";
            }while(player1[w-1][z-1]==1|| player2[w-1][z-1] == 1);
            player2[w-1][z-1] = 1;
           board(player1,player2);
           cout << endl<< "0 to stop ";
           cin >> g;
           cout << endl;
        }while(g!=0);
           

      
    return 0;
}


void board(const bool A[][M],const bool B[][M]){
    for(int i=0;i<M;i++){
        cout << i+1 << "  ";
        for (int j=0;j<M;j++){
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
    for(int i=0;i<M;i++){
        cout << i+1 <<" ";
    }
    cout << "\n";


}













