#include <stdio.h>
#include <iostream>

using namespace std;
typedef unsigned long long ll;

ll N, n;
vector<ll> A;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;
        A.push_back(n);
    }

    for(int i = 0; i < N - 1; i++){
        bool flag = false;
        for(int j = i + 1; j < N; j++){
            if(A[j] > A[i]){
                flag = true;
                cout << A[j] << " ";
                break;
            }
        }
        if(!flag) cout << "-1" << " ";
    }
    cout << "-1" << '\n';
    return 0;
}
