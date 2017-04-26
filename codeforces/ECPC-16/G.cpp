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

const int MOD = 1000000007;

#define int long long

int Power(int x,int p,int m){
    if(p == 0)return 1;
    int k = Power(x,p/2,m);
    if(p%2)return k*k%m*x%m;
    else return k*k%m;
}

int inverse(int A,int M){
    return Power(A,M-2,M);
}

#undef int

int main(){
    #define int long long
    FI("galactic.in");
    IOS;
    int T;cin >> T;
    while(T--){
        int N,K;cin >> N >> K;
        if(K > N){ cout << 0 << endl;continue; }
        int C = 1;
        int ans = C*Power(K,N,MOD)%MOD,sign = -1;
        for(int i=1;i<=K;i++){
            C = C*(K-i+1)%MOD*inverse(i,MOD)%MOD;
            ans = (ans + sign*(C*Power(K-i,N,MOD)%MOD) + MOD)%MOD;
            sign *= -1;
        }
        cout << ans << endl;
    }
    return 0;
}
