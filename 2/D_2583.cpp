#include <stdio.h>
#include <iostream>

using namespace std;

int visited[100][100];
int V[100][100];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N, M, K;
vector<int> answer;

void DFS(int y, int x, int n){
    visited[y][x] = 1;
    answer[n]++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if((nx < 0) || (nx >= N) || (ny < 0) || (ny >= M)) continue;
        if(visited[ny][nx] == 0 && V[ny][nx] == 0) DFS(ny, nx, n);
    }
    return ;
}
int main(){
    cin >> M >> N >> K;
    int min_x, min_y, max_x, max_y;
    for(int i = 0; i < K; i++){
        cin >> min_x >> min_y >> max_x >> max_y;
        for(int j = min_y; j < max_y; j++){
            for(int k = min_x; k < max_x; k++){
                V[j][k] = 1;
            }
        }
    }

    int n = 0;
    for(int i = 0; i < M; i++){ // M: 세로 길이, y축 방향
        for(int j = 0; j < N; j++){ // N: 가로 길이, x축 방향
            if(visited[i][j] == 0 && V[i][j] == 0){
                answer.push_back(0);
                DFS(i, j, n);
                n++;
            }
        }
    }

    sort(answer.begin(), answer.end(), less<int>()); // sort(시작 주소, 끝 주소, less<int>())***
    cout << n << '\n';
    for(int i : answer){
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}
