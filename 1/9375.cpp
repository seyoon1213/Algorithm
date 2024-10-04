#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int n, m, p;
string s1, s2;

int main(){
    cin >> n;
    int answer[n];
    for(int i = 0; i < n; i++){
        map<string, int> mp;
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> s1 >> s2;
            if(mp.find(s2) == mp.end()){ // map.find(key): key가 없는 경우 map.end()를 반환***
                mp.insert({s2, 1}); // map.insert({key, value}): (key, value) 쌍을 삽입***
            }
            else{
                mp[s2] += 1; // key와 대응하는 value 값 변경***
            }
        }
        answer[i] = 1;
        for(auto it : mp){ // map 순회***
            answer[i] *= (it.second + 1); // it.first: key값, it.second: value값 접근***
        }
        answer[i] -= 1;
    } 

    for(int i = 0; i < n; i++){
        cout << answer[i] << '\n';
    }
    
    return 0;
}
