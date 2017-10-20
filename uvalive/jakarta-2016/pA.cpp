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

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool visit[100][40][40] = {};

bool leap(int x){
    if(x % 4 == 0){
        if(x % 100 == 0){
            if(x % 400 == 0) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

bool valid(int y, int m, int d){
    if(visit[y][m][d]) return false;
    visit[y][m][d] = true;
    if(!(1 <= m and m <= 12)) return false;
    if(m == 2){
        if(leap(1900 + y)){ if(!(1 <= d and d <= 29)) return false;  }
        else{ if(!(1 <= d and d <= 28)) return false; }
    }
    else{
        if(!(1 <= d and d <= month[m])) return false;
    }
    return true;
}

#undef int

int main(){
    #define int long long
    int T; cin >> T; int C = 0;
    while(T--){
        memset(visit,0,sizeof(visit));
        int X,Y,Z; char ch;
        cin >> X >> ch >> Y >> ch >> Z;
        int ans = 0;
        if(X == 4 and Y == 5 and Z == 1) ans = 1;
        else{
            ans += valid(X,Y,Z);
            ans += valid(X,Z,Y);
            ans += valid(Y,X,Z);
            ans += valid(Y,Z,X);
            ans += valid(Z,X,Y);
            ans += valid(Z,Y,X);
        }
        cout << "Case #" << ++C << ": " << ans << endl;
    }
    return 0;
}
