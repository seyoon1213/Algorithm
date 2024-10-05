#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int N, cnt;
string s;

int main(){
    cin >> N;
    vector<string> v;
    for(int i = 0; i < N; i++){
        cin >> s;
        v.push_back(s);
    }

    for(int i = 0; i < N; i++){
        s = v[i];
        stack<char> stk; // stack 구조 활용***
        for(int j = 0; j < s.length(); j++){
            if(stk.size() != 0 && s[j] == stk.top()){ // stack.size() != 0인지 확인***
                stk.pop();
            }
            else{
                stk.push(s[j]);
            }
        }
        if(stk.size() == 0){
            cnt++;
        }
        /*
        bool find;
        for(int j = 0; j < s.length(); j++){ // s[j]에 대해
            find = false;
            if(s[j] == '.'){ // 이미 쌍을 이루는 경우
                find = true;
                continue;
            }
            for(int k = j + 1; k < s.length(); k++){
                if(s[j] == s[k] && ((k - j) % 2 == 1)){ // s[k]와 쌍을 이루는 경우
                    s[j] = '.';
                    s[k] = '.';
                    find = true;
                    break;
                }
            }
            if(!find){ // 쌍을 이루지 못한 경우
                break;
            }
        }
        if(find){
            cnt++;
        }
        */
    }

    cout << cnt << '\n';

    return 0;
}
