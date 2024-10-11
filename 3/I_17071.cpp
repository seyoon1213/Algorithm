#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int N, K;
int minimum = 500001;
int position = -1; // 만나는 위치***
int s[500001];
int d[500001];

// N < K인 경우 수빈과 동생이 동시에 도착하는 경우만 고려
// N > K인 경우 수빈이 동생보다 먼저 도착하는 경우 고려***
// 수빈이 + 1, - 1만큼 이동하면 제자리에 위치***

int main(){
    cin >> N >> K;

    int idx = K;
    int cnt = 0;
    while(true){
        cnt++;
        d[idx] = cnt;
        idx += cnt;
        if(idx > 500000) break;
    }

    s[N] = 1;
    queue<int> q;
    q.push(N);
    while(q.size()){
        int pos = q.front();
        q.pop();
        if(d[pos] == s[pos]){
            if(minimum > d[pos]){
                position = pos;
            }
            break;
        }
        if(d[pos] > s[pos] && d[pos] % 2 == s[pos] % 2){
            if(minimum > d[pos]){
                minimum = d[pos];
                position = pos;
            }
        }
        for(int i = 0; i < 3; i++){
            int npos = pos;
            if(i == 0) npos++;
            if(i == 1) npos--;
            if(i == 2) npos *= 2;

            if(npos < 0 || npos > 500000) continue;
            if(s[npos] != 0) continue;
            s[npos] = s[pos] + 1;
            q.push(npos);
        }
    }
    if(position == -1){
        cout << -1 << '\n';
    }
    else{
        cout << d[position] - 1 << '\n';
    }
    return 0;
}
