/*
    Author: OAlienO
    Country: Taiwan
    School: NCTU
*/
#include<bits/stdc++.h>

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
#define SZ(x) ((int)((x).size()))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

const int NUM = 510;

#define int long long

int N,H,W;
vector<pair<double,int>> E[NUM];

// Time Complexity : O(|E|log|V|)
vector<double> Dijkstra(int N,int S){
    // one-based
    vector<bool> visit(N+1,false);
    vector<double> D(N+1,1e20); // D -> Distance
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> P;
    P.push(mp(0.0,S));D[S] = 0.0;
    while(!P.empty()){
        double weight = P.top().ff;int now = P.top().ss;P.pop();
        if(visit[now])continue;
        visit[now] = true;
        for(auto i:E[now]){
            double potential = D[now]+i.ff;
            if(!visit[i.ss] && potential < D[i.ss]) P.push(mp(D[i.ss] = potential,i.ss));
        }
    }
    return D;
}

struct shadow{
    int x,y;
    int H,W;
    bool operator<(const shadow & sh) const {
        return y < sh.y;
    }
};

inline double power(double x){ return x*x; }

double distanceee(shadow A,shadow B){
    double dis = 0;
    double _11 = B.y-(A.y+A.H);
    double _12 = A.y-(B.y+B.H);
    double _21 = B.x-(A.x+A.W);
    double _22 = A.x-(B.x+B.W);
    if((B.x <= A.x && A.x <= B.x+B.W) || (B.x <= A.x+A.W && A.x+A.W <= B.x+B.W) ||
       (A.x <= B.x && B.x <= A.x+A.W) || (A.x <= B.x+B.W && B.x+B.W <= A.x+A.W))
    {
        if(A.y < B.y)dis = _11;
        else dis = _12;
    }
    else if((B.y <= A.y && A.y <= B.y+B.H) || (B.y <= A.y+A.H && A.y+A.H <= B.y+B.H) ||
            (A.y <= B.y && B.y <= A.y+A.H) || (A.y <= B.y+B.H && B.y+B.H <= A.y+A.H))
    {
        if(A.x < B.x)dis = _21;
        else dis = _22;
    }
    else{
        if(A.y < B.y && A.x < B.x)dis = sqrt(power(_11)+power(_21));
        else if(A.y < B.y && A.x >= B.x)dis = sqrt(power(_11)+power(_22));
        else if(A.y >= B.y && A.x < B.x)dis = sqrt(power(_12)+power(_21));
        else dis = sqrt(power(_12)+power(_22));
    }
    return dis;
}

#undef int

int main(){
    #define int long long
    FI("street.in");
    IOS;
    int T;cin >> T;
    while(T--){
        cin >> N >> H >> W;
        shadow sh[N+1];
        for(int i=1;i<=N;i++){
            int a,b,c,d;cin >> a >> b >> c >> d;
            sh[i].x = (d == 0) ? 0 : W-b;
            sh[i].y = c;
            sh[i].H = a;
            sh[i].W = b;
        }
        for(int i=1;i<=N;i++){
            E[N+1].pb(mp(sh[i].y,i));
            E[i].pb(mp(H-(sh[i].y+sh[i].H),N+2));
            for(int j=i+1;j<=N;j++){
                if(i == j)continue;
                E[i].pb(mp(distanceee(sh[i],sh[j]),j));
                E[j].pb(mp(distanceee(sh[i],sh[j]),i));
            }
        }
        vector<double> D = Dijkstra(N+2,N+1);
        cout << fixed << setprecision(6) << D[N+2] << endl;
    }
    return 0;
}
