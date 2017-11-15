//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define int long long

struct ST{
	struct Node{
        int value, lazy, sz;
        Node *lc,*rc;
        Node():lc(NULL), rc(NULL), lazy(0), sz(0){}
        void pull(){
            value = lc->value + rc->value;
            sz = lc->sz + rc->sz;
        }
        void push(){
            if(!lazy) return;
            if(lc){ lc->lazy += lazy; lc->value += lazy * lc->sz; }
            if(rc){ rc->lazy += lazy; rc->value += lazy * rc->sz; }
            lazy = 0;
        }
    };

	vector<int> A;
    Node *root;

    void build(int N){
        root = _build(0, N-1);
    }

    Node* _build(int L,int R){
        Node *node = new Node();
        if(L == R){
            node->value = A[L];
            node->sz = 1;
            return node;
        }
        int mid = (L+R)>>1;
        node->lc = _build(L,mid);
        node->rc = _build(mid+1,R);
        node->pull();
        return node;
    }

    void modify(Node *node,int L,int R,int ql,int qr,int d){
        if(R < ql || qr < L) return;
        if(ql <= L && R <= qr){
            node->lazy += d;
            node->value += d * node->sz;
            return;
        }
        node->push();
        int mid = (L+R)>>1;
        modify(node->lc,L,mid,ql,qr,d);
        modify(node->rc,mid+1,R,ql,qr,d);
        node->pull();
    }

    int query(Node* node,int L,int R,int ql,int qr){
        if(R < ql || qr < L) return 0;
        if(ql <= L && R <= qr){ return node->value; }
        node->push();
        int mid = (L+R)>>1;
        return query(node->lc,L,mid,ql,qr) + query(node->rc,mid+1,R,ql,qr);
    }

    void delete_(Node* now){
        if(!now) return;
        delete_(now->lc);
        delete_(now->rc);
        delete now;
    }
};

#undef int

int main(){
    #define int long long
    int N, Q; cin >> N >> Q;
    ST st; for(int i=0;i<N;i++){ int x; scanf("%lld", &x); st.A.push_back(x); }
    st.build(N);
    for(int i=0;i<Q;i++){
        char oper; cin >> oper;
        if(oper == 'C'){
            int a, b, c; scanf("%lld%lld%lld", &a, &b, &c); a--; b--;
            st.modify(st.root, 0, N-1, a, b, c);
        }
        else{
            int a, b; scanf("%lld%lld", &a, &b); a--; b--;
            printf("%lld\n", st.query(st.root, 0, N-1, a, b));
        }
    }
    return 0;
}
