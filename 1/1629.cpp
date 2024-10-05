#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;
ll a, b, c;

ll go(ll a, ll b, ll c){
    if(b == 1){
        return a % c; // 기저조건***
    }
    ll temp = go(a, b / 2, c);
    temp = (temp * temp) % c;
    if(b % 2 == 1){
        temp = (temp * a) % c;
    }
    return temp;
}

int main(){
    cin >> a >> b >> c;

    /* long long 타입을 사용했음에도 불구하고 a^b의 값이 너무 커서 오버플로우 발생***
    ll result = 1;
    for(int i = 0; i < b; i++){
        result *= a;
    }
    cout << result % c << '\n';
    */

    cout << go(a, b, c) << '\n'; // (A * B) mod C = (A mod C * B mod C) mod C임을 활용***
    return 0;
}
