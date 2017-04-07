#include<bits/stdc++.h>

using namespace std;

#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
#define SZ(x) ((int)x.size())
#define pb push_back
#define first ff
#define second ss

#define NUM 1000100

#define int long long

int prefix[NUM];

#undef int

int main(){
    #define int long long
    int N = 0;
    string bits;
    while(cin >> bits){
        prefix[0] = (bits[0] == '1');for(int i=1;i<SZ(bits);i++)prefix[i] = prefix[i-1]+(bits[i] == '1');
        int Q;cin >> Q;
        N++;cout << "Case " << N << ":" << endl;
        for(int i=0;i<Q;i++){
            int x,y;cin >> x >> y;
            if(x > y)swap(x,y);
            if(prefix[y]-prefix[x-1] == 0 || prefix[y]-prefix[x-1] == (y-x+1))cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
