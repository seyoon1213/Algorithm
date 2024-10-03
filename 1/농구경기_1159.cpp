#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int eng[26];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        string name;
        cin >> name;
        eng[int(name[0] - 'a')] += 1;
    }

    for(int i = 0; i < 26; i++){
        if(eng[i] >= 5){
            cout << char(i + 'a');
        }
    }
    cout << '\n';

    return 0;
}
