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

const int NUM = 50010;

vector<pair<int,int>> E[NUM]; // index, value
bool super[NUM];

void check(int now, int parent, int parent_value){
    if(not super[now]) return;
    super[now] = false;
    for(auto child:E[now]){
        if(child.ff == parent) continue;
        if(child.ss == parent_value){
            cout << 0 << endl;
            exit(0);
        }
        check(child.ff, now, child.ss);
    }
}

void DFS(int now, int parent){
    // initialize
    vector<int> jedi;
    int parent_value = -1;
    for(auto child:E[now]){
        if(child.ff == parent){ parent_value = child.ss; continue; }
        jedi.pb(child.ss);
    }
    sort(jedi.begin(), jedi.end());

    // parent == child
    for(auto child:E[now]){
        if(child.ff == parent) continue;
        if(child.ss == parent_value){
            check(parent, now, parent_value);
            check(child.ff, now, child.ss);
        }
    }

    // child == child
    for(auto child:E[now]){
        if(child.ff == parent) continue;
        int L = distance(jedi.begin(), lower_bound(jedi.begin(), jedi.end(), child.ss));
        int R = distance(jedi.begin(), upper_bound(jedi.begin(), jedi.end(), child.ss));
        if(R - L > 1) check(child.ff, now, child.ss);
        if(super[child.ff]) DFS(child.ff, now);
    }
}

#undef int

int main(){
    #define int long long
    int N; cin >> N;
    for(int i=0;i<N;i++) super[i] = true;
    for(int i=0;i<N-1;i++){
        int u, v, c; cin >> u >> v >> c; u--; v--; c--;
        E[u].pb({v, c});
        E[v].pb({u, c});
    }
    DFS(0, -1);
    vector<int> ans;
    for(int i=0;i<N;i++) if(super[i]) ans.pb(i + 1);
    cout << SZ(ans) << endl;
    for(auto i:ans) cout << i << endl;
    return 0;
}
/*
8
1 3 1
2 3 1
3 4 3
4 5 4
5 6 3
6 7 2
6 8 2

8
1 2 2
1 3 1
2 4 3
2 7 1
3 5 2
5 6 2
7 8 1

9
1 2 2
1 3 1
1 4 5
1 5 5
2 6 3
3 7 3
4 8 1
5 9 2

10
9 2 1 
9 3 1
9 4 2
9 5 2
9 1 3
9 6 4
1 8 5
1 10 5
6 7 9
*/
