#include <stdio.h>
#include <iostream>

using namespace std;

int H, W;
int V[100][100];
int cloud[100][100];

int main(){
    cin >> H >> W;
 
    for(int i = 0; i < H; i++){
        string s;
        cin >> s;
        for(int j = 0; j < W; j++){
            V[i][j] = s[j];
            if(s[j] == 'c'){
                cloud[i][j] = 0;
            }
            else{
                cloud[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 1; j < W; j++){
            if(V[i][j] == '.' && cloud[i][j - 1] != -1){
                cloud[i][j] = cloud[i][j - 1] + 1;
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << cloud[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
