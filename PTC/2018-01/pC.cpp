#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define NUM 50000

struct Edge {
    int c, y;
	bool operator<(const Edge & e) const {
        return c < e.c;
    }
	bool operator>(const Edge & e) const {
        return c > e.c;
    }
};

vector<Edge> E[NUM + 100];

int check(int parent, int now, vector<bool> &visit) {
    if(visit[now]) return false;
    visit[now] = true;
    int sum = 1;
    for(auto x:E[now]) {
        if(x.y == parent) continue;
        sum += check(now, x.y, visit);
    }
    return sum;
}

vector<int> Dijkstra(int N, int S){
    vector<bool> visit(N + 10, false);
    vector<int> D(N + 10, INT_MAX); // D -> Distance
    priority_queue<Edge, vector<Edge>, greater<Edge>> P;
    P.push({0, S}); D[S] = 0;
    while(!P.empty()){
        int now = P.top().y; P.pop();
        if(visit[now]) continue;
        visit[now] = true;
        for(auto i:E[now]) {
            int potential = D[now] + i.c;
            if(!visit[i.y] && potential < D[i.y]) P.push({D[i.y] = potential, i.y});
        }
    }
    return D;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for(int i = 0; i < N; i++) E[i].clear();
        int total = 0;
        for(int i = 0; i < N - 1; i++) {
            int x, y, c; cin >> x >> y >> c;
            E[x].push_back({c, y});
            E[y].push_back({c, x});
            total += c;
        }
        
        vector<bool> visit(N, false);
        int sum = check(-1, 0, visit);
        if(sum < N) {
            cout << -1 << endl;
            continue;
        }

        vector<int> result;
        result = Dijkstra(N, 0);
        int big = 0, index;
        for(int i = 0; i < N; i++) {
            if(big < result[i]) {
                big = result[i];
                index = i;
            }
        }

        big = 0;
        result = Dijkstra(N, index);
        for(int i = 0; i < N; i++) {
            big = max(big, result[i]);
        }
        cout << total * 2 - big << endl;
        
    }
    return 0;
}
