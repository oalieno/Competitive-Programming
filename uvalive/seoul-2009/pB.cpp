#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int NUM = 50;

#define int long long

#undef int

int main(){
    #define int long long
    //IOS;
    int T; cin >> T;
    while(T--){
        int N,M,len = 0; cin >> N >> M;
        char region[NUM][NUM];
        vector<int> E[NUM];
        bool beside[NUM][NUM] = {};
        for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin >> region[i][j];
        for(int i=0;i<N;i++) for(int j=0;j<M;j++){
            int now = region[i][j] - 'A'; len = max(len,now+1);
            int right = -1,down = -1;
            if(j+1 < M) right = region[i][j+1] - 'A';
            if(i+1 < N) down = region[i+1][j] - 'A';
            if(right != -1) beside[now][right] = beside[right][now] = true;
            if(down != -1) beside[now][down] = beside[down][now] = true;
        }
        for(int i=0;i<len;i++) for(int j=0;j<len;j++) if(i != j and beside[i][j]) E[i].push_back(j);

        // troop support calculate
        pair<int,int> troop[len]; for(int i=0;i<len;i++){ cin >> troop[i].ff; troop[i].ss = i; }
        int support[len]; for(int i=0;i<len;i++) support[i] = troop[i].ff/(E[i].size()+1);
        for(int i=0;i<len;i++) for(auto j:E[i])troop[j].ff += support[i];

        // solve
        bool victory = true; int saruman; cin >> saruman;
        for(int i=0;i<len;i++){
            sort(troop,troop+len);
            if(troop[i].ff >= saruman){ victory = false; break; }
            for(auto j:E[troop[i].ss]){
                int neighbor; for(int k=0;k<len;k++) if(troop[k].ss == j) neighbor = k;
                troop[neighbor].ff -= support[j] + support[troop[i].ss];
            }
        }
        if(victory) cout << "Saruman" << endl;
        else cout << "Human" << endl;
    }
    return 0;
}
