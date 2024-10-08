#include <stdio.h>
#include <iostream>

using namespace std;

bool flag(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}
int main(){
    vector<string> v;
    while(true){
        string s;
        cin >> s;
        if(s == "end"){
            break;
        }
        v.push_back(s);
    }
    for(string s : v){
        int number = 0;
        bool answer = true;
        for(int i = 0; i < s.length(); i++){
            if(flag(s[i])){
                number++;
            }
            if(i > 0 && i < s.length() - 1){
                if(flag(s[i - 1]) == flag(s[i]) && flag(s[i]) == flag(s[i + 1])){
                    answer = false;
                    break;
                }
            }
            if(i < s.length() - 1){
                if(s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o'){
                    answer = false;
                    break;
                }
            }
        }

        if(answer == true && number > 0){
            cout << "<" << s << "> is acceptable.\n";
        }
        else{
            cout << "<" << s << "> is not acceptable.\n";
        }
    }
    return 0;
}
