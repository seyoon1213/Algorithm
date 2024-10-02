#include <stdio.h>
#include <iostream>

using namespace std;

vector<int> v;
vector<int> s;

void print(int i, int j){
    for(int k : v){
        if(k != i && k != j){
            cout << k << '\n';
        }
    }
    cout << '\n';
}

void printCombi(){
    for(int k : v){
        if(k != s[0] && k != s[1]){
            cout << k << '\n';
        }
    }
    cout << '\n';
}

void printPermutation(){
    for(int i = 0; i < 7; i++){
        cout << v[i] << '\n';
    }
    cout << '\n';
}

void permutation(int depth){
    if(depth == 7){
        int sum = 0;
        for(int i = 0; i < 7; i++){
            sum += v[i];
        }
        if(sum == 100){
            sort(v.begin(), v.begin() + 7);
            printPermutation();
            exit(0);
        }
    }

    for(int i = depth; i < 9; i++){
        swap(v[i], v[depth]);
        permutation(depth + 1);
        swap(v[i], v[depth]);
    }
    return;
}

void combi(int index, int total){
    if(s.size() == 2){
        if((s[0] + s[1]) == (total - 100)){
            printCombi();
            exit(0);
        }
    }
    for(int i = index + 1; i < 9; i++){
        s.push_back(v[i]);
        combi(i, total);
        s.pop_back();
    }
    return;
}

int main(){
    int total = 0;
    for(int i = 0; i < 9; i++){
        int n;
        cin >> n;
        v.push_back(n);
        total += n;
    }
    cout << '\n';

    sort(v.begin(), v.end());

    // Combination #1
    
    bool found = false;
    for(int i = 0; i < 9 && !found; i++){
        for(int j = i + 1; j < 9; j++){
            if(total - v[i] - v[j] == 100){
                print(v[i], v[j]);
                found = true;
            }
        }
    }
    

    // Permutation #1
    
    do{
        int sum = 0;
        for(int i = 0; i < 7; i++){
            sum += v[i];
        }
        if(sum == 100){
            sort(v.begin(), v.begin() + 7); // 생략 가능
            for(int i = 0; i < 7; i++){
                cout << v[i] << '\n';
            }
            cout << '\n';
            break;
        }
    }while(next_permutation(v.begin(), v.end()));
    

    // Combination #2
    combi(-1, total);

    // Permutation #2
    permutation(0);

    return 0;
}
