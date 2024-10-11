#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N, M, x11, x22, y11, y22;
char V[300][300];
int visited[300][300];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
vector<pair<int, int>> v;

int main(){
    cin >> N >> M;
    cin >> y11 >> x11 >> y22 >> x22;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            V[i][j] = s[j];
        }
    }

    x11--; y11--; x22--; y22--; // 인덱스 vs 행렬 ***

    int cnt = 0;
    bool flag = true;
    while(flag){
        cnt++;
        memset(visited, 0, sizeof(visited));

        v.clear();
        v.push_back({y11, x11});

        visited[y11][x11] = 1;
        queue<pair<int, int>> q;
        q.push({y11, x11});
        while(q.size()){
            int x = q.front().second;
            int y = q.front().first;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                if(visited[ny][nx] != 0) continue;
                if(V[ny][nx] == '1' || V[ny][nx] == '#') continue; // '1'과 '#'을 만나기 직전까지의 모든 좌표들을 저장***
                v.push_back({ny, nx});
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }

        for(pair<int, int> p : v){
            for(int i = 0; i < 4; i++){
                int nx = p.second + dx[i];
                int ny = p.first + dy[i];
                if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                if(nx == x11 && ny == y11) continue;
                V[ny][nx] = '0';
                if(ny == y22 && nx == x22) flag = false;
            }
        }
        cout << cnt << '\n';
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cout << V[i][j] << " ";
            }
            cout << '\n';
        }
    }
    cout << cnt << '\n';
    return 0;
}
