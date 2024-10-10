#include <stdio.h>
#include <iostream>

using namespace std;
typedef unsigned long long ll;

int N;
ll M;
vector<int> childs[10000];
int visited[10000]; // 사이클이 없는 그래프라고 장담할 수 없기 때문에 방문 여부를 기록하여 중복 방지***

int DFS(int parent){
    visited[parent] = 1;
    int number = 1;
    for(int child : childs[parent]){
        if(visited[child] == 1) continue;
        number += DFS(child);
    }
    return number;
}

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(){
    cin >> N >> M;
    int child, parent;
    for(ll i = 0; i < M; i++){
        cin >> child >> parent;
        childs[parent].push_back(child);
    }

    vector<pair<int, int>> hack;
    for(int i = 0; i < N; i++){
        fill(&visited[0], &visited[0] + N + 1, 0);
        //memset(visited, 0, sizeof(visited));
        hack.push_back({DFS(i + 1), i + 1});
    }

    sort(hack.begin(), hack.end(), cmp);

    for(int i = 0; i < hack.size(); i++){
        if(hack[i].first != hack[0].first) break;
        cout << hack[i].second << " ";
    }
    cout << '\n';

    return 0;
}
