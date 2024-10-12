#include <stdio.h>
#include <iostream>

using namespace std;

int K;
int num[2000];
vector<pair<int, int>> v;
int idx = 0;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

void go(int n){
    if(2 * n < pow(2, K)) go(2 * n);
    v.push_back({n, num[idx++]});
    if(2 * n < pow(2, K)) go(2 * n + 1);
}

int main(){
    cin >> K;
    for(int i = 0; i < pow(2, K) - 1; i++){
        cin >> num[i];
    }
    go(1);
    

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < K; i++){
        for(int j = pow(2, i) - 1; j < pow(2, i + 1) - 1; j++){
            cout << v[j].second << " ";
        }
        cout << '\n';
    }

    return 0;
}
