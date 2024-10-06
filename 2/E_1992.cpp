#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int N;
int visited[64][64];
char V[64][64];

stack<char> s;

string quard(int y, int x, int size){
    if(size == 1) return string(1, V[y][x]);
    char b = V[y][x];
    string ret = "";
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(b != V[i][j]){
                ret += '(';
                ret += quard(y, x, size / 2);
                ret += quard(y, x + size / 2, size / 2);
                ret += quard(y + size / 2, x, size / 2);
                ret += quard(y + size / 2, x + size / 2, size / 2);
                ret += ')';
                return ret;
            }
        }
    }
    return string(1, V[y][x]);
}
int main(){
    cin >> N;
    string s = "";
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < N; j++){
            V[i][j] = s[j];
        }
    }

    cout << quard(0, 0, N) << '\n';
    return 0;
}
