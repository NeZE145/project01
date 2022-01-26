#include<iostream>

using namespace std;




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
}


int main(){
    board();
    return 0;
}