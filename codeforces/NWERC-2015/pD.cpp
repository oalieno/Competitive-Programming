#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second


int main(){
#define int long long
    int n, r, p;
    cin >> n >> r >> p;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 2; i <= n; ++i) {
        int tmp = ceil(log(n) / log(i));
        ans = min(ans, tmp * (r + p * (i-1)));
    }
    cout << ans << endl;
    return 0;
}
