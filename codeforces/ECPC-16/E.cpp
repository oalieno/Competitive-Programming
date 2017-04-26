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

#define int long long

#undef int

int main(){
    #define int long long
    FI("jumping.in");
    IOS;
    int T;cin >> T;
    while(T--){
        int N;cin >> N;
        vector<int> E[N];
        int A[N],ans[N];for(int i=0;i<N;i++){ cin >> A[i];ans[i] = -1; }
        for(int i=0;i<N;i++){
            if(0 <= i+A[i] && i+A[i] < N)E[i+A[i]].pb(i);
            if(0 <= i-A[i] && i-A[i] < N)E[i-A[i]].pb(i);
        }
        queue<int> Q;Q.push(N-1);
        int value = 0;
        while(!Q.empty()){
            int L = Q.size();
            for(int i=0;i<L;i++){
                int now = Q.front();Q.pop();
                if(ans[now] != -1)continue;
                ans[now] = value;
                for(auto j:E[now])if(ans[j] == -1)Q.push(j);
            }
            value++;
        }
        for(int i=0;i<N;i++)cout << ans[i] << endl;
    }
    return 0;
}
