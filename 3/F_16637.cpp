#include <stdio.h>
#include <iostream>
using namespace std;

int N;
int maximum = -987654321;
string s;
vector<int> num; // 숫자들의 모음***
vector<char> oper;

int operation(char c, int a, int b){
    if(c == '+') return a + b;
    if(c == '-') return a - b;
    if(c == '*') return a * b;
}

void go(int idx, int sum){ // idx: 현재 위치(인덱스), sum: 현재 위치까지의 계산 결과***
    if(idx == num.size() - 1){
        maximum = max(maximum, sum);
        return;
    }
    else{
        go(idx + 1, operation(oper[idx], sum, num[idx + 1])); // 괄호가 없는 경우***
        if(idx + 2 <= num.size() - 1){ // 괄호가 있는 경우***
            int temp = operation(oper[idx + 1], num[idx + 1], num[idx + 2]);
            go(idx + 2, operation(oper[idx], sum, temp));
        }
        return;
    }
}

int main(){
    cin >> N;
    cin >> s;
    for(int i = 0; i < N; i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
            oper.push_back(s[i]);
        }
        else{
            num.push_back(s[i] - '0');
        }
    }

    go(0, num[0]);

    cout << maximum << '\n';

    return 0;
}
