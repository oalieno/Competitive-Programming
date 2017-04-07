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

const long long INFLL = 100000000000000000;
const int INF = 1500000000;
const int NUM = 1100;

#define int long long

#undef int

int main(){
    #define int long long
    IOS;
    int N,L,R,QL,QR;cin >> N >> L >> R >> QL >> QR;
    int W[N];for(int i=0;i<N;i++)cin >> W[i];
    int PL[N];PL[0] = W[0];for(int i=1;i<N;i++)PL[i] = PL[i-1]+W[i];
    int PR[N];PR[N-1] = W[N-1];for(int i=N-2;i>=0;i--)PR[i] = PR[i+1]+W[i];
    int ans = INFLL;
    for(int i=-1;i<N;i++){
        int left = (i == -1)?0:PL[i];
        int right = (i == N-1)?0:PR[i+1];
        int A = i+1,B = N-i-1,C = QL,D = QR;if(A < B){ swap(A,B);swap(C,D); }
        ans = min(ans,left*L+right*R+max(A-B-1,0LL)*C);
    }
    cout << ans << endl;
    return 0;
}
