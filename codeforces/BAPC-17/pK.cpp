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

const int NUM = 1000;

int N;
bool E[NUM][NUM];
bool visit[NUM];
vector<int> ans;

void DFS(int now, int p) {
    visit[now] = true;
    for(int i = 0; i < N; i++) {
        if(i == now or i == p or E[now][i] == false) continue;
        if(not visit[i]) DFS(i, now);
    }
    ans.push_back(now);
}

#undef int

int main(){
    #define int long long
    cin >> N;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
        char c; cin >> c;
        if(c == '1') E[i][j] = true;
        else E[i][j] = false;
    }
    memset(visit, 0, sizeof(visit));
    DFS(0, -1);
    if(SZ(ans) != N) cout << "impossible" << endl;
    else for(auto a:ans) cout << a << " "; cout << endl;
    return 0;
}
