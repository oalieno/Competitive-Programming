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
const int NUM = 1000100;

#define int long long

int ans[NUM*3];

#undef int

int main(){
    #define int long long
    IOS;
    int N;cin >> N;
    for(int i=1;i<=N;i++)ans[i] = i;
    for(int i=2;i<=N;i++){
        int start = ((N-1)/i)*i+1;
        for(int j=start+(i-2);j>=1+(i-2);j-=i){
            if(j == start+(i-2) && N%i != 0)ans[j+N%i] = ans[j];
            else ans[j+i] = ans[j];
            ans[j] = 0;
        }
    }
    int now = 1;
    while(!ans[now])now++;
    while(ans[now])cout << ans[now++] << " ";cout << endl;
    return 0;
}
