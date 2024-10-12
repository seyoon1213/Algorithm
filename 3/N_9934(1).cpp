#include <stdio.h>
#include <iostream>

using namespace std;
int k;
vector<int> v[10];
int building[1024];

void go(int s, int e, int level){
    if(s > e) return;
    if(s == e){
        v[level].push_back(building[s]);
        return;
    }
    int mid = (s + e) / 2;
    v[level].push_back(building[mid]);
    go(s, mid - 1, level + 1);
    go(mid + 1, e, level + 1);
    return;
}

int main(){
    cin >> k;
    int n = int(pow(2, k)) - 1;
    for(int i = 0; i < n; i++){
        cin >> building[i];
    }
    go(0, n, 1); // level: 1 ~ k***
    for(int i = 1; i <= k; i++){ // level: 1 ~ k***
        for(int j : v[i]){
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}

/*
n = 3
a[0] = 1, ... , a[6] = 7

0 1 2 3 4 5 6 (7)  i
| | | | | | |  |
| | | 1 | | |  |   ret[1] = {a[3]}
| 2 |   | 2 |  |   ret[2] = {a[1], a[5]}
3   3   3   3  |   ret[3] = {a[0], a[2], a[4], a[6]}
              (4)  ret[4] = {a[7]}

*/
