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

const int NUM = 105;
const int SMALL = -100000;

int dp[NUM][NUM][4];
string A,B;

int GO(int x, int y, int status){
    if(x == 0 and y == 0) return 0;
    if(dp[x][y][status] == SMALL){
        int ans = SMALL, current;
        if(x != 0 and y != 0){
            current = A[SZ(A) - x] == B[SZ(B) - y] ? 1 : -2;
            ans = max(ans, GO(x - 1, y - 1, 0) + current);
        }
        if(y != 0){
            current = -1; if(!(status & 2)) current -= 4;
            ans = max(ans, GO(x, y - 1, 2) + current);
        }
        if(x != 0){
            current = -1; if(!(status & 1)) current -= 4;
            ans = max(ans, GO(x - 1, y, 1) + current);
        }
        dp[x][y][status] = ans;
    }
    return dp[x][y][status];
}

#undef int

int main(){
    #define int long long
    int T; cin >> T;
    while(T--){
        for(int i=0;i<NUM;i++) for(int j=0;j<NUM;j++) for(int k=0;k<4;k++) dp[i][j][k] = SMALL;
        cin >> A >> B;
        cout << GO(SZ(A),SZ(B),0) << endl;
    }
    return 0;
}
