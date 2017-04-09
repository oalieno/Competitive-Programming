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

bool stop[NUM];

#undef int

int main(){
    #define int long long
    IOS;
    int T;cin >> T;
    int C = 0;
    while(T--){
        string pancake;cin >> pancake;
        int K;cin >> K;
        int now = 0,ans = 0;
        bool success = true;
        for(int i=0;i<SZ(pancake);i++)stop[i] = false;
        for(int i=0;i<SZ(pancake);i++){
            bool value = (pancake[i] == '+');
            if(stop[i])now--;
            if(!(value^(now%2))){
                if(i <= SZ(pancake)-K){
                    now++;ans++;
                    stop[i+K] = true;
                } else {
                    success = false;
                    break;
                }
            }
        }
        cout << "Case #" << ++C << ": ";
        if(success)cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

