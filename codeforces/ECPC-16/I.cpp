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

const double eps = 1e-7;

#define int long long

inline int getint(){
	int _x = 0,_tmp = 1; char _tc = getchar();    
	while( (_tc < '0'|| _tc > '9') && _tc != '-' ) _tc = getchar();
	if( _tc == '-' ) _tc = getchar() , _tmp = -1;
	while(_tc >= '0'&& _tc <= '9') _x *= 10,_x += (_tc-'0'),_tc = getchar();
	return _x * _tmp;
}

struct circle{
    int x,y,r;
};

inline int power(int x){ return x*x; }

#undef int

int main(){
    #define int long long
    //IOS;
    FI("walk.in");
    int T = getint();//cin >> T;
    while(T--){
        int N = getint(),M = getint();//cin >> N >> M;
		vector<pair<double,int>> segment;
		for(int i=0;i<N;i++){
			int x = getint(),y = getint(),r = getint();
			//cin >> x >> y >> r;
            if(r > M || abs(y) > M - r) continue;
			double delta = sqrt(power(M-r)-power(y));
			segment.pb({x-delta,-r});
			segment.pb({x+delta,r});
		}
        sort(segment.begin(),segment.end());
		int ans = 0,now = 0;
		for(auto i:segment){
			now += i.ss;
			ans = max(ans,-now);
		}
        cout << ans << endl;
    }
    return 0;
}
