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
    pair<int,int> molecule[3]; for(int i=0;i<3;i++){ cin >> molecule[i].ff; molecule[i].ss = i; }
    sort(molecule, molecule+3); reverse(molecule, molecule+3);
    if(molecule[0].ff > molecule[1].ff + molecule[2].ff){cout << "Impossible" << endl;return 0;}
    if((molecule[1].ff + molecule[2].ff - molecule[0].ff)%2){ cout << "Impossible" << endl; return 0;  }
    int ans[3];
    ans[1] = (molecule[1].ff + molecule[2].ff - molecule[0].ff) / 2;
    ans[0] = molecule[1].ff - ans[1];
    ans[2] = molecule[2].ff - ans[1];
    int jedi[3];
    for(int i=0;i<3;i++){
        if(molecule[i].ss + molecule[(i+1)%3].ss == 1) jedi[0] = ans[i];
        else if(molecule[i].ss + molecule[(i+1)%3].ss == 3) jedi[1] = ans[i];
        else jedi[2] = ans[i];
    }
    for(int i=0;i<3;i++) cout << jedi[i] << " "; cout << endl;
    return 0;
}
