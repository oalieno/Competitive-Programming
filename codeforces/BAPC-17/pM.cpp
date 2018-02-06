#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) ((int)x.size())

#define int long long

struct point {
    int x, y;
    bool operator<(const point &p) const {
        return x < p.x or (x == p.x and y < p.y);
    }
};

int LIS(vector<int> v) {
    vector<int> ans;
    for (auto& i : v) {
        auto it = upper_bound(ans.begin(), ans.end(), i);
        if (ans.size() == 0 || i >= ans.back())
            ans.push_back(i);
        else {
            *it = i;
        }
    }
    return ans.size();
}

#undef int

int main(){
    #define int long long
    int N; cin >> N;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int mx = x1 < x2 ? 1 : -1;
    int my = y1 < y2 ? 1 : -1;
    vector<point> P;
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        P.push_back({(x - x1) * mx, (y - y1) * my});
    }
    x2 = (x2 - x1) * mx;
    y2 = (y2 - y1) * my;
    x1 = y1 = 0;
    
    sort(P.begin(), P.end());

    vector<int> jedi;
    for(int i = 0; i < N; i++) {
        if(!(0 <= P[i].x and P[i].x <= x2 and 0 <= P[i].y and P[i].y <= y2)) continue;
        jedi.push_back(P[i].y);
    }

    cout << LIS(jedi) << endl;

    return 0;
}
