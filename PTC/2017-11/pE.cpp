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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int sum = 0;
        int part[N]; for(int i=0;i<N;i++){ cin >> part[i]; sum += part[i]; }
        int cut = 0, diff = part[0] - (sum - part[0]), ans = LLONG_MAX;
        int a, b;
        for(int i=0;i<N;i++){
            while(diff < 0){
                cut = (cut + 1) % N;
                diff += part[cut] * 2;
            }
            if(abs(diff) < ans){
                ans = abs(diff);
                a = i;
                b = (cut + 1) % N;
            }
            if(abs(diff - part[cut] * 2) < ans){
                ans = abs(diff - part[cut] * 2);
                a = i;
                b = cut;
            }
            diff -= part[i] * 2;
        }
        int i = a;
        int anss[2] = {};
        while(true){
            if(i == b) break;
            anss[0] += part[i];
            i = (i + 1) % N;
        }
        anss[1] = sum - anss[0];
        sort(anss, anss+2);
        cout << anss[0] << " " << anss[1] << endl;
    }
    return 0;
}
