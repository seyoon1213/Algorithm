#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
typedef unsigned long long ll;

ll N, n;
ll a[1000000], ret[1000000];
stack<ll> stk; // 오큰수가 정해지지 않은 숫자들의 모음***

int main(){
    cin >> N;
    memset(ret, -1, sizeof(ret)); // -1로 초기화***
    // full(&ret[0], &ret[0] + 1000000, -1);
    for(int i = 0; i < N; i++){
        cin >> a[i]; // a[i]: i + 1번째 숫자***
        while(!stk.empty() && a[stk.top()] < a[i]){
            ret[stk.top()] = a[i]; // stk.top() + 1번째 숫자의 오큰수 지정***
            stk.pop();
        }
        stk.push(i); // i + 1번째 숫자의 오큰수는 아직 정해지지 않음***
    }

    for(int i = 0; i < N; i++) cout << ret[i] << '\n';
    return 0;
}


/*

*
*     *
*     *
* *   *
* * * *
5 2 1 4

stack에 저장된 숫자들(5, 2, 1)은 내림차순으로 push, 오름차순으로 pop
*/
