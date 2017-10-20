#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define NUM 100100

#define int long long

struct BITRMQ{
    vector<int> val,LT,RT;
    
    BITRMQ(){}
    BITRMQ(int n,int v):val(n+1,v){
        LT.resize(n+1); RT.resize(n+1);
        for(int i=0;i<=n;i++) LT[i] = RT[i] = i;
    }

    inline int lsb(int x){ return x & -x; }

    int query(int a,int b){
        int s = LLONG_MAX,i = a,x = a,y = b;

        while(x + lsb(x) <= b){
            if(s > val[RT[x]]){ s = val[RT[x]]; i = RT[x]; }
            x += lsb(x);
        }
        if(s > val[x]){ s = val[x]; i = x; }
        while(y != x){
            if(s > val[LT[y]]){ s = val[LT[y]]; i = LT[y]; }
            y -= lsb(y);
        }
        
        return i;
    }

    void _magic(int now,int x,int d,bool LR){
        vector<int> &T = LR ? LT : RT;
        if(T[now] != x){ if(val[T[now]] > d) T[now] = x; }
        else{
            int a = now,b = now;
            if(LR) a = now - lsb(now) + 1;
            else b = min(SZ(T)-1,now + lsb(now) - 1);
            if(a <= x-1){
                int s = query(a,x-1);
                if(val[s] < d) T[now] = s;
            }
            if(x+1 <= b){
                int s = query(x+1,b);
                if(val[s] < d) T[now] = s;
            }
        }
    }

    void update(int x,int d){
        val[x] = d;
        for(int now=x;now<=SZ(val);now+=lsb(now)) _magic(now,x,d,true);
        for(int now=x;now>0;now-=lsb(now)) _magic(now,x,d,false);
    }
};

#undef int

int main(){
    #define int long long
    int N; cin >> N;
    vector<pair<pair<int,int>,int>> V;
	for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        V.pb({{x,y - x + 1},i});
	}
	sort(V.begin(),V.end());
	int now = 1;
    for(int i=0;i<SZ(V);i++){
        V[i].ff.ff = now;
        if(i == 0 or V[i] != V[i-1]) now++;
    }
    vector<pair<int,int>> VV(N); for(int i=0;i<SZ(V);i++) VV[V[i].ss] = V[i].ff;
    BITRMQ B(N+10,LLONG_MAX);
    int big = 0;
    for(int i=0;i<N;i++){
        int previous = B.val[B.query(1,VV[i].ff)];
        if(previous == LLONG_MAX) previous = 0;
        else previous = -previous;
        int now = previous + VV[i].ss;
        big = max(big,now);
        B.update(VV[i].ff + 1, -now);
    }
    cout << big << endl;
    return 0;
}
