#include <stdio.h>
#include <iostream>

using namespace std;

int N, M, J;

int main(){
    cin >> N >> M;
    cin >> J;
    int array[J];
    memset(array, 0, sizeof(array)); // memset(시작 위치, 초기화 값, 크기)***
    for(int i = 0; i < J; i++){
        int n;
        cin >> n;
        array[i] = n - 1;
    }
    int answer = 0;
    int left = 0;
    int right = left + M - 1;
    for(int i = 0; i < J; i++){
        if(array[i] < left){
            answer += (left - array[i]);
            left = array[i];
            right = array[i] + M - 1;
        }
        else if(array[i] > right){
            answer += (array[i] - right);
            left = array[i] - M + 1;
            right = array[i];
        }
    }
    cout << answer << '\n';
    return 0;
}
