#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int n, c;
map<int, int> mp; // 숫자, 처음 입력된 시각
vector<pair<int, int>> v; // 입력 횟수, 숫자

bool cmp(pair<int, int> a, pair<int, int> b){ // 커스텀 비교함수: 반환 값이 참이 되도록 정렬***
    if(a.first == b.first){ // 입력 횟수가 동일한 경우
        return mp[a.second] < mp[b.second]; // 처음 입력된 시각이 빠른 순으로 정렬***
    }
    return a.first > b.first; // 입력 횟수가 많은 순으로 정렬***
}

int main(){
    cin >> n >> c;
    int array[n];
    int number[c + 1]; // 주의***
    memset(array, 0, sizeof(array));
    memset(number, 0, sizeof(number));

    for(int i = 0; i < n; i++){
        cin >> array[i];
        number[array[i]]++;
        if(mp[array[i]] == 0){
            mp[array[i]] = i + 1; // mp[array[i]] = i인 경우 문제 발생***
        }
    }

    for(int i = 1; i < c + 1; i++){
        if(number[i] != 0){
            v.push_back({number[i], i}); // map: 정렬 불가능***
        }
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].first; j++){
            cout << v[i].second << " ";
        }
    }
    cout << '\n';

    return 0;
}
