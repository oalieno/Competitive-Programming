#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
       
const double eps = 1e-7;

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
    bool operator==(const VT &v) const { return x == v.x && y == v.y;  }
    bool operator!=(const VT &v) const { return !(*this == v);  }
    double operator*(const VT &v) const { return x * v.x + y * v.y; }
    double operator^(const VT &v) const { return x * v.y - y * v.x; }
    double len(){ return sqrt(x * x + y * y); }
    double len2(){ return x * x + y * y; }
    VT U(){ return *this / len(); }
    VT T(){ return VT(-y, x); }
    VT rot(double a){ return VT(cos(a) * x - sin(a) * y, sin(a) * x + cos(a) * y); }
};

void ConvexHull(vector<pair<VT,int>> &_V, vector<pair<VT,int>> &C){
    vector<pair<VT,int>> V;
    V.push_back(_V[0]); for(int i=1;i<SZ(_V);i++) if(_V[i].ff != _V[i-1].ff) V.push_back(_V[i]);
    sort(V.begin(),V.end());
    int m = 0;
    for(int i=0;i<SZ(V);i++){
        while(m > 1 && ((C[m-1].ff - C[m-2].ff) ^ (V[i].ff - C[m-2].ff)) <= eps) m--;
        C.push_back(V[i]); m++;
    }
    cout << "debug: "; for(auto i:C) cout << i.ss << " "; cout << endl;
    int k = m;
    for(int i=SZ(V)-2;i>=0;i--){
        while(m > k && ((C[m-1].ff - C[m-2].ff) ^ (V[i].ff - C[m-2].ff)) <= eps) m--;
        C.push_back(V[i]); m++;
    }
}

#undef int

int main(){
    #define int long long
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<pair<VT,int>> V,C;
        for(int i=1;i<=N;i++){
            int x,y; cin >> x >> y;
            V.push_back({{(double)x,(double)y},i});
        }
        ConvexHull(V,C);
        for(auto i:C){
            cout << i.ss << " ";
        } cout << endl;
    }
    return 0;
}
