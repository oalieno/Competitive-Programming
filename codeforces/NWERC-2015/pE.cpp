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
        int v, f, re, id;
        Edge(int v, int f, int re, int id)
            : v(v)
            , f(f)
            , re(re)
            , id(id)
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
    void AddEdge(int u, int v, int c, int id)
    {
        E[u].pb({ v, c, SZ(E[v]), id });
        E[v].pb({ u, 0, SZ(E[u]) - 1, id });
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
    char oper[3] = {'+','-','*'};
    int N; cin >> N;
	Dinic D(4 * N + 2,0,1);
    int s = 0, t = 1;
	map<int,int> node;
    pair<int,int> equation[N+10];
    int now = 2 + N,index;
    for(int i=2;i<N+2;i++){
        int x,y; cin >> x >> y; equation[i] = {x,y};
        D.AddEdge(s,i,1,0);
        
        if(node.find(x+y) != node.end()) index = node[x+y];
        else{ index = node[x+y] = now++; D.AddEdge(index,t,1,0); }
        D.AddEdge(i,index,1,0);
        
        if(node.find(x-y) != node.end()) index = node[x-y];
        else{ index = node[x-y] = now++; D.AddEdge(index,t,1,0); }
        D.AddEdge(i,index,1,1);
        
        if(node.find(x*y) != node.end()) index = node[x*y];
        else{ index = node[x*y] = now++; D.AddEdge(index,t,1,0); }
        D.AddEdge(i,index,1,2);
    }
    int ans = D.Flow();
    if(ans != N){
        puts("impossible");
        return 0;
    }
    for(int i=2;i<N+2;i++){
        for(auto j:D.E[i]){
            if(j.v != s and j.f == 0){
                int result;
                if(j.id == 0) result = equation[i].ff + equation[i].ss;
                else if(j.id == 1) result = equation[i].ff - equation[i].ss;
                else result = equation[i].ff * equation[i].ss;
                cout << equation[i].ff << " " << oper[j.id] << " " << equation[i].ss << " = " << result << endl;
            }
        }
    }
    return 0;
}
