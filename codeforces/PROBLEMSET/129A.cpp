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
    int N; cin >> N;
    int sum = 0, even = 0, odd = 0;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        sum += x;
        if(x % 2) odd++;
        else even++;
    }
    if(sum % 2) cout << odd << endl;
    else cout << even << endl;
    return 0;
}
