/*
    Author: OAlienO
    Country: Taiwan
    School: NCTU
*/
#include<bits/stdc++.h>

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define FI(x) freopen(x,"r",stdin)
#define SZ(x) ((int)((x).size()))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

using namespace std;

const int INF = 1500000000;
const int NUM = 100100;

#define int long long

#undef int

int main(){
    #define int long long
    IOS;
    int N;cin >> N;
    int F[NUM];for(int i=1;i<=N;i++)cin >> F[i];

    bool visit[NUM] = {};for(int i=1;i<=N;i++){ visit[F[i]] = true; }

    int G[NUM],H[NUM],M = 0;

    for(int i=1;i<=N;i++)if(visit[i]){ M++;G[i] = M;H[M] = i; }
    for(int i=1;i<=N;i++)if(!visit[i]){ G[i] = G[F[i]]; }

    bool success = true;
    for(int i=1;i<=N;i++)if(H[G[i]] != F[i]){ success = false;break; }
    for(int i=1;i<=M;i++)if(G[H[i]] != i){ success = false;break; }
    if(!success)cout << -1 << endl;
    else{
        cout << M << endl;
        for(int i=1;i<=N;i++)cout << G[i] << " ";cout << endl;
        for(int i=1;i<=M;i++)cout << H[i] << " ";cout << endl;
    }
    return 0;
}
