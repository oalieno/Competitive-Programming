#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define NUM 200100

#define int long long

struct node{
    int value, state;
    node *next;
    node(){}
    node(int value, int state):value(value),state(state),next(NULL){}
};

struct root{
    int size;
    node *next;
    root():size(0),next(NULL){}
};

#undef int

int main(){
    #define int long long
    int N, L, R; cin >> N >> L >> R;
    root balloon[NUM];
    for(int i=0;i<N;i++){
        int x, y; cin >> x >> y;
        balloon[x].size++;
        node *now = new node(y,balloon[y].size);
        now->next = balloon[x].next;
        balloon[x].next = now;
    }
    vector<int> ans; ans.pb(0);
    stack<pair<node*,int>> S; S.push({balloon[0].next, balloon[0].size});
    while(true){
        if(SZ(ans) == R) break;
        if(S.empty()) break;
        
        auto now = S.top(); S.pop();
        
        if(now.ff == NULL or now.ss == 0) continue;
        ans.pb(now.ff->value);
        
        int y = now.ff->value;
        pair<node*,int> item = {balloon[y].next,balloon[y].size - now.ff->state};
        
        now.ff = now.ff->next;
        now.ss--;
        S.push(now);
        S.push(item);
    }
    for(int i=L;i<R;i++) cout << ans[i % SZ(ans)] << " "; cout << endl;
	return 0;
}
