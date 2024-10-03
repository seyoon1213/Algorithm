#include <stdio.h>
#include <iostream>

using namespace std;

string s;
int main(){
    cin >> s;
    cout << '\n';

    int mid = s.length() / 2;
    string back;
    string front;

    if(s.length() % 2 == 1){
        front = s.substr(0, mid);
        back = s.substr(mid + 1, s.length());
    }
    if(s.length() % 2 == 0){
        front = s.substr(0, mid - 1);
        back = s.substr(mid, s.length());
    }
    reverse(back.begin(), back.end());
    
    for(int i = 0; i < front.length(); i++){
        if(front[i] != back[i]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;

    return 0;
}
