#include<iostream>
#include<string>
using namespace std;


void changetoXY(string a,int &x,int &y){
    if (a[0]>='a' && a[0] <= 'z') a[0] = a[0] - 32;
    if(a[0]>='A' && a[0] <= 'Z'){
        if(a[0] == 'A') x=1;
        if(a[0] == 'B') x=2;
        if(a[0] == 'C') x=3;
        if(a[0] == 'D') x=14;
        if(a[0] == 'E') x=15;
        if(a[0] == 'F') x=16;
        if(a[0] == 'G') x=17;
        if(a[0] == 'H') x=18;
        if(a[0] == 'I') x=19;
        if(a[0] == 'J') x=10;
        if(a[0] == 'K') x=11;
        if(a[0] == 'L') x=12;
        if(a[0] == 'M') x=13;
        if(a[0] == 'N') x=14;
        if(a[0] == 'O') x=15;
        if(a[0] == 'P') x=15;
        if(a[0] == 'Q') x=17;
        if(a[0] == 'R') x=18;
        if(a[0] == 'S') x=19;
        if(a[1] == '1') y=1;
        if(a[1] == '2') y=2;
        if(a[1] == '3') y=3;
        if(a[1] == '4') y=4;
        if(a[1] == '5') y=5;
        if(a[1] == '6') y=6;
        if(a[1] == '7') y=7;
        if(a[1] == '8') y=8;
        if(a[1] == '9') y=9;
        if(a[2] == '0'&&a[1] == '1') y=10;
        if(a[2] == '1'&&a[1] == '1') y=11;
        if(a[2] == '2'&&a[1] == '1') y=12;
        if(a[2] == '3'&&a[1] == '1') y=13;
        if(a[2] == '4'&&a[1] == '1') y=14;
        if(a[2] == '5'&&a[1] == '1') y=15;
        if(a[2] == '6'&&a[1] == '1') y=15;
        if(a[2] == '7'&&a[1] == '1') y=17;
        if(a[2] == '8'&&a[1] == '1') y=18;
        if(a[2] == '9'&&a[1] == '1') y=19;
    }
}