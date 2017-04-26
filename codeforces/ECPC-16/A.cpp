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

#define int long long

#undef int

int main(){
    #define int long long
    FI("powers.in");
    IOS;
    int T;cin >> T;
    while(T--){
        int N;cin >> N;
        int SG = 0;
        for(int i=0;i<N;i++){
            int A,B;cin >> A >> B;
            if(A%2)SG ^= B%2;
            else{
                if(B%(A+1) == A)SG ^= 2;
                else SG ^= (B%(A+1))%2;
            }
        }
        if(SG)cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}
