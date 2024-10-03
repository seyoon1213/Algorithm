#include <stdio.h>
#include <iostream>

using namespace std;

int n1, n2, n3;
int As, Ae, Bs, Be, Cs, Ce;
int times[100];
int main(){
    cin >> n1 >> n2 >> n3;
    cin >> As >> Ae;
    cin >> Bs >> Be;
    cin >> Cs >> Ce;

    for(int i = As - 1; i < Ae - 1; i++){
        times[i] += 1;
    }
    for(int i = Bs - 1; i < Be - 1; i++){
        times[i] += 1;
    }
    for(int i = Cs - 1; i < Ce - 1; i++){
        times[i] += 1;
    }
    int answer = 0;
    for(int i = 0; i < 100; i++){
        if(times[i] == 1){
            answer += n1;
        }
        if(times[i] == 2){
            answer += n2 * 2;
        }
        if(times[i] == 3){
            answer += n3 * 3;
        }
    }

    cout << answer;
    return 0;
}
