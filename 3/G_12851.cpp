#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N, K;
int cnt;
int visited[100000];
//int counting[100000];

int main(){
    cin >> N >> K;
    
    visited[N] = 1;
    queue<int> q;
    q.push(N);
    while(q.size()){
        int pos = q.front();
        q.pop();
        if(pos == K){
            cnt++;
        }
        for(int i = 0; i < 3; i++){
            int npos;
            if(i == 0) npos = pos + 1;
            if(i == 1) npos = pos - 1;
            if(i == 2) npos = pos * 2;
            if(npos < 0 || npos > 100000) continue;
            if(visited[npos] == 0 || visited[npos] == visited[pos] + 1){
                visited[npos] = visited[pos] + 1;
                q.push(npos);
            }
            /*
            if(visited[npos] == 0){
                visited[npos] = visited[pos] + 1;
                counting[npos] = counting[pos];
                q.push(npos);
            }
            else if(visited[npos] == visited[pos] + 1){
                counting[npos] += counting[pos];
            }
            */
        }
    }
    cout << visited[K] - 1 << '\n';
    cout << cnt << '\n';
    //cout << counting[K] << '\n';
    return 0;
}
