#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N, M, maximum;
char V[50][50];
int visited[50][50];
vector<pair<int, int>> land;
vector<pair<int, int>> v;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void DFS(int y, int x){
    if(v[1].second == x && v[1].first == y){
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if((nx < 0) || (ny < 0) || (nx >= M) || (ny >= N)) continue;
        if(visited[ny][nx] != 0) continue;
        if(V[ny][nx] == 'W') continue;
        visited[ny][nx] = visited[y][x] + 1;
        DFS(ny, nx);
    }
}

void combi(int start){
    if(v.size() == 2){
        memset(visited, 0, sizeof(visited));
        visited[v[0].first][v[0].second] = 1;
        DFS(v[0].first, v[0].second);
        maximum = max(maximum, visited[v[1].first][v[1].second]);
        return;
    }
    for(int i = start + 1; i < land.size(); i++){
        v.push_back(land[i]);
        combi(i);
        v.pop_back();
    }
}


void BFS(int y, int x){
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size() != 0){
        pair<int, int> pos = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = pos.second + dx[i];
            int ny = pos.first + dy[i];
            if((nx < 0) || (ny < 0) || (nx >= M) || (ny >= N)) continue;
            if(visited[ny][nx] != 0) continue;
            if(V[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[pos.first][pos.second] + 1;
            q.push({ny, nx});
            maximum = max(maximum, visited[ny][nx]);
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            V[i][j] = s[j];
            if(s[j] == 'L') land.push_back({i, j});
        }
    }
    // combination을 통해 두 개의 육지를 선택 -> 조합별로 최단 거리 계산 -> 최단 거리 중 가장 큰 값 선택
    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(V[i][j] == 'L'){
                memset(visited, 0, sizeof(visited));
                BFS(i, j);
            }
        }
    }
    */

    combi(-1);

    cout << maximum - 1 << '\n';

    return 0;
}
