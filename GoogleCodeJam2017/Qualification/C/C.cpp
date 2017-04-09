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

const int INF = 1500000000;
const int NUM = 1010;

#define int long long

#undef int

int main(){
    #define int long long
    IOS;
    int T;cin >> T;
    int C = 0;
    while(T--){
        int N,K;cin >> N >> K;
        cout << "Case #" << ++C << ": ";
        priority_queue<pair<int,int>> pq; // value count
        pq.push(mp(N,1));
        while(true){
            pair<int,int> now = pq.top();pq.pop();
            while(!pq.empty() && pq.top().ff == now.ff){ now.ss += pq.top().ss;pq.pop(); }
            int L = (now.ff-1)/2,R = (now.ff-1)/2+(now.ff-1)%2;
            K -= now.ss;if(K <= 0){ cout << R << " " << L << endl;break; }
            if(L == R)pq.push(mp(L,now.ss << 1));
            else{ pq.push(mp(L,now.ss));pq.push(mp(R,now.ss)); }
        }
    }
    return 0;
}

