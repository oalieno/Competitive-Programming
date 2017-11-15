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

#undef int

int main(){
    #define int long long
    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        int tasks[N]; for(int i=0;i<N;i++) cin >> tasks[i];
        int workers[M]; for(int i=0;i<M;i++) cin >> workers[i];
        sort(tasks, tasks + N);
        sort(workers, workers + M);
        int now = 0, ans = 0;
        bool success = true;
        for(int i=0;i<N;i++){
            while(now < M and workers[now] < tasks[i]) now++;
            if(now == M){ success = false; break; }
            ans += workers[now] * workers[now];
            now++;
        }
        if(success) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}
