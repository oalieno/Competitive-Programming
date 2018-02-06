#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define int long long

#undef int

int main(){
    #define int long long
    int c, v1, v2;
    while(cin >> c){
        if(c == 0) break;
        cin >> v1 >> v2;
        if(v1 == v2) cout << "false" << endl;
        else{
            int p = abs(v1 - v2) * 2;
            int q = c * v1;
            while(q < 0) q = q + c * p;
            while(q >= c * p) q = q - c * p;
            int g = __gcd(abs(q), abs(p));
            cout << q / g;
            if(p / g != 1) cout << "/" << p / g;
            cout << endl;
        }
    }
    return 0;
}
