#include <stdio.h>
#include <iostream>

using namespace std;
typedef unsigned long long ll; // 오버플로우 조심***
int k;
char oper[10];

int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<ll> v;

int visited[10];
vector<string> vv;

bool operation(char c, int a, int b){
    if(c == '<') return a < b;
    if(c == '>') return a > b;
}

void go(int idx, string str){ // 매개변수: str***
    if(str.length() == k + 1){
        vv.push_back(str);
        return;
    }
    for(int i = 0; i < 10; i++){
        if(visited[i] != 0) continue;
        if(idx != 0 && !operation(oper[idx - 1], str[idx - 1] - '0', i)) continue;
        visited[i] = 1;
        go(idx + 1, str + to_string(i));
        visited[i] = 0;
    }
}

void permutation(int depth){
    if(depth == k + 1){
        bool flag = true;
        for(int i = 0; i < k; i++){
            if(oper[i] == '>' && num[i] <= num[i + 1]) flag = false;
            if(oper[i] == '<' && num[i] >= num[i + 1]) flag = false;
        }
        if(flag){
            ll n = 0;
            for(int i = 0; i < k + 1; i++){
                n += num[i] * ll(pow(10, k - i));
            }
            v.push_back(n);
        }
        return;
    }
    for(int i = depth; i < 10; i++){
        swap(num[i], num[depth]);
        permutation(depth + 1);
        swap(num[i], num[depth]);
    }
}

void print(ll n){ // 별도의 처리 필요***
    for(int i = 0; i < k + 1; i++){
        cout << n / ll(pow(10, k - i));
        n = n % ll(pow(10, k - i));
    }
    cout << '\n';
}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> oper[i];
    }

    permutation(0);
    sort(v.begin(), v.end(), less<ll>());
    print(v[v.size() - 1]);
    print(v[0]);

    go(0, ""); // 재귀***
    sort(vv.begin(), vv.end(), less<string>()); // 별도의 처리 없이 출력(O)***
    cout << vv[vv.size() - 1] << '\n';
    cout << vv[0] << '\n';
    
    return 0;
}
