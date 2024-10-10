#include <stdio.h>
#include <iostream>

using namespace std;

int N, K;
int node[50]; // 각 노드의 부모
vector<int> v; // 삭제된 노드
vector<int> parents; // 부모 노드

int main(){
    cin >> N;
    int n;
    for(int i = 0; i < N; i++){
        cin >> n;
        node[i] = n;
    }

    cin >> K;
    v.push_back(K);
    node[K] = -1;
    for(int i = 0; i < N; i++){
        if(node[i] == K){ // 부모가 K거나
            v.push_back(i);
            node[i] = -1;
        }
        else{
            for(int j : v){
                if(node[i] == j){ // 부모가 삭제되었거나
                    v.push_back(i);
                    node[i] = -1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(node[i] != -1){
            parents.push_back(node[i]);
        }
    }

    int answer = 0;
    for(int i = 0; i < N; i++){
        bool flag = true;
        for(int j : v){
            if(i == j) flag = false; // 삭제된 노드인 경우
        }
        for(int j : parents){
            if(i == j) flag = false; // 부모 노드인 경우
        }
        if(flag) answer++;
    }

    cout << answer << '\n';

    return 0;
}
