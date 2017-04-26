/*
    Author: OAlienO
    Country: Taiwan
    School: NCTU
*/
#include<bits/stdc++.h>

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
#define SZ(x) ((int)((x).size()))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

const int NUM = 50;

#define int long long

int dp[NUM][NUM];

int C(int N,int M){
    if(M > N/2)M = N-M;
    if(M == 0)return 1;
    if(dp[N][M] == -1)dp[N][M] = C(N-1,M)+C(N-1,M-1);
    return dp[N][M];
}

#undef int

int main(){
    #define int long long
    FI("popcorn.in");
    IOS;
    for(int i=0;i<NUM;i++)for(int j=0;j<NUM;j++)dp[i][j] = -1;
    int T;cin >> T;
    while(T--){
        int N,M;cin >> N >> M;
        cout << C(N,M) << endl;
    }
    return 0;
}
