#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int NUM = 21;

void LU(vector<vector<int>> &A, vector<vector<int>> &B){
    int Alen = SZ(A); int Awid = (1 << NUM) / Alen;
    int Blen = Alen << 1;
    B.resize(Blen); for(int i=0;i<Blen;i++) B[i].clear();
    for(int i=Alen-1;i>=0;i--) for(int j=(Awid>>1)-1;j>=0;j--) B[Alen-1-i].push_back(A[i][j]);
    for(int i=0;i<Alen;i++) for(int j=(Awid>>1);j<Awid;j++) B[(Blen>>1)+i].push_back(A[i][j]);
}

void LD(vector<vector<int>> &A, vector<vector<int>> &B){
    int Alen = SZ(A); int Awid = (1 << NUM) / Alen;
    int Blen = Alen << 1;
    B.resize(Blen); for(int i=0;i<Blen;i++) B[i].clear();
    for(int i=0;i<Alen;i++) for(int j=(Awid>>1);j<Awid;j++) B[i].push_back(A[i][j]);
    for(int i=Alen-1;i>=0;i--) for(int j=(Awid>>1)-1;j>=0;j--) B[(Blen>>1)+(Alen-1-i)].push_back(A[i][j]);
}

void RU(vector<vector<int>> &A, vector<vector<int>> &B){
    int Alen = SZ(A); int Awid = (1 << NUM) / Alen;
    int Blen = Alen << 1;
    B.resize(Blen); for(int i=0;i<Blen;i++) B[i].clear();
    for(int i=Alen-1;i>=0;i--) for(int j=Awid-1;j>=(Awid>>1);j--) B[Alen-1-i].push_back(A[i][j]);
    for(int i=0;i<Alen;i++) for(int j=0;j<(Awid>>1);j++) B[(Blen>>1)+i].push_back(A[i][j]);
}

void RD(vector<vector<int>> &A, vector<vector<int>> &B){
    int Alen = SZ(A); int Awid = (1 << NUM) / Alen;
    int Blen = Alen << 1;
    B.resize(Blen); for(int i=0;i<Blen;i++) B[i].clear();
    for(int i=0;i<Alen;i++) for(int j=0;j<(Awid>>1);j++) B[i].push_back(A[i][j]);
    for(int i=Alen-1;i>=0;i--) for(int j=Awid-1;j>=(Awid>>1);j--) B[(Blen>>1)+(Alen-1-i)].push_back(A[i][j]);
}

#undef int

int main(){
    freopen("E.IN", "r", stdin);
    vector<vector<int>> stripe[2];
    stripe[0].resize(1); for(int i=0;i<(1<<NUM);i++) stripe[0][0].push_back(i+1);
    int where = 0;
    for(int i=0;i<NUM;i++){
        string oper; cin >> oper;
        if(oper == "LU") LU(stripe[where], stripe[1-where]);
        if(oper == "LD") LD(stripe[where], stripe[1-where]);
        if(oper == "RU") RU(stripe[where], stripe[1-where]);
        if(oper == "RD") RD(stripe[where], stripe[1-where]);
        where = 1-where;
    }
    int jedi = 1024;
    for(int i=0;i<jedi;i++){
        cout << stripe[where][i][0] << endl;
    }
    return 0;
}
