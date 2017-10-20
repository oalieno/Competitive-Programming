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
    int A[N];for(int i=0;i<N;i++)cin >> A[i];
    for(int i=0;i<N-1;i++)A[i] = abs(A[i]-A[i+1]);
    int previous = 0,ans = 0;
    for(int i=0;i<N-1;i++){
        int now = A[i];if(i%2)now = -now;
        if(previous > 0)previous += now;
        else previous = now;
        ans = max(ans,previous);
    }
    previous = 0;
    for(int i=1;i<N-1;i++){
        int now = A[i];if(i%2 == 0)now = -now;
        if(previous > 0)previous += now;
        else previous = now;
        ans = max(ans,previous);
    }
    cout << ans << endl;
    return 0;
}
