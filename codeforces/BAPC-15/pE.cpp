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

struct BITRMQ{
    vector<int> val,LT,RT;
    
    BITRMQ(){}
    BITRMQ(int n,int v):val(n,v){
        LT.resize(n); RT.resize(n);
        for(int i=0;i<n;i++) LT[i] = RT[i] = i;
    }

    inline int lsb(int x){ return x & -x; }

    int query(int a,int b){
        if(a >= SZ(LT) or b >= SZ(LT) or a < 1 or b < 1) while(1);
        //cout << "query: " <<  a << " " << b << endl;
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
        //cout << "update: " << x << " " << d << endl;
        val[x] = d;
        for(int now=x;now<=SZ(val);now+=lsb(now)) _magic(now,x,d,true);
        for(int now=x;now>0;now-=lsb(now)) _magic(now,x,d,false);
    }
};

struct engineer{
    int x,y,z;
    bool operator<(const engineer &en){ return x < en.x;  }
};

#undef int

int main(){
    #define int long long
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        engineer E[N]; for(int i=0;i<N;i++) cin >> E[i].x >> E[i].y >> E[i].z;
        sort(E,E+N);
        BITRMQ B(N+1,LLONG_MAX);
        int ans = N;
        for(int i=0;i<N;i++){
            //cout << i << endl;
            int index = B.query(1,E[i].y);
            if(B.val[index] < E[i].z) ans--;
            B.update(E[i].y,E[i].z);
        }
        cout << ans << endl;
    }
    return 0;
}
