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
        string N;cin >> N;
        cout << "Case #" << ++C << ": ";
        int bound = 1,jedi;
        while(bound < SZ(N)-1 && N[bound-1] <= N[bound])bound++;
        if(SZ(N) == 1 || N[bound-1] <= N[bound]){ cout << N << endl;continue; }
        for(jedi=bound-1;jedi>0;jedi--)if(N[jedi] > N[jedi-1])break;
        N[jedi]--;
        for(int i=0;i<jedi;i++)cout << N[i];
        if(!(jedi == 0 && N[jedi] == '0'))cout << N[jedi];
        for(int i=jedi+1;i<SZ(N);i++)cout << 9;
        cout << endl;
    }
    return 0;
}

