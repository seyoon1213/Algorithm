#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N;
int V[3];
int visited[61][61][61]; // 아이디어***

struct A{
    int a, b, c;
};

int B[6][3] = {{1, 3, 9}, {1, 9, 3}, {3, 1, 9}, {3, 9, 1}, {9, 1, 3}, {9, 3, 1}};

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> V[i];
    }

    visited[V[0]][V[1]][V[2]] = 1;
    queue<A> q;
    q.push({V[0], V[1], V[2]});
    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(a == 0 && b == 0 && c == 0) break;
        for(int i = 0; i < 6; i++){ // 이동 가능 범위***
            int na = max(0, a - B[i][0]);
            int nb = max(0, b - B[i][1]);
            int nc = max(0, c - B[i][2]);
            if(visited[na][nb][nc] != 0) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }

    cout << visited[0][0][0] - 1 << '\n';
    return 0;
}
