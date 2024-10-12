#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int R, C;
char V[20][20];
int visited[20][20];
int eng[26];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int answer = 0;

void DFS(int y, int x){
    answer = max(answer, visited[y][x]);
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
        if(visited[ny][nx] != 0) continue;
        if(eng[V[ny][nx] - 'A'] != 0) continue;
        visited[ny][nx] = visited[y][x] + 1;
        eng[V[ny][nx] - 'A']++;
        DFS(ny, nx);
        eng[V[ny][nx] - 'A']--;
        visited[ny][nx] = 0;
    }
    return;
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        string s;
        cin >> s;
        for(int j = 0; j < C; j++){
            V[i][j] = s[j];
        }
    }

    visited[0][0] = 1;
    eng[V[0][0] - 'A']++;
    DFS(0, 0);
    
    cout << answer << '\n';

    return 0;
}
