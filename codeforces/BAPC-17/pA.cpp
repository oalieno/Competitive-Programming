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

const double PI = acos(-1.0);

#undef int

int main(){
    #define int long long
    int N, M; cin >> N >> M;
    double R; cin >> R;
    double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    double ans = 0.0;
    double y = min(y1, y2);
    double r = R * y / M;
    ans += R * abs(y1 - y2) / M;
    double A = r * PI * abs(x1 - x2) / N;
    double B = 2 * r;
    ans += min(A, B);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
