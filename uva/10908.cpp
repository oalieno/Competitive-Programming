#include<bits/stdc++.h>

using namespace std;

#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
#define SZ(x) ((int)x.size())
#define pb push_back
#define first ff
#define second ss

#define NUM 1000100

#define int long long

#undef int

int main(){
    #define int long long
    int T;cin >> T;
    while(T--){
        int M,N,Q;cin >> M >> N >> Q;cout << M << " " << N << " " << Q << endl;
        char grid[M][N];for(int i=0;i<M;i++)for(int j=0;j<N;j++)cin >> grid[i][j];
        for(int q=0;q<Q;q++){
            int x,y;cin >> x >> y;
            char jedi = grid[x][y];
            int ans = 0;
            for(int k=0;k<=min(min(x,y),min(M-x-1,N-y-1));k++){
                bool success = true;
                for(int i=x-k;i<=x+k;i++)for(int j=y-k;j<=y+k;j++)if(grid[i][j] != jedi){ success = false;break; }
                if(success)ans = k;
            }
            cout << 2*ans+1 << endl;
        }
    }
    return 0;
}

