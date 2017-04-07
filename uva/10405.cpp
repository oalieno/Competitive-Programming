#include<bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define pb push_back
#define first ff
#define second ss

#define NUM 1010

#define int long long

int dp[NUM][NUM];

#undef int

int main(){
    #define int long long
    string A,B;
    while(cin >> A >> B){
        for(int i=0;i<=SZ(A);i++)dp[i][0] = 0;
        for(int i=0;i<=SZ(B);i++)dp[0][i] = 0;
        for(int i=1;i<=SZ(A);i++)for(int j=1;j<=SZ(B);j++)dp[i][j] = max(dp[i-1][j-1]+(A[i-1] == B[j-1]),max(dp[i-1][j],dp[i][j-1]));
        cout << dp[SZ(A)][SZ(B)] << endl;
    }
    return 0;
}

