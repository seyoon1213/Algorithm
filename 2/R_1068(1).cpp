#include <stdio.h>
#include <iostream>

using namespace std;

int N, K, root;
vector<int> childs[50];

int DFS(int parent){ // parent가 루트 노드인 서브 트리를 탐색***
    int number = 0; // 서브 트리 내 leaf node의 개수***
    for(int child : childs[parent]){
        if(child == K) continue;
        else number += DFS(child);
    }
    if(number == 0) return 1; // parent가 부모 노드가 아닌 경우***
    else return number; // parent가 부모 노드인 경우***
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        if(n == -1) root = i;
        else childs[n].push_back(i); // n: 부모 노드, i: 자식 노드***
    }

    cin >> K;

    if(root == K) cout << "0\n";
    else cout << DFS(root) << '\n';

    return 0;
}
