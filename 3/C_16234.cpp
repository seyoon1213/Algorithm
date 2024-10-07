#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int N, L, R;
int A[50][50];
int visited[50][50];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
vector<vector<pair<int, int>>> V;
vector<pair<int, int>> v;

void BFS(int y, int x){
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    v.clear();
    v.push_back({y, x});
    while(q.size()){
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = p.second + dx[i];
            int ny = p.first + dy[i];
            int diff = abs(A[p.first][p.second] - A[ny][nx]);
            if((nx < 0) || (ny < 0) || (nx >= N) || (ny >= N)) continue;
            if(visited[ny][nx] != 0) continue;
            if((diff < L) || (diff > R)) continue; // 조건***
            visited[ny][nx] = 1;
            q.push({ny, nx});
            v.push_back({ny, nx});
        }
    }
    V.push_back(v);
    return;
}

int main(){
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }
    int cnt = 0;
    while(true){
        V.clear();
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(visited[i][j] == 0){
                    BFS(i, j);
                }
            }
        }

        if(V.size() == N * N) break;

        for(vector<pair<int, int>> a : V){
            int sum = 0;
            for(pair<int, int> p : a){
                sum += A[p.first][p.second];
            }
            for(pair<int, int> p : a){
                A[p.first][p.second] = sum / a.size();
            }
        }

        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
