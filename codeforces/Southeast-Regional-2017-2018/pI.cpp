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

bool check(int N, int a, int b){
    if(N % (a + b) == 0) return true;
    else if(N % (a + b) == a) return true;
    else return false;
}

#undef int

int main(){
    #define int long long
    int N; cin >> N;
    int a = 1, b = 1;
    while(a + b <= N){
        a++;
        if(check(N, a, b)) cout << a << " " << b << endl;
        b++;
        if(check(N, a, b)) cout << a << " " << b << endl;
    }
    return 0;
}
