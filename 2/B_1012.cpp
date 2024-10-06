#include <stdio.h>
#include <iostream>

using namespace std;
int T, M, N, K;
int V[50][50];
int visited[50][50];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void DFS(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if((nx < 0) || (nx >= M) || (ny < 0) || (ny >= N)) continue;
        if(visited[ny][nx] == 0 && V[ny][nx] == 1) DFS(ny, nx);
    }
    return;
}

int main(){

    cin >> T;
    int x, y;
    int answer[T]; // 지역 변수로 선언된 배열은 0으로 자동 초기화 (X)***
    memset(answer, 0, sizeof(answer));
    for(int i = 0; i < T; i++){
        memset(V, 0, sizeof(V)); // memset(시작 주소, 초기화 값, 크기)***
        memset(visited, 0, sizeof(visited));
        cin >> M >> N >> K;
        for(int j = 0; j < K; j++){
            cin >> x >> y;
            V[y][x] = 1;
        }
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(visited[j][k] == 0 && V[j][k] == 1){
                    DFS(j, k);
                    answer[i] ++;
                }
            }
        }
    }
    for(int i = 0; i < T; i++){
        cout << answer[i] << '\n';
    }

    return 0;
}
