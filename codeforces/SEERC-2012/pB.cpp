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

struct BIT{
    vector<int> val;

	BIT(int N){ val.resize(N+10, 0); }
    
    inline int lsb(int x){ return x & -x; }
    
    int sum(int x){
        int s = 0;
        while(x > 0){
            s += val[x];
            x -= lsb(x);
        }
        return s;
    }

    void update(int x,int d){
        while(x <= SZ(val)){
            val[x] += d;
            x += lsb(x);
        }
    }

    int query(int a,int b){
        if(a > b) swap(a,b);
        return sum(b)-sum(a-1);
    }
};

#undef int

int main(){
    #define int long long
    freopen("B.IN", "r", stdin);
    int N; cin >> N; N *= 2;
    int A[N]; for(int i=0;i<N;i++) cin >> A[i];
    int appear[N]; fill(appear, appear + N, -1);
    int ans = 0;
	BIT bit(N); for(int i=0;i<N;i++) bit.update(i+1, 1);
    for(int i=0;i<N;i++){
        if(appear[A[i]] != -1){
            ans += bit.query(appear[A[i]]+1, i+1) - 2;
            bit.update(appear[A[i]]+1, -1);
            bit.update(i+1, -1);
        }
        else appear[A[i]] = i;
    }
    cout << ans << endl;
    return 0;
}
