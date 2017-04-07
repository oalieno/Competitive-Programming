#include<bits/stdc++.h>

using namespace std;

#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
#define SZ(x) ((int)x.size())
#define pb push_back
#define first ff
#define second ss

#define NUM 1000100

#define int long long

#undef int

int main(){
    #define int long long
    int N;
    while(cin >> N){
        if(!N)break;
        int sqr = sqrt(N);
        if(sqr*sqr == N)cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}

