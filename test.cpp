#include<iostream>

using namespace std;

const int N = 9; // เปลี่ยนได้ตามขนาด นั้นนี้ตั้งค่าเริ่มต้นไว้เฉยๆ
const int M = 9;

void pullpiecse(bool [][M], int,int);

void pull(const bool [][M]);

void board(){
    char a='a';
    for(int i=0;i<9;i++){
        cout << 9-i << "  ";
        for (int j=0;j<9;j++){
            cout << "."<< " ";
        }
        cout << endl;
    }
    cout << endl<<"   ";
    for(int i=0;i<9;i++){
        cout <<a++<<" ";
    }
    cout << "\n";
}


int main(){
    board();
    bool image[N][M] = {};
    int x, y;
    do
    {
        if (x==0 && y ==0) break; //ใส่เงื่อนไขนับแต้ม
        else{
            cout << "Player1 Input your location: ";
            cin >> x >> y;
            pullpiecse(image,x,y);
            pull(image);
        }
    } while (1);
    return 0;
}

void pullpiecse(bool image[][M], int x, int y){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (x-1 == i && y-1 == j) image[i][j]=1;
        }
        
    }
    
}

void pull(const bool image[][M]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (image[i][j]) cout << " #";   
            else cout << " .";
        }
        cout << "\n";
    }
    
}




