//#include<bits/stdc++.h>
#include <iostream>

using namespace std;

#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define SZ(x) (int)x.size()

#define int long long

const int NUM = 100100;

int factor[NUM];

/*
int inverse(int b, int p) {
    if(b == 0) return 1;
    return b == 1 ? 1 : (inverse(p % b, p) * (p - p / b) % p);
}
*/
int inverse(int a, int b) {
    int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

void init(int m) {
    factor[0] = 1; for(int i = 1; i < NUM; i++) factor[i] = factor[i - 1] * i % m;
}

int C(int n, int m, int k) {
    if(n < m) return 0;
    return factor[n] * inverse(factor[n - m], k) % k * inverse(factor[m], k) % k;
}

int mul(int x, int y, int m) {
    if(y == 0) return 0;
    int k = mul(x, y / 2, m);
    if(y % 2) return ((k + k) % m + x) % m;
    else return (k + k) % m;
}

int lucas(int n, int m, int k) {
    int ans = 1;
    int _n = n, _m = m;
    while(_n > 0) {
        int nn = _n % k, mm = _m % k;
        ans = ans * C(nn, mm, k) % k;
        _n /= k; _m /= k;
    }
    return ans;
}

int CRT(int k, int a[], int p[]) {
    int M = 1, ans = 0; for(int i = 0; i < k; i++) M *= p[i];
    for(int i = 0; i < k; i++) {
        int mi = M / p[i];
        ans = (ans + mul(a[i] * inverse(mi, p[i]), mi, M)) % M;
    }
    return ans;
}

#undef int

int main(){
    #define int long long
    IOS;
    int T; cin >> T;
    while(T--) {
        int n, m, k; cin >> n >> m >> k;
        int p[20]; for(int i = 0; i < k; i++) cin >> p[i];
        int jedi[20];
        for(int i = 0; i < k; i++) {
            init(p[i]);
            jedi[i] = lucas(n, m, p[i]);
        }
        cout << CRT(k, jedi, p) << endl;
    }
    return 0;
}
