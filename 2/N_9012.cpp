#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    string list[n];
    for(int i = 0; i < n; i++){
        cin >> list[i];
    }
    
    for(int i = 0; i < n; i++){
        stack<char> stk;
        string s = list[i];
        for(int j = 0; j < s.size(); j++){
            if(!stk.empty() && stk.top() == '(' && s[j] == ')'){
                stk.pop();
            }
            else{
                stk.push(s[j]);
            }
        }
        if(stk.empty()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
