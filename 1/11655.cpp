#include <stdio.h>
#include <iostream>

using namespace std;

string s;

int main(){
    getline(cin, s);
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'm'){
            s[i] = char(s[i] + 13);
            continue; // continue를 빼먹으면 다음 if문 실행 ***
        }
        if(s[i] >= 'n' && s[i] <= 'z'){
            s[i] = char(s[i] - 13);
            continue;
        }
        if(s[i] >= 'A' && s[i] <= 'M'){
            s[i] = char(s[i] + 13);
            continue;
        }
        if(s[i] >= 'N' && s[i] <= 'Z'){
            s[i] = char(s[i] - 13);
        }
    }

    cout << s << '\n';

    return 0;
}
