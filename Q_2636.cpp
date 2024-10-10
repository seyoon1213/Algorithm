#include <stdio.h>
#include <iostream>

using namespace std;

int N, M;
int V[100][100];
int visited[100][100];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
vector<pair<int, int>> v;

void DFS(int y, int x){
    visited[y][x] = 1;
    if(V[y][x] == 1){ // 가장자리에 위치한 치즈***
        v.push_back({y, x});
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if((nx < 0) || (ny < 0) || (nx >= M) || (ny >= N)) continue;
        if(visited[ny][nx] == 1) continue;
        DFS(ny, nx); // if(V[ny][nx] == 0) continue; (X)***
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> V[i][j];
        }
    }

    int cnt = 0;
    int cheese = 0;
    while(true){
        memset(visited, 0, sizeof(visited)); // fill(&visited[0][0], &visited[0][0] + 100 * 100, 0)***
        v.clear();
        DFS(0, 0);
        cheese = v.size(); // 가장자리에 위치한 치즈의 개수***
        for(pair<int, int> p : v){
            V[p.first][p.second] = 0; // 가장자리에 위치한 치즈가 녹음***
        }
        bool flag = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(V[i][j] == 1){ // 치즈가 남아있는 경우***
                    flag = true;
                }
            }
        }
        cnt++; // 치즈가 모두 녹는 데까지 걸린 시간***
        if(flag == false) break;
    }   
    cout << cnt << '\n';
    cout << cheese << '\n';

    return 0;
}
