#include <stdio.h>
#include <iostream>

using namespace std;

int N, M;
vector<string> names;
vector<string> questions;

int main(){
    
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        names.push_back(s);
    }

    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        questions.push_back(s);
    }
    cout << '\n';

    for(int i = 0; i < M; i++){
        string s = questions[i];

        if(s[0] >= 'A' && s[0] <= 'Z'){
            /*
            for(int j = 0; j < N; j++){
                for(int k = 0; k < names[j].length(); k++){
                    if(names[j][k] != s[k]){
                        break;
                    }
                    if(k == names[j].length() - 1){
                        cout << j + 1 << '\n';
                    }
                }
            }
            */
            for(int j = 0; j < N; j++){
                if(names[j] == s){ // 문자열을 '=='를 통해 직접 비교 가능***
                    cout << j + 1 << '\n';
                    break;
                }
            }

        }
        else {
            int number = 0;
            for(int j = 0; j < s.length(); j++){
                number += (s[j] - '0') * pow(10, s.length() - j - 1);
            }
            cout << names[number - 1] << '\n';
        }
    }

    return 0;
}
