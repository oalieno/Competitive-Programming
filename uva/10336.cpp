#include<bits/stdc++.h>

using namespace std;

#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
#define SZ(x) ((int)x.size())
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#define NUM 110

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

#define int long long

int N,M;
char grid[NUM][NUM];
bool visit[NUM][NUM];

void Go(int x,int y,char ch){
    if(visit[x][y])return;
    visit[x][y] = true;
    for(int k=0;k<4;k++){
        int xx = x+dx[k];
        int yy = y+dy[k];
        if(0 <= xx && xx < N && 0 <= yy && yy < M && grid[xx][yy] == ch)Go(xx,yy,ch);
    }
}

#undef int

int main(){
    #define int long long
    int T;cin >> T;
    int C = 0;
    while(T--){
        for(int i=0;i<NUM;i++)for(int j=0;j<NUM;j++)visit[i][j] = false;
        cin >> N >> M;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin >> grid[i][j];
        map<char,int> lang;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++){
            if(!visit[i][j]){
                lang[grid[i][j]]++;
                Go(i,j,grid[i][j]);
            }
        }
        cout << "World #" << ++C << endl;
        vector<pair<int,char> > ans;
        for(map<char,int>::iterator it=lang.begin();it != lang.end();it++)ans.pb(mp(-(it->ss),it->ff));
        sort(ans.begin(),ans.end());
        for(int i=0;i<SZ(ans);i++)cout << ans[i].ss << ": " << -(ans[i].ff) << endl;
    }
    return 0;
}

