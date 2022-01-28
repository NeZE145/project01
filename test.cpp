
#include<iostream>

using namespace std;

const int N = 9;
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
    cout << "Input your location: ";
    cin >> x >> y;
    pullpiecse(image,x,y);
    pull(image);
    return 0;
}

void pullpiecse(bool image[][M], int x, int y){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (x == i && y == j) image[i][j]=1;
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
