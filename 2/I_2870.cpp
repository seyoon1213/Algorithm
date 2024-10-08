#include <stdio.h>
#include <iostream>

using namespace std;

int N;
vector<string> v;
vector<int> number;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(string s : v){
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c >= '0' && c <= '9'){
                temp += c;
            }
            else{
                if(temp.size() != 0){
                    int n = atoi(temp.c_str()); // atoi(string.c_str()): string 객체 -> int 변수***
                    /*
                    int n = 0;
                    for(int j = 0; j < temp.size(); j++){
                        n += int(temp[j] - '0') * pow(10, temp.size() - j - 1);
                    }
                    */
                    number.push_back(n);
                    temp = "";
                }
            }
        }
        if(temp.size() != 0){
            int n = atoi(temp.c_str());
            /*
            int n = 0;
            for(int j = 0; j < temp.size(); j++){
                n += int(temp[j] - '0') * pow(10, temp.size() - j - 1);
            }
            */
            number.push_back(n);
        }
    }

    sort(number.begin(), number.end(), less<int>());

    for(int i : number){
        cout << i << '\n';
    }

    return 0;
}
