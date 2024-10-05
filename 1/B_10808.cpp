#include <stdio.h>
#include <iostream>

using namespace std;

string s;
int eng[26];
int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        int alphabet = int(s[i] - 'a');
        eng[alphabet] += 1;
    }

    for(int i = 0; i < 26; i++){
        cout << eng[i] << " ";
    }
    cout << '\n';
    return 0;
}
