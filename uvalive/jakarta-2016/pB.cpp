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

const int MAXCHAR = 26;
const char CHAR = 'a';

struct Trie{
	struct Node{
		int N;
		Node* child[MAXCHAR];
		Node():N(-1){ for(int i=0;i<MAXCHAR;i++) child[i] = NULL; }
	};

	Node* root;

	Trie(){ root = new Node; }
	~Trie(){ release(root); }

	void insert(string text, int id){
		Node* now = root;
		for(int i=0;i<SZ(text);i++){
			int c = text[i] - CHAR;
			if(now->child[c] == NULL) now->child[c] = new Node;
			now = now->child[c];
		}
		now->N = id;
	}

    int query(string &s, int pos){
        set<int> S;
        query(s,pos,root,S,true);
        return S.size();
    }

    void query(string &s, int pos, Node* now, set<int> &S, bool mode){
        if(pos == SZ(s)){
            S.insert(now->N);
            return;
        }
        if(mode){
            for(int i=0;i<26;i++){
                if(now->child[i] != NULL){
                    // insert
                    query(s,pos,now->child[i],S,false);
                    // modify
                    query(s,pos+1,now->child[i],S,false);
                }
            }
            // delete
            query(s,pos+1,now,S,false);
        }

        int ch = s[pos] - CHAR;
        if(now->child[ch]) query(s,pos+1,now->child[ch],S,mode);
    }

	void release(Node* now){
		for(int i=0;i<MAXCHAR;i++) if(now->child[i]) release(now->child[i]);
		delete now;
	}
};

#undef int

int main(){
    #define int long long
    int T; cin >> T; int C = 0;
    while(T--){
		int N; cin >> N;
        Trie T_T;
        string S[N]; for(int i=0;i<N;i++){
            cin >> S[i];
            T_T.insert(S[i],i);
        }
        int big = 0, index;
        for(int i=0;i<N;i++){
            int result = T_T.query(S[i],0);
            if(result > big){ big = result; index = i; }
        }
		cout << "Case #" << ++C << ": " << S[index] << endl;
    }
    return 0;
}
