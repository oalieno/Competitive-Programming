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

struct Dinic {
    struct Edge {
        int v, f, re;
        Edge(int v, int f, int re)
            : v(v)
            , f(f)
            , re(re)
        {
        }
    };
    vector<vector<Edge> > E;
    vector<int> level;
    int N, s, t;
    Dinic(int N, int s, int t)
        : N(N)
        , s(s)
        , t(t)
    {
        E.resize(N + 1);
    }
    void AddEdge(int u, int v, int c)
    {
        E[u].pb({ v, c, SZ(E[v]) });
        E[v].pb({ u, 0, SZ(E[u]) - 1 });
    }
    bool BFS()
    {
        level.clear();
        for (int i = 0; i <= N; i++)
            level.pb(-1);
        queue<int> Q;
        Q.push(s);
        level[s] = 0;
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for (auto i : E[now]) {
                if (i.f > 0 && level[i.v] == -1) {
                    level[i.v] = level[now] + 1;
                    Q.push(i.v);
                }
            }
        }
        return level[t] != -1;
    }
    int DFS(int now, int nf)
    {
        if (now == t)
            return nf;
        int ans = 0;
        for (auto& i : E[now]) {
            if (i.f > 0 && level[i.v] == level[now] + 1) {
                int tf = DFS(i.v, min(nf, i.f));
                ans += tf;
                nf -= tf;
                i.f -= tf;
                E[i.v][i.re].f += tf;
                if (nf == 0)
                    return ans;
            }
        }
        if (!ans)
            level[now] = -1;
        return ans;
    }
    int Flow()
    {
        int ans = 0;
        while (BFS())
            ans += DFS(s, INT_MAX);
        return ans;
    }
};

#undef int

int main(){
    #define int long long
    int T; cin >> T;
	while(T--){
	    int room[5]; for(int i=0;i<5;i++) cin >> room[i];
        int N; cin >> N;
        int s = 1, t = 2;
        Dinic D(N+5+2,s,t);
        for(int i=0;i<5;i++) D.AddEdge(3+i,t,room[i]);
        for(int i=0;i<N;i++){
            char jedi,master; cin >> jedi >> master;
            D.AddEdge(s,8+i,1);
            D.AddEdge(8+i,3+(jedi-'A'),1);
            D.AddEdge(8+i,3+(master-'A'),1);
        }
        int ans = D.Flow();
        if(ans == N) cout << "YES" << endl;
        else cout << "NO" << endl;
	}
    return 0;
}
