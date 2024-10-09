#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    vector<string> v;
    while(true){
        string s;
        getline(cin, s); // getline(cin, string): 띄어쓰기까지 포함하여 문자열 입력***
        if(s == "."){
            break;
        }
        v.push_back(s);
    }

    for(string s : v){
        stack<char> stk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '['){
                stk.push(s[i]);
            }
            if(s[i] == ')' && !stk.empty() && stk.top() == '('){
                stk.pop();
            }
            if(s[i] == ']' && !stk.empty() && stk.top() == '['){
                stk.pop();
            }
        }
        if(stk.empty()){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
    return 0;
}
