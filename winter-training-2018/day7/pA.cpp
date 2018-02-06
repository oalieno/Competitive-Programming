//#include<bits/stdc++.h>
#include <iostream>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define int long long

const int NUM = 70000;

int phi[NUM];

void BuildPhi(int N){
    for(int i = 1; i <= N; i++) phi[i] = i;
    for(int i = 1; i <= N; i++) for(int x = i * 2; x <= N; x += i) phi[x] -= phi[i];
}

#undef int

int main(){
    #define int long long
    BuildPhi(65535);
    int p;
    while(cin >> p) {
        cout << phi[p - 1] << endl;
    }
    return 0;
}
