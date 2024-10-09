#include <stdio.h>
#include <iostream>

using namespace std;

int n;

int main(){

    cin >> n;
    int i = 666;
    for( ; ; i++){
        if(to_string(i).find("666") != string::npos) n--;
        // string to_string(int num): 정수 -> 문자열로 변환***
        // string.find("부분 문자열"): 부분 문자열의 시작 위치 or string::npos 반환***
        if(n == 0) break;
    }
    cout << i << '\n';

    return 0;
}
