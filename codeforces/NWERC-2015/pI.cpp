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

int dx[4] = {0,1,0,1};
int dy[4] = {0,0,1,1};

#undef int

int main(){
    #define int long long
    string S; cin >> S;
    int now = 1, x = 0, y = 0;
    for(int i=SZ(S)-1;i>=0;i--){
        x += now * dx[S[i] - '0'];
        y += now * dy[S[i] - '0'];
        now *= 2;
    }
    cout << SZ(S) << " " << x << " " << y << endl;
    return 0;
}
