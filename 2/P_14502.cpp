#include <stdio.h>
#include <iostream>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int V[8][8];
int visited[8][8];
int N, M, wall;
vector<pair<int, int>> blank;

int DFS(int y, int x){
    int sum = 1; // 현재 위치 포함***
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if((nx < 0) || (nx >= M) || (ny < 0) || (ny >= N)) continue;
        if(visited[ny][nx] == 1) continue;
        if(V[ny][nx] == 1) continue;
        sum += DFS(ny, nx);
    }
    return sum;
}

int go(){
    int answer = 0; // 바이러스가 퍼질 수 있는 구역***
    memset(visited, 0, sizeof(visited)); // 방문 횟수 초기화***
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] == 0 && V[i][j] == 2){ // V[i][j] != 1 (X): 안전 구역이 포함될 수 있기 때문***
                answer += DFS(i, j);
            }
        }
    }
    /*
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(V[i][j] == 0 && visited[i][j] == 0) cnt++;
        }
    }*/
    return N * M - answer - wall - 3;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> V[i][j];
            if(V[i][j] == 0){
                blank.push_back({i, j}); // 빈 칸의 위치 저장***
            }
            if(V[i][j] == 1){
                wall++;
            }
        }
    }

    int answer = 0;
    for(int p = 0; p < blank.size(); p++){ // 3개의 빈 칸을 선택 by 조합***
        for(int q = p + 1; q < blank.size(); q++){
            for(int r = q + 1; r < blank.size(); r++){
                V[blank[p].first][blank[p].second] = 1;
                V[blank[q].first][blank[q].second] = 1;
                V[blank[r].first][blank[r].second] = 1;
                answer = max(answer, go());
                V[blank[p].first][blank[p].second] = 0;
                V[blank[q].first][blank[q].second] = 0;
                V[blank[r].first][blank[r].second] = 0;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
