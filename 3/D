#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int R, C;
int V[1000][1000];
int visited[1000][1000];
int fire_check[1000][1000]; // 발화 시점에 대해 기록***
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int INF = 1000000;
vector<pair<int, int>> fire;
pair<int, int> jihoon;

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        string s;
        cin >> s;
        for(int j = 0; j < C; j++){
            V[i][j] = s[j];
            if(V[i][j] == 'F'){
                fire.push_back({i, j});
            }
            if(V[i][j] == 'J'){
                jihoon = {i, j};
            }
        }
    }

    fill(&fire_check[0][0], &fire_check[0][0] + 1000 * 1000, INF); // 크기가 1바이트 이상인 숫자로 초기화하기 위해선 fill() 사용***
    for(pair<int, int> f : fire){
        fire_check[f.first][f.second] = 1;
        queue<pair<int, int>> q;
        q.push(f);
        while(q.size()){
            pair<int, int> pos = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = pos.second + dx[i];
                int ny = pos.first + dy[i];
                if((nx < 0) || (ny < 0) || (nx >= C) || (ny >= R)) continue;
                if(fire_check[ny][nx] != INF) continue;
                if(V[ny][nx] == '#') continue;
                fire_check[ny][nx] = fire_check[pos.first][pos.second] + 1;
                q.push({ny, nx});
            }
        }
    }

    int cnt = 0;
    int x = jihoon.second;
    int y = jihoon.first;
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()){
        pair<int, int> pos = q.front();
        q.pop();
        if((pos.first == 0) || (pos.second == 0) || (pos.first == R - 1) || (pos.second == C - 1)){
            cnt = visited[pos.first][pos.second];
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = pos.second + dx[i];
            int ny = pos.first + dy[i];
            if((nx < 0) || (ny < 0) || (nx >= C) || (ny >= R)) continue;
            if(visited[ny][nx] != 0) continue;
            if(V[ny][nx] != '.') continue;
            if(fire_check[ny][nx] <= visited[pos.first][pos.second] + 1) continue; // 발화 시점 <= 도착 시점***
            visited[ny][nx] = visited[pos.first][pos.second] + 1;
            q.push({ny, nx});
        }
    }
    
    if(cnt == 0) cout << "IMPOSSIBLE\n";
    else cout << cnt << '\n';

    return 0;
}
