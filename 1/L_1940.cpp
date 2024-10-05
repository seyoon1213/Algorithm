#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int N, M;
int answer = 0;
vector<int> v;
void combi(int depth, int* array){
    if(v.size() == 2){
        if(v[0] + v[1] == M){
            answer++;
        }
        return;
    }
    else{
        for(int i = depth + 1; i < N; i++){
            v.push_back(array[i]);
            combi(i, array);
            v.pop_back();
        }
        return;
    }
}

int main(){
    cin >> N >> M;
    int array[N];
    for(int i = 0; i < N; i++){
        cin >> array[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(array[i] + array[j] == M){
                answer++;
                array[i] = 0;
                array[j] = 0;
            }
        }
    }

    //combi(-1, array);
    cout << answer << '\n';
    return 0;
}
