//#include<bits/stdc++.h>
#include <iostream>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()

const int NUM = 110;
const int MOD = 10000;

void mul(int n, int A[NUM][NUM], int B[NUM][NUM], int C[NUM][NUM]) {
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) C[i][j] = (A[i][k] * B[k][j] % MOD + C[i][j]) % MOD;
}       

void power(int n, int m[NUM][NUM], int C[NUM][NUM], int y) {
    if(y == 0) {
        for(int i = 0; i < n; i++) C[i][i] = 1;
        return;
    }
    int k[NUM][NUM] = {};
    power(n, m, k, y / 2);
    if(y % 2) {
        int c1[NUM][NUM] = {};
        mul(n, k, k, c1);
        mul(n, c1, m, C);
    }
    else {
        mul(n, k, k, C);
    }
}

int main(){
    IOS;
    int k;
    while(cin >> k) {
        if(!k) break;
        int a[110], b[110];
        for(int i = 0; i < k; i++) cin >> a[i];
        for(int i = 0; i < k; i++) cin >> b[i];
        int index; cin >> index;
        int magic[NUM][NUM] = {};
        for(int i = 0; i < k; i++) magic[0][i] = b[i];
        for(int i = 1; i < k; i++) magic[i][i-1] = 1;
        if(index < k) cout << a[index] << endl;
        else {
            int jedi[NUM][NUM] = {};
            power(k, magic, jedi, index - k + 1);
            int answer = 0;
            for(int i = 0; i < k; i++) {
                answer = (jedi[0][i] * a[k - 1 - i] % MOD + answer) % MOD;
            }
            cout << answer << endl;
        }
    }
    return 0;
}
