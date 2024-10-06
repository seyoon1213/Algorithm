#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int visited[100][100];
int V[100][100];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void BFS(int y, int x){
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while(q.size()){
        pair<int, int> parent = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = parent.second + dx[i]; // nx = x + dx[i] (X), nx = parent.second + dx[i] (O) 주의***
            int ny = parent.first + dy[i];
            if((nx < 0) || (nx >= M) || (ny < 0) || (ny >= N)) continue;
            if(visited[ny][nx] != 0) continue; // visited라는 배열에는 최단 거리가 저장***
            if(V[ny][nx] == 0) continue;
            visited[ny][nx] = visited[parent.first][parent.second] + 1;
            q.push({ny, nx});
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            int n = s[j] - '0';
            V[i][j] = n;
        }
    }

    BFS(0, 0);

    cout << visited[N - 1][M - 1] << '\n'; // 칸수: visited, 거리: visited - 1 주의***


    return 0;
}
