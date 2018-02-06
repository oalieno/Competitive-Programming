#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())

const int NUM = 1000;

int main() {
#define int long long
    int T; cin >> T;
    while(T--) {
        vector<int> E[NUM + 100];
        int M, N; cin >> M >> N;
        for(int i = 0; i < M; i++) {
            int x, y; cin >> x >> y;
            E[x].push_back(y);
            E[y].push_back(x);
        }
        
        bool ans[NUM + 10][NUM + 10] = {};

        for(int i = 0; i < N; i++) {
            int visit[NUM + 100]; memset(visit, -1, sizeof(visit));
            int layer = 0;
            queue<int> Q; Q.push(i); visit[i] = 0;
            while(not Q.empty()){
                layer++;
                int len = Q.size();
                for(int j = 0; j < len; j++) {
                    int now = Q.front(); Q.pop();
                    bool success = false;
                    for(auto x:E[now]) {
                        if(visit[x] == layer or visit[x] == -1) success = true;
                        if(visit[x] != -1) continue;
                        visit[x] = layer;
                        Q.push(x);
                    }
                    if(success) {
                        int a = i, b = now; if(a > b) swap(a, b);
                        ans[a][b] = true;
                    }
                }
            }
        }
        
        int sum = 0;

        for(int i = 0; i < N; i++) for(int j = i + 1; j < N; j++) {
            if(ans[i][j] == false) sum++;
        }

        cout << sum << endl;
    }
    return 0;
}
