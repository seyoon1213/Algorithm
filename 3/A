#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int N, M;
int V[50][50];
vector<vector<int>> chickenList; // 치킨 조합 목록***
vector<pair<int, int>> chicken; // 치킨 목록
vector<pair<int, int>> home; // 집 목록
vector<int> v; // 임시 치킨 조합***

void combi(int start){
    if(v.size() == M){
        chickenList.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++){ // 조합***
        v.push_back(i);
        combi(i);
        v.pop_back();
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> V[i][j];
            if(V[i][j] == 2) chicken.push_back({i, j});
            if(V[i][j] == 1) home.push_back({i, j});
        }
    }

    combi(-1); // 조합*** 
    int result = 10000;
    for(vector<int> cList : chickenList){
        int ret = 0;
        for(pair<int, int> h : home){
            int temp = 100;
            for(int ch : cList){
                int dist = abs(h.first - chicken[ch].first) + abs(h.second - chicken[ch].second);
                temp = min(temp, dist);
            }
            ret += temp;
        }
        result = min(result, ret);
    }
    cout << result << '\n';

    return 0;
}
