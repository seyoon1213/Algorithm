#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visited[100000];
int before[100000];
vector<int> v;

int main(){
    cin >> N >> K;

    visited[N] = 1;
    before[N] = -1;
    queue<int> q;
    q.push(N);
    while(q.size()){
        int pos = q.front();
        q.pop();
        for(int i = 0; i < 3; i++){
            int npos = pos;
            if(i == 0) npos++;
            if(i == 1) npos--;
            if(i == 2) npos *= 2;

            if(npos < 0 || npos >= 100000) continue;
            if(visited[npos] != 0) continue;
            visited[npos] = visited[pos] + 1;
            before[npos] = pos;
            q.push(npos);
        }
    }
    cout << visited[K] - 1 << '\n';

    int idx = K;
    while(true){
        if(idx == -1) break;
        v.push_back(idx);
        idx = before[idx];
    }
    reverse(v.begin(), v.end()); // 순서를 반대로 정렬***
    for(int i : v) cout << i << " ";
    cout << '\n';

    return 0;
}
