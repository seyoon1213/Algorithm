#include <stdio.h>
#include <iostream>

using namespace std;

int N, K;
vector<int> temp;

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        temp.push_back(n);
    }

    int max = -30000000; // 최솟값 설정***

    for(int i = 0; i < N - K + 1; i++){
        int n = 0;
        for(int j = i; j < i + K; j++){
            n += temp[j];
        }
        if(n > max){
            max = n;
        }
    }

    cout << max << '\n';

    return 0;
}
