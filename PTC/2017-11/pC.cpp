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

const int NUM = 3100;

struct Edge{
    int y, c, index;
    bool operator<(const Edge &E) const {
        return c < E.c;
    }
};

vector<Edge> E[NUM];
int counter[NUM];

void DFS(int now, int parent, vector<Edge> &S){
    if(parent != -1){
        int index = distance(S.begin(), lower_bound(S.begin(), S.end(), (Edge){-1, S.back().c / 2, -1}));
        if(S[index].c == S.back().c / 2){
            counter[S[index].index]++;
            counter[S[index+1].index]++;
        }
        else{
            counter[S[index].index]++;
        }  
    }
    for(auto &i:E[now]){
        if(i.y == parent) continue;
        S.push_back({i.y, S.back().c + i.c, i.index});
        DFS(i.y, now, S);
        S.pop_back();
    }
}

#undef int

int main(){
    #define int long long
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for(int i=0;i<N;i++) E[i].clear();
        for(int i=1;i<N;i++){
            int x, y, c; cin >> x >> y >> c;
            c *= 2;
            E[x].pb({y, c, i-1});
            E[y].pb({x, c, i-1});
        }
        memset(counter, 0, sizeof(counter));
        for(int i=1;i<=N;i++){
            vector<Edge> S; S.push_back({-1, 0, -1});
            DFS(i, -1, S);
        }
        sort(counter, counter + N - 1);
        cout << counter[(N-1+1)/2-1]/2 << " " << counter[N-1-1]/2 << endl;
    }
    return 0;
}
