#include <stdio.h>
#include <iostream>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int N;
int visited[100][100];
int V[100][100];

void DFS(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if((nx < 0) || (nx >= N) || (ny < 0) || (ny >= N)) continue;
        if(visited[ny][nx] == 0 && V[ny][nx] > N) DFS(ny, nx);
    }
    return;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> V[i][j];
        }
    }
    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == 0 && V[i][j] > N){
                answer++;
                DFS(i, j);
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
