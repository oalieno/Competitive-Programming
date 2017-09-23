#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define int long long

int J(int n, int k, int p){
    int ans = ( k - 1 ) % p;
    for(int i=p+1;i<=n;i++){
        ans = ( ans + k ) % i;
    }
    return ans;
}

#undef int

int main(){
    #define int long long
    //IOS;
    int T; cin >> T;
    while(T--){
        int N,K; cin >> N >> K;
        cout << J(N,K,3)+1 << " " << J(N,K,2)+1 << " " << J(N,K,1)+1 << endl;
    }
    return 0;
}
