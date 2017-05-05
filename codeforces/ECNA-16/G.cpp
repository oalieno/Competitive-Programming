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

const int NUM = 55;
const int MOD = 1000000007;

const double pi = acos(-1.0);

#define int long long

int dp[NUM];
queue<int> hano[3];

int other(int x,int y){
    bool visit[3] = {};
    visit[x] = true;
    visit[y] = true;
    for(int i=0;i<3;i++)if(!visit[i])return i;
}

int Go(int height,int head,int tail){
    int base;for(int i=0;i<3;i++)if(SZ(hano[i]) && hano[i].front() == height){ base = i;break; }hano[base].pop();
    if(height == 1){
        if(base == head) return 1;
        else if(base == tail) return 0;
        else return -1;
    }
    if(base == head){
        int result = Go(height-1,head,other(head,tail));
        if(result == -1)return -1;
        //cout << height << " " << head << " " << tail << endl;
        //cout << "head " << result + dp[height-1] + 1 << endl;
        return result + dp[height-1] + 1;
    }
    else if(base == tail){
        int result = Go(height-1,other(head,tail),tail);
        if(result == -1)return -1;
        //cout << height << " " << head << " " << tail << endl;
        //cout << "tail " << result << endl;
        return result;
    }
    else return -1;
}

#undef int

int main(){
    #define int long long
    //IOS;
    dp[0] = 0;for(int i=1;i<NUM;i++)dp[i] = dp[i-1]*2+1;
    int H = 0;
    for(int i=0;i<3;i++){
        int N;cin >> N;H += N;
        for(int j=0;j<N;j++){ int x;cin >> x;hano[i].push(x); }
    }
    int ans = Go(H,0,2);
    if(ans == -1)cout << "No" << endl;
    else cout << ans << endl;
    return 0;
}
