#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int NUM = 150;

#define int long long

int N,K;
int A[NUM],prefix[NUM];
int dp[NUM][NUM];

int go(int n,int k){
    if(k == 1) return prefix[n-1] * n;
    if(dp[n][k] == -1){
        int ans = LLONG_MAX;
        for(int i=k-1;i<n;i++){
            int now = go(i,k-1) + (prefix[n-1] - prefix[i-1]) * n;
            ans = min(ans,now);
        }
        dp[n][k] = ans;
    }
    return dp[n][k];
}

#undef int

int main(){
    #define int long long
    //IOS;
    int T; cin >> T;
    while(T--){
        cin >> N >> K;
        for(int i=0;i<N;i++) cin >> A[i]; sort(A,A+N); reverse(A,A+N);
        prefix[0] = A[0]; for(int i=1;i<N;i++) prefix[i] = A[i] + prefix[i-1];
        for(int i=0;i<=N;i++) for(int j=0;j<=K;j++) dp[i][j] = -1;
        double ans = go(N,K);
        cout << fixed << setprecision(4) << ans/(double)(prefix[N-1]) << endl;
    }
    return 0;
}
