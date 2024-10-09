#include <stdio.h>
#include <iostream>

using namespace std;
typedef unsigned long long ll;

int n;

int main(){
    cin >> n;
    ll array[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    for(int i = 0; i < n; i++){
        ll a = array[i];
        int ret2 = 0, ret5 = 0;
        for(ll j = 2; j <= a; j *= 2){ // 승수를 기반으로 계산***
            ret2 += a / j;
        }
        for(ll j = 5; j <= a; j *= 5){
            ret5 += a / j;
        }
        cout << min(ret2, ret5) << '\n';
    }
    return 0;
}
/*
1   2   3   4   5   6   7   8   9   10
    1       1       1       1       1   -> 총 (10 / 2)개
            1               1           -> 총 (10 / 4)개
                            1           -> 총 (10 / 8)개
*/
