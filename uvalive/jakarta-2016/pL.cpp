#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int NUM = 20100;

#define int long long

struct job{
    int L,R,H;
    bool operator<(const job &j){ return L < j.L or (L == j.L and R < j.R); }
};

int N,M;
int dp[NUM];
job j[NUM];

int GO(int x){
    if(x >= M) return 0;
    if(dp[x] == -1){
        int L = x + 1,H = M - 1;
        while(L < H){
            int mid = (L + H) / 2;
            if(j[x].R <= j[mid].L) H = mid;
            else L = mid + 1;
        }
        if(j[x].R > j[L].L) dp[x] = max(GO(x+1),j[x].H);
        else dp[x] = max(GO(x+1),j[x].H + GO(L));
    }
    return dp[x];
}

#undef int

int main(){
    #define int long long
    int T; cin >> T; int C = 0;
    while(T--){
        cin >> N >> M;
        for(int i=0;i<M;i++){
            int X,A,B,H; cin >> X >> A >> B >> H;
            j[i] = {A,B,H};
            dp[i] = -1;
        }
        sort(j,j+M);
        cout << "Case #" << ++C << ": " << GO(0) << endl;
    }
    return 0;
}
