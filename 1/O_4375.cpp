#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;
ll n;
vector<ll> v;

int main(){
    // scanf("%d", &n) 형식***
    // 반환값 (1) 올바른 형식인 경우: 입력된 값(들)의 개수 (2) 올바른 형식이 아닌 경우: 0 (3) ctrl + d: EOF(-1)
    while(scanf("%lld", &n) != EOF){
        v.push_back(n);
    }

    for(int i = 0; i < v.size(); i++){
        ll a = 1;
        ll b = 0;
        while(a % v[i] != 0){
            b++;
            a += pow(10, b);
        }
        cout << a << '\n';
    }
    return 0;
}
