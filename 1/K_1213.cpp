#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int eng[26];

int main(){
    string s;
    string answer = "";
    string temp = "";
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        int alphabet = s[i] - 'A';
        eng[alphabet] += 1;
    }

    int number = 0;
    int odd;
    for(int i = 0; i < 26; i++){
        if(eng[i] % 2 == 1){
            number += 1;
            odd = i;
        }
    }

    if(number > 1){
        cout << "I'm Sorry Hansoo" << '\n';
    }
    else if(number == 1){
        for(int i = 0; i < 26; i++){
            if(eng[i] == 0){
                continue;
            }
            else{
                char c = i + 'A';
                for(int j = 0; j < eng[i] / 2; j++){
                    answer += c;
                }
            }
        }
        temp = answer;
        reverse(temp.begin(), temp.end());
        answer += char(odd + 'A');
        answer += temp;
        cout << answer << '\n';
    }
    else{
        for(int i = 0; i < 26; i++){
            if(eng[i] == 0){
                continue;
            }
            else{
                char c = i + 'A';
                for(int j = 0; j < eng[i] / 2; j++){
                    answer += c;
                }
            }
        }
        temp = answer;
        reverse(temp.begin(), temp.end());
        answer += temp;
        cout << answer << '\n';
    }

    return 0;
}
