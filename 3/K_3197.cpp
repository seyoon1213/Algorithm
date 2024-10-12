#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int R, C, x_1, y_1, x_2, y_2;
char V[1500][1500];
int visited[1500][1500];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
vector<pair<int, int>> l;
vector<pair<int, int>> v; // '.' 모음***
bool flag = true;

void BFS(int y, int x){
    v.push_back({y, x});
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()){
        int xx = q.front().second;
        int yy = q.front().first;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
            if(visited[ny][nx] != 0) continue;
            if(V[ny][nx] == 'X') continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
            v.push_back({ny, nx});
        }
    }
    return;
}

void DFS(int y, int x){
    visited[y][x] = 1;
    if(y == y_2 && x == x_2){
        flag = false;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
        if(visited[ny][nx] != 0) continue;
        if(V[ny][nx] == 'X') continue;
        DFS(ny, nx);
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
            if(s[j] == 'L') l.push_back({i, j});
        }
    }
    x_1 = l[0].second;
    y_1 = l[0].first;
    x_2 = l[1].second;
    y_2 = l[1].first;

    int cnt = 0;
    while(flag){
        cnt++;

        v.clear();
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(V[i][j] == 'X') continue;
                if(visited[i][j] != 0) continue;
                BFS(i, j); // '.'를 v에 넣기***
            }
        }

        for(pair<int, int> p : v){
            for(int i = 0; i < 4; i++){
                int nx = p.second + dx[i];
                int ny = p.first + dy[i];
                if(nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
                if(V[ny][nx] != 'L'){
                    V[ny][nx] = '.'; // '.' 주변의 'X'를 '.'로 변환***
                }
            }
        }

        memset(visited, 0, sizeof(visited));
        DFS(y_1, x_1); // 백조가 서로 만날 수 있는지 여부 확인***
    }

    cout << cnt << '\n';
    return 0;
}
