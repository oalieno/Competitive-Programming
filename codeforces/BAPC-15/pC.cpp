#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define double int
#define int long long

struct VT{
    double x,y;
    VT(){}
    VT(double x, double y):x(x),y(y){}
    VT operator+(const VT &v) const { return VT(x + v.x, y + v.y); }
    VT operator-(const VT &v) const { return VT(x - v.x, y - v.y); }
    VT operator*(double c) const { return VT(x * c, y * c); }
    VT operator/(double c) const { return VT(x / c, y / c); }
    bool operator<(const VT &v) const { return (x < v.x) || (x == v.x && y < v.y); }
    double operator*(const VT &v) const { return x * v.x + y * v.y; }
    double operator^(const VT &v) const { return x * v.y - y * v.x; }
    double len(){ return sqrt(x * x + y * y); }
    double len2(){ return x * x + y * y; }
    VT U(){ return *this / len(); }
    VT T(){ return VT(-y, x); }
    VT rot(double a){ return VT(cos(a) * x - sin(a) * y, sin(a) * x + cos(a) * y); }
};

void ConvexHull(vector<VT> V, vector<VT> &C){
    sort(V.begin(),V.end());
    int m = 0;
    for(int i=0;i<SZ(V);i++){
        while(m > 1 && ((C[m-1] - C[m-2]) ^ (V[i] - C[m-2])) <= 0){ C.pop_back(); m--; }
        C.push_back(V[i]); m++;
    }
    int k = m;
    for(int i=SZ(V)-2;i>=0;i--){
        while(m > k && ((C[m-1] - C[m-2]) ^ (V[i] - C[m-2])) <= 0){ C.pop_back(); m--; }
        C.push_back(V[i]); m++;
    }
}

vector<VT> V,C;

double area(int a, int b, int c){
    VT A = V[a], B = V[b], C = V[c];
    return abs((B - A) ^ (C - A));
}

double TenarySearch(int a, int b, int m){
    int L = a, H = b; a %= m; b %= m;
    while(true){
        //cout << L << " " << H << endl;
        int M1 = (L * 2 + H) / 3, M2 = (L + H * 2) / 3;
        //cout << "M " << M1 << " " << M2 << endl;
        if(H - L < 3) return area(a,b,M2 % m);
        else if(area(a,b,M1 % m) > area(a,b,M2 % m)) H = M2;
        else L = M1;
    }
}

#undef int

int main(){
    #define int long long
    int T; cin >> T;
    while(T--){
        V.clear(); C.clear();
        int N; cin >> N;
        for(int i=0;i<N;i++){
            int x,y; cin >> x >> y;
            V.pb({x,y});
        }
        ConvexHull(V,C);
        cout << "convex:" << endl; for(auto i:C) cout << i.x << " " << i.y << endl;
        int ans = 0;
        for(int i=0;i<SZ(C)-1;i++) for(int j=i+1;j<SZ(C)-1;j++){
            cout << i << " " << j << " " << TenarySearch(i,j,SZ(C)) << " ";
            cout << i << " " << j << " " << TenarySearch(j,i+SZ(C),SZ(C)) << endl;
            ans = max(ans,TenarySearch(i,j,SZ(C)) + TenarySearch(j,i+SZ(C),SZ(C)));
        }
        if(ans % 2) cout << ans/2 << ".5" << endl;
        else cout << ans/2 << endl;
    }
    return 0;
}
