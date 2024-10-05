#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int N, M;
map<string, int> mp1;
map<int, string> mp2;
vector<string> questions;
string s;
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s;
        mp1[s] = i + 1; // (포켓몬의 이름, 도감 순서) 쌍을 이루므로 map 사용***
        mp2[i + 1] = s; // 문자열 <-> 숫자: 양방향 변환이 필요하므로 map 2개 사용***
    }
    for(int i = 0; i < M; i++){
        cin >> s;
        questions.push_back(s);
    }
    cout << '\n';
    
    for(int i = 0; i < M; i++){
        s = questions[i];
        if(atoi(s.c_str()) == 0){ // atoi(s.c_str()): 문자열이 숫자로 변환 불가능하면 0 반환
            cout << mp1[s] << '\n';
        }
        else{ // atoi(s.c_str()): 문자열을 숫자로 변환 가능하면 해당 숫자 반환
            cout << mp2[atoi(s.c_str())] << '\n';
        }
    }
    return 0;
}
