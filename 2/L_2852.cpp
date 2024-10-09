#include <stdio.h>
#include <iostream>

using namespace std;

int n;

int times[48 * 60];

int main(){
    cin >> n;

    int team[n];
    int mm[n];
    int ss[n];

    for(int i = 0; i < n; i++){
        scanf("%d %d:%d", &team[i], &mm[i], &ss[i]); // 입력되는 문자열의 형식이 일정한 경우***
    }
    int idx = 0;
    int t1 = 0;
    int t2 = 0;
    for(int i = 0; i < 48 * 60; i++){
        if(idx < n){
            if(i == mm[idx] * 60 + ss[idx]){
                if(team[idx] == 1) t1++;
                if(team[idx] == 2) t2++;
                idx++;
            }
        }
        if(t1 - t2 > 0){
            times[i] = 1;
        }
        else if(t1 - t2 < 0){
            times[i] = 2;
        }
        else{
            times[i] = 0;
        }
    }

    int s1 = 0;
    int s2 = 0;
    for(int i = 0; i < 48 * 60; i++){
        if(times[i] == 1) s1++;
        if(times[i] == 2) s2++;
    }
    
    printf("%02d:%02d\n", s1 / 60, s1 % 60); // %02d: 여백에 0을 추가하여 2자리만 출력***
    printf("%02d:%02d\n", s2 / 60, s2 % 60); // %.2f: 소수점 아래 2자리만 출력***

    return 0;
}
