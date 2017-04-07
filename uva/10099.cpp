include<bits/stdc++.h>
  
using namespace std;

#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
#define SZ(x) ((int)x.size())
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#define NUM 110

#define int long long

int N,M;
int head,tail,people;
int ans[NUM];
vector<pair<int,int> > E[NUM];
bool visit[NUM];
  
void DFS(int now,int value){
    if(now == head){ ans[now] = max(ans[now],value);return; }
    if(now == tail || value <= ans[now])return;
    ans[now] = value;
    for(int i=0;i<SZ(E[now]);i++){
        DFS(E[now][i].ff,min(value,E[now][i].ss));
    }
}
  
  #undef int
 
int main(){
    #define int long long
    int C = 0;
    while(cin >> N >> M){
        if(!N && !M)break;
        for(int i=1;i<=N;i++){ E[i].clear();visit[i] = false;ans[i] = 0; }
        for(int i=0;i<M;i++){
            int x,y,c;cin >> x >> y >> c;
            E[x].pb(mp(y,c));
            E[y].pb(mp(x,c));
        }
        cin >> head >> tail >> people;
        visit[tail] = true;
        for(int i=0;i<SZ(E[tail]);i++)DFS(E[tail][i].ff,E[tail][i].ss);
        int maxi = ans[head];
        cout << "Scenario #" << ++C << endl;
        cout << "Minimum Number of Trips = " << people/(maxi-1)+(people%(maxi-1) != 0) << endl << endl;
    }
    return 0;
}
