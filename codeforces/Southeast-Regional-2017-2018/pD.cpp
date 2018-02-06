#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

//#define int long long

const int NUM = 2010;
const int BIG = 1000000000;

set<pair<int,int>> snake[NUM]; // value, index
int ans[NUM][NUM];

//#undef int

int main(){
    //#define int long long
    int N, K; cin >> N >> K;
    char hay[NUM][NUM]; for(int i=0;i<N;i++) scanf("%s", hay[i]);
    for(int i=N-1;i>=0;i--){
        set<pair<int,int>> hand;
        for(int j=N-1;j>=0;j--){
            if(hay[i][j] == '#') ans[i][j] = BIG;
            else if(i == N-1 and j == N-1) ans[i][j] = 0;
            else if(i == N-1 and (N-1)-j <= K) ans[i][j] = 1;
            else if(j == N-1 and (N-1)-i <= K) ans[i][j] = 1;
            else{
                int A = BIG, B = BIG;
                if(SZ(hand) != 0) A = hand.begin()->first;
                if(SZ(snake[j]) != 0) B = snake[j].begin()->first;
                ans[i][j] = min(A, B) + 1;
            }
            if(SZ(hand) == K) hand.erase({ans[i][j+K], j+K});
            hand.insert({ans[i][j], j});
            if(SZ(snake[j]) == K) snake[j].erase({ans[i+K][j], i+K});
            snake[j].insert({ans[i][j], i});
        }
    }
    if(ans[0][0] >= BIG) printf("-1\n");
    else printf("%d\n", ans[0][0]);
    return 0;
}
