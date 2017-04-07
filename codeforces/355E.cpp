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
const long long NUM = 1000000;

#define int long long

int A[NUM+1];

#undef int

int main(){
    #define int long long
    IOS;
    int N,K;cin >> N >> K;
    int small = INF,big = 0;
    for(int i=0;i<N;i++){
        int x;cin >> x;
        A[x]++;
        small = min(small,x);
        big = max(big,x);
    }
    if(small <= K+1){ cout << small << endl;return 0; }
    for(int i=2;i<=big;i++)A[i] += A[i-1];
    for(int d=big;d>=K+1;d--){
        int counter = 0;
        for(int i=1;i<=big/d;i++)counter += A[min(i*d+K,big)] - A[i*d-1];
        if(counter == N){ cout << d << endl;break; }
    }
    return 0;
}
