//#include<bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()

#define int long long

const int NUM = 100000;

bool prime[NUM];
vector<int> primelist;

void buildPrime(int N){
    for(int i = 2; i < N; i++) prime[i] = true;
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            primelist.push_back(i);
            for(int j = i * i; j < N; j += i) prime[j] = false;
        }
    }
}

bool isPrime(int n) {
    if(n < NUM) return prime[n];
    for(int i = 0; i < SZ(primelist); i++) {
        if(n % primelist[i] == 0) return false;
    }
    return true;
}

#undef int

int main(){
    #define int long long
    buildPrime(NUM);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        if(N == 4) cout << 2 << endl;
        else if(isPrime(N)) cout << N - 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
