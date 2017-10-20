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
    int A[N][3]; for(int i=0;i<3;i++) for(int j=0;j<N;j++) cin >> A[j][i];
    map<int,int> M;
    int now = N, ans = 0;
    for(int i=0;i<N;i++){
        int jedi = 0;
        for(int j=0;j<3;j++){
            M[A[i][j]]++;
            if(M[A[i][j]] == 1) now--;
            if(M[A[i][j]] == 3) jedi++;
        }
        ans += jedi * now;
    }
    cout << ans << endl;
    return 0;
}
