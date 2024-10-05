#include <stdio.h>
#include <iostream>

using namespace std;

int N;
string pattern;
vector<string> names;

int main(){
    cin >> N;
    cin >> pattern;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        names.push_back(s);
    }

    string front;
    string back;
    for(int i = 0; i < pattern.length(); i++){
        if(pattern[i] == '*'){
            front = pattern.substr(0, i);
            back = pattern.substr(i + 1, pattern.length() - i - 1); // substr(시작 인덱스, 크기)) ***
        }
    }
    /*
    int pos = pattern.find('*');
    front = pattern.substr(0, pos);
    back = pattern.substr(pos + 1);
    */

   /*
    bool answer = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < front.length(); j++){
            if(front[j] != names[i][j]){
                answer = false;
                break;
            }
        }
        for(int j = 0; j < back.length(); j++){
            int l = names[i].length();
            if(back[j] != names[i][j + l - back.length()]){
                answer = false;
                break;
            }
        }
        if(answer){
            cout << "DA" << '\n';
        }
        else {
            cout << "NE" << '\n';
        }
        answer = true; // answer 초기화 필수***
    }
    */
    for(int i = 0; i < N; i++){
        int f = front.length();
        int b = back.length();
        string s = names[i];
        if(f + b > s.size()){ // [반례] s: ab, pattern: ab*ab
            cout << "NE\n";
        }
        else{
            if(front == s.substr(0, f) && back == s.substr(s.length() - b)){ // substr(시작 인덱스), 문자열의 내용 비교***
                cout << "DA\n";
            }
            else{
                cout << "NE\n";
            }
        }
    }
    return 0;
}
